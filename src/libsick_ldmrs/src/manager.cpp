//
// manager.cpp
//

#include "manager.hpp"
#include "tools/errorhandler.hpp"
#include "tools/toolbox.hpp"

// The devices
#include "devices/LD_MRS.hpp"

// The applications
#include "application/LdmrsApp.hpp"
#include "application/LdmrsSectorChangeApp.hpp"
#include "application/LdmrsFieldApp.hpp"
#include "application/LdmrsNtpTimeApp.hpp"
#include "application/LdmrsScanpointCoordinateApp.hpp"

using namespace application;
using namespace devices;

// ****************************************************************************
//     The Manager of the system
// ****************************************************************************
Manager::Manager()
	: m_beVerbose(false)
	, m_nextSourceId(0)
{
	infoMessage("Manager: Starting constructor.", m_beVerbose);
	
	// Max. size of the device-data-buffer
	m_sourceBuffer.setLimit(5000000);
	
	infoMessage("Manager: Constructor done.", m_beVerbose);
}

//
// Destructor.
// Close all applications and devices.
//
Manager::~Manager()
{
	infoMessage("~Manager(): Destructor called.", m_beVerbose);
	
	stopAllDevices();

	// Delete all applications
	while (m_appList.size() > 0)
	{
		BasicApplication* a;
		a = m_appList.back();
		delete a;
		m_appList.pop_back();
	}
	
	// Delete all devices
	while (m_deviceList.size() > 0)
	{
		BasicDevice* p;
		p = m_deviceList.back();
		delete p;
		m_deviceList.pop_back();
	}

	infoMessage("~Manager(): Destructor is done.", m_beVerbose);
}


//
// Provides the next unique ID. Such an ID is set for all devices and all
// applications, to identify data generated by them.
//
UINT16 Manager::getNextSourceId()
{
	UINT16 sourceId = m_nextSourceId;
	m_nextSourceId++;
	
	if (m_nextSourceId == 0x0000)
	{
		dieWithError("Manager::getNextSourceId(): We are out of source IDs - exiting.");
	}
	return sourceId;
}


//
// Add a new device at runtime.
//
// It would be nice to add an ID-handling, to make the IDs safely unique!
//
bool Manager::addAndRunDevice(Sourcetype deviceType, std::string deviceName, UINT16 wantedId)
{
	BasicDevice* device;
	
	// Device erzeugen
	switch (deviceType)
	{
		case Sourcetype_LDMRS:
			device = new LDMRS(this);
			break;
		default:
			printError("Manager::addAndRunDevice: Unknown device (Type=" + toString((UINT16)deviceType) +
						" , Name=" + deviceName + "). Ignoring this call!");
			return false;
	}
	return addAndRunDevice(device, deviceName, wantedId);
}

//
// Add a external created device object.
//
// Note that device needs to be on the heap and will automatically be deleted when the manager is destructed.
//
bool Manager::addAndRunDevice(devices::BasicDevice* device, std::string deviceName, UINT16 wantedId)
{
	bool beVerboseHere = true | m_beVerbose;
	
	// ID erzeugen
	UINT16 id = wantedId;
	if (id == 0xFFFF)
	{
		id = getNextSourceId();
	}
	device->setSourceId(id);
	
	// Namen setzen
	device->setDeviceName(deviceName);

	// Device speichern
	m_deviceList.push_back(device);
	
	std::string text = "Manager::addAndRunDevice: Created Device of type " +
						toString(device->getDevicetype()) +
						" with Name " + deviceName +
						" under the ID " +
						toString(device->getSourceId()) + ". Now initializing the device.";
	printInfoMessage(text, beVerboseHere);
	
	// Device initialisieren
	bool result = device->init();
	if (result == true)
	{
		printInfoMessage("Manager::addAndRunDevice: Device is initialized.", beVerboseHere);
	}
	else
	{
		printError("Manager::addAndRunDevice: Failed to initialize the device, aborting.");
		return false;
	}
	
	// Device starten
	result = device->run();
	if (result == true)
	{
		printInfoMessage("Manager::addAndRunDevice: Device is running.", beVerboseHere);
	}
	else
	{
		printError("Manager::addAndRunDevice: Failed to run device, aborting.");
		return false;
	}
	
	if (m_sourceThread.isRunning() == false)
	{
		printInfoMessage("Manager::addAndRunDevice: Added device, now running source thread.", beVerboseHere);
		m_sourceThread.run(this);
	}

	printInfoMessage("Manager::addAndRunDevice: All done, leaving.", beVerboseHere);
	return result;
}

