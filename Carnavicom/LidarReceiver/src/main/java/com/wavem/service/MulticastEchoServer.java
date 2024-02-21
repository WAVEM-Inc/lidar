package com.wavem.service;

import java.io.ByteArrayInputStream;
import java.io.IOException;
import java.net.DatagramPacket;
import java.net.InetAddress;
import java.net.MulticastSocket;
import java.time.LocalDateTime;
import java.time.format.DateTimeFormatter;
import java.util.ArrayList;
import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Value;
import org.springframework.boot.CommandLineRunner;
import org.springframework.context.ApplicationEvent;
import org.springframework.context.ApplicationListener;
import org.springframework.context.event.ContextClosedEvent;
import org.springframework.stereotype.Component;

import com.wavem.persistence.DistanceDataMapper;
import com.wavem.vo.DistanceDataVO;

@Component
//public class MulticastEchoServer implements CommandLineRunner, ApplicationListener<ContextClosedEvent> {
public class MulticastEchoServer extends Thread  {
    protected MulticastSocket socket = null;
    protected byte[] buf = new byte[1024];
    protected InetAddress group = null;
    private int DECTECION_COUNT = 480;
    private int HEADER_SIZE = 7;
    private byte [] lidar_head = {(byte)0xFA, 0x03, (byte)0xD0, (byte)0xDD };
    private int SLEEPTIME = 500;
    
    @Value("${service.sleep}")
    private Integer sleeptime;
    
    @Autowired
	private DistanceDataService distanceDataService;
	
    @SuppressWarnings("deprecation")
	public MulticastEchoServer() throws IOException {
        socket = new MulticastSocket(5000);
        
        socket.setReceiveBufferSize(1024);
        
        socket.setReuseAddress(true);
        group = InetAddress.getByName("224.0.0.5");    	
        socket.joinGroup(group);
    }

    public void close() throws IOException {
    	if ( socket != null && !socket.isClosed()) {
	    	socket.leaveGroup(group);
	        socket.close();
    	}
    }
    