//
// Eine neue Applikation dynamisch, d.h. zur Laufzeit, hinzufuegen.
//
// It would be nice to add an ID-handling, to make the IDs safely unique!
//
bool Manager::addApplication(Sourcetype appType, std::string appName, UINT16 wantedId)
{
	BasicApplication* app;
	
	// Device erzeugen
	switch (appType)
	{
		case Sourcetype_MrsApp:
			app = new LdmrsApp(this);
			break;
		case Sourcetype_MrsFieldApp:
			app = new LdmrsFieldApp(this);
			break;
		case Sourcetype_MrsChangeApp:
			app = new LdmrsSectorChangeApp(this);
			break;
		case Sourcetype_MrsNtpTimeApp:
			app = new LdmrsNtpTimeApp(this);
			break;
		case Sourcetype_MrsScanpointCoordinateApp:
			app = new LdmrsScanpointCoordinateApp(this);
			break;
		default:
			printError("Manager::addApplication: Unknown application (Type=" + toString((UINT16)appType) +
						" , Name=" + appName + "). Ignoring this call!");
			return false;
	}
	
	// Namen setzen
	app->setApplicationName(appName);

	return addApplication(app, wantedId);
}

bool Manager::addApplication(BasicApplication *app, UINT16 wantedId)
{
	// ID erzeugen
	UINT16 id = wantedId;
	if (id == 0xFFFF)
	{
		id = getNextSourceId();
	}
	app->setSourceId(id);

	// Device speichern
	m_appList.push_back(app);
	
	std::string text = "Manager::addApplication: Created application " +
						toString(app->getApplicationType()) +
						" with Name " + app->getApplicationName() +
						" under the ID " +
						toString(app->getSourceId()) + ". Now running the device.";
	printInfoMessage(text, m_beVerbose);
	
	return true;
}



/**
 * Kommando: Los...
 */
bool Manager::runAllDevices()
{
	std::string text;

	for (UINT32 i=0; i<m_deviceList.size(); i++)
	{
		BasicDevice* device;
		device = m_deviceList.at(i);
		
		text = "Manager: Running device with ID " + toString(device->getSourceId()) + ".";
		infoMessage(text, m_beVerbose);
	
		device->run();
	}

	// Start the data distribution
	if (m_sourceThread.isRunning() == false)
	{
		m_sourceThread.run(this);
	}
	
	return true;
}


//
// Stop!
//
void Manager::stopAllDevices()
{
	std::string text;
	
	for (UINT32 i=0; i<m_deviceList.size(); i++)
	{
		BasicDevice* device;
		device = m_deviceList.at(i);
		
		text = "Manager::stopAllDevices: Stopping device with ID " + toString(device->getSourceId()) + ".";
		infoMessage(text, m_beVerbose);
		
		device->stop();

		infoMessage("Manager::stopAllDevices: Device stopped.", m_beVerbose);
	}
}