    @SuppressWarnings("deprecation")
    @Override
	public void run() {
    	System.out.println("RUN");
    	printLogo("Lidar Receiver", "v1.0.0");
    	
    	boolean bRun = true;
    	long inserttime = 0;
    	
        try {
           
        	if ( sleeptime == null )
        		sleeptime = SLEEPTIME;
        		
            while (!Thread.currentThread().isInterrupted()) {
				
            	DatagramPacket packet = new DatagramPacket(buf, buf.length);
            	
                socket.receive(packet);
                /*InetAddress address = packet.getAddress();
                int port = packet.getPort();
                DatagramPacket recvPacket = new DatagramPacket(buf, buf.length, address, port);
                  */  
                
                String received = new String(packet.getData(), 0, packet.getLength());
                
                if (received.contains("start")) {
                	bRun=true;
                }else if (received.contains("stop")) {
                	bRun=false;
                }else if (received.contains("end")) {
                  break;
                }
                
                if ( bRun == false)
                	continue;
                
                List<DistanceDataVO> distData = getData(packet.getData(), packet.getLength(),lidar_head);
                if ( distData == null || distData.size() == 0)
                	continue;
                                   
                // 인서트 주기을 조정
                if ( inserttime == 0 || sleeptime < (System.currentTimeMillis()-inserttime)) {
                	
                	distanceDataService.insertDistanceData(distData);
                	inserttime = System.currentTimeMillis();
                	System.out.println("*****************************************************");
    				System.out.println("insert DistanceData --> [" + distData.get(0).getDetectionTime()+"]");
    				System.out.println("*****************************************************\n");
                }
            //    socket.send(packet);
              //  Thread.sleep(1);
            }
            this.close();
        }catch (IOException e) {
            e.printStackTrace();
			/*} catch (InterruptedException e) {
				e.printStackTrace();*/
        }
    }
    
    
    private List<DistanceDataVO> getData(byte [] databuf,int read_len,byte [] lidar_head ){
    	
    	int lp = 0;
    	float dist_dot = 0;
    	float [] range_data = new float [1024];  
    	
    	ByteArrayInputStream bis = new ByteArrayInputStream(databuf);
    	List<DistanceDataVO> distanceDataList = new ArrayList<DistanceDataVO>();
    	
    	//System.out.println("\n");
		if (read_len < 0) {
			System.out.println("reading datagram message");
			return null;
		}

		Integer  srcPos = null;
		
		try {
		
			LocalDateTime detectionTime = LocalDateTime.now(); //1. 시간
			String formatedNow = detectionTime.format(DateTimeFormatter.ofPattern("yyyyMMddHHmmssSSS"));
			//System.out.println(formatedNow); 
			
			if((srcPos = memmem(databuf, read_len, lidar_head, lidar_head.length))!=null)
			{
				byte [] destbuf = new byte [1024];
				
				int bodyLength = read_len-srcPos.intValue();
				System.arraycopy(databuf, srcPos.intValue(), destbuf, 0, bodyLength);			
				//memcpy(databuf,memmem(databuf,databuf.length,lidar_head,lidar_head.length),read_len);
				for(lp=0;lp<DECTECION_COUNT;lp++)	
				{
					dist_dot=destbuf[lp*2+HEADER_SIZE] + (float)databuf[lp*2+HEADER_SIZE+1]/100;
					range_data[lp]=dist_dot;  //2. 좌표
					//printf("1=%02X,2=%02X, %f\n,",databuf[lp*2+7],databuf[lp*2+8],dist_dot);
				}				
				
				String channelX = String.format("%02x", destbuf[4]).toUpperCase();// 3. 채널
				
				int detectionValue = destbuf[bodyLength]; // 4. Detection Value
				
				for(lp=0;lp<DECTECION_COUNT;lp++)
				{
					//System.out.println(String.format("[ %03d ]%f,",lp+1,range_data[lp]));
					
					DistanceDataVO distanceData = new DistanceDataVO(formatedNow
																,lp   //range index
																,range_data[lp]
																,channelX
																,detectionValue);					
					distanceDataList.add(distanceData);					
				}
				System.out.println("["+formatedNow + "]receive DistanceData count : " + distanceDataList.size());
				
				//System.out.println("\n");
			}
		}catch(Exception e) {
			e.printStackTrace();
			return null;
		}
		
		return distanceDataList;
    }
    
	/* 
	 * c memem 함수 대응
	 * 일치하는 값의 인덱스를 리턴한다.
	 *  
	 * */
    Integer memmem(byte [] haystack, int haystacklen, byte [] needle, int needlelen) {
    	
    	int index = new String(haystack).indexOf(new String(needle)); 
    	//System.out.println(index);
    	
    	if ( index < 0 )
    		return null;
    	
    	return index;
    }
	/*
		@Override
		public void run(String... args) throws Exception {
			this.run();
		}
	
		@Override
		public void onApplicationEvent(ContextClosedEvent event) {
			try {
				this.close();
			} catch (IOException e) {
				e.printStackTrace();
			}
			
		}	*/
    
    
    public void printLogo(String applicationName, String version) {
    		System.out.println("");	        
    		System.out.println(" _      _     _              _____               _");
    		System.out.println("| |    (_)   | |            |  __ \\             (_)");
    		System.out.println("| |     _  __| | __ _ _ __  | |__) |___  ___ ___ ___   _____ _ __");
    		System.out.println("| |    | |/ _` |/ _` | '__| |  _  // _ \\/ __/ _ \\ \\ \\ / / _ \\ '__|");
    		System.out.println("| |____| | (_| | (_| | |    | | \\ \\  __/ (_|  __/ |\\ V /  __/ |");   
    		System.out.println("|______|_|\\__,_|\\__,_|_|    |_|  \\_\\___|\\___\\___|_| \\_/ \\___|_|");   
    		System.out.println(" for Canavicom Lidar Test    ");
	        System.out.println(" ⓒ WAVEM ");
	        System.out.println(" " + applicationName + "(" + version + ")");

		}

    
}