//
// Receiver for data from the devices. The data is forwarded to the applications.
//
// Note: In the buffer, only the data pointers are stored!
//
void Manager::setDeviceData(BasicData* data)
{
	// Hier in einen Puffer schreiben!
	ScopedLock lock(&m_sourceBufferMutex);	// Wg. der folgenden Textmeldung. Der Puffer selber ist sicher...
	bool result = m_sourceBuffer.pushData(data);
	if (result == true)
	{
		// Datum wurde hinzugefuegt
		if (m_beVerbose == true)
		{
			std::string text;
			text = "Manager::setDeviceData(): Added data. Device data buffer size is now " +
				toString(m_sourceBuffer.getBufferSize()) + " Elements (" + toString(m_sourceBuffer.getUsedBytes()) + " bytes).";
			infoMessage(text, m_beVerbose);
		}
	}
	else
	{
		// Datum konnte nicht hinzugefuegt werden
		std::string text;
		text = "Manager::setDeviceData(): Failed to add data. Device data buffer size is currently " +
			   toString(m_sourceBuffer.getBufferSize()) + " Elements (" + toString(m_sourceBuffer.getUsedBytes()) +
			   " bytes), and the buffer refused to add " + toString(data->getUsedMemory()) + " bytes.";
		printWarning(text);
		
		// Datum loeschen!
		delete data;
		return;
	}
}

/**
 * Thread-Funktion fuer das Verteilen der Daten.
 * 
 * Aus diesem Kontext heraus werden die Applikationen aufgerufen!
 * 
 * Pro Aufruf wird nur 1 Datum verteilt. Grund ist es, auch mit einem Prozessor den anderen
 * Threads ggf. genug Rechenleistung zu ueberlassen. Hier koennten pro Aufruf aber auch mehr
 * Daten verteilt werden, etwa wenn CAN-Nachrichten mit hoher Frequenz eintreffen.
 * 
 * Die Daten werden aktuell nicht an eine globale "Drain" weitergeleitet.
 */
void Manager::sourceThreadFunction(bool& endThread, UINT16& waitTimeMs)
{
	infoMessage("Manager: sourceThreadFunction() called.", m_beVerbose);
	
	//
	// Pruefe, ob Daten verteilt werden muessen
	//
	// Hole den Zeiger auf die naechsten Daten im Puffer, falls welche da sind.
	// Zugriffsschutz hier nicht erforderlich, da der Buffer selber Thread-Safe ist.
	BasicData* data = NULL;
	data = m_sourceBuffer.popData();
	
	// Verteile die Daten, falls welche da waren
	if (data != NULL)
	{
		// DEBUG
		if (m_beVerbose == true)
		{
			std::string text;
			text = "Manager::sourceThreadFunction(): Popped a dataset of type " + toString(data->getDatatype()) + 
					", created from Source-ID " + toString(data->getSourceId()) + ".";
			infoMessage(text, m_beVerbose);
		}
		

		// Einfach an jede Applikation verteilen
		for (UINT32 i=0; i<m_appList.size(); i++)
		{
			BasicApplication* a;
			a = m_appList.at(i);
			a->setData(*data);
		}
		
		// Datensatz wird nicht mehr benoetigt, loeschen
		delete data;
		data = NULL;
	}

	//
	// Naechsten Aufruf vorbereiten
	//
	endThread = false;
	if (m_sourceBuffer.getBufferSize() > 0)
	{
		// Es sind bereits jetzt neue Daten da, also nur kurz unterbrechen
		waitTimeMs = 0;
//		infoMessage("Source fill level: " + toString(m_sourceBuffer.getBufferSize()) + ".", true);
	}
	else
	{
		// Es sind aktuell keine weiteren Daten da, also ruhig etwas laenger schlafen
		waitTimeMs = 2;
	}
}

//
// Get a pointer to the device identified by its ID.
// Returns NULL if no such device could be found.
//
devices::BasicDevice* Manager::getDeviceById(UINT32 id)
{
	devices::BasicDevice* device = NULL;

	for (DeviceList::iterator iter = m_deviceList.begin(); iter != m_deviceList.end(); ++iter)
	{
		if ((*iter)->getSourceId() == id)
		{
			device = *iter;
			break;
		}
	}

	return device;
}

//
// Get a pointer to the first device of the given type.
// Returns NULL if no such device could be found.
//
devices::BasicDevice* Manager::getFirstDeviceByType(Sourcetype type)
{
	devices::BasicDevice* device = NULL;

	for (DeviceList::iterator iter = m_deviceList.begin(); iter != m_deviceList.end(); ++iter)
	{
		if ((*iter)->getDevicetype() == type)
		{
			device = *iter;
			break;
		}
	}

	return device;
}

