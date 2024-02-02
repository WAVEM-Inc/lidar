#include "sick_scan/sick_scan_base.h" /* Base definitions included in all header files, added by add_sick_scan_base_header.py. Do not edit this line. */
// Generated by gencpp from file sick_scan/SickLocSetOdometryPortSrvRequest.msg
// DO NOT EDIT!


#ifndef SICK_SCAN_MESSAGE_SICKLOCSETODOMETRYPORTSRVREQUEST_H
#define SICK_SCAN_MESSAGE_SICKLOCSETODOMETRYPORTSRVREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace sick_scan
{
template <class ContainerAllocator>
struct SickLocSetOdometryPortSrvRequest_
{
  typedef SickLocSetOdometryPortSrvRequest_<ContainerAllocator> Type;

  SickLocSetOdometryPortSrvRequest_()
    : port(0)  {
    }
  SickLocSetOdometryPortSrvRequest_(const ContainerAllocator& _alloc)
    : port(0)  {
  (void)_alloc;
    }



   typedef uint32_t _port_type;
  _port_type port;





  typedef std::shared_ptr< ::sick_scan::SickLocSetOdometryPortSrvRequest_<ContainerAllocator> > Ptr;
  typedef std::shared_ptr< ::sick_scan::SickLocSetOdometryPortSrvRequest_<ContainerAllocator> const> ConstPtr;

}; // struct SickLocSetOdometryPortSrvRequest_

typedef ::sick_scan::SickLocSetOdometryPortSrvRequest_<std::allocator<void> > SickLocSetOdometryPortSrvRequest;

typedef std::shared_ptr< ::sick_scan::SickLocSetOdometryPortSrvRequest > SickLocSetOdometryPortSrvRequestPtr;
typedef std::shared_ptr< ::sick_scan::SickLocSetOdometryPortSrvRequest const> SickLocSetOdometryPortSrvRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::sick_scan::SickLocSetOdometryPortSrvRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::sick_scan::SickLocSetOdometryPortSrvRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::sick_scan::SickLocSetOdometryPortSrvRequest_<ContainerAllocator1> & lhs, const ::sick_scan::SickLocSetOdometryPortSrvRequest_<ContainerAllocator2> & rhs)
{
  return lhs.port == rhs.port;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::sick_scan::SickLocSetOdometryPortSrvRequest_<ContainerAllocator1> & lhs, const ::sick_scan::SickLocSetOdometryPortSrvRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace sick_scan

namespace roswrap
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::sick_scan::SickLocSetOdometryPortSrvRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::sick_scan::SickLocSetOdometryPortSrvRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sick_scan::SickLocSetOdometryPortSrvRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sick_scan::SickLocSetOdometryPortSrvRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sick_scan::SickLocSetOdometryPortSrvRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sick_scan::SickLocSetOdometryPortSrvRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::sick_scan::SickLocSetOdometryPortSrvRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "f5a0285dfe37e02dce127c75dd32e54b";
  }

  static const char* value(const ::sick_scan::SickLocSetOdometryPortSrvRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xf5a0285dfe37e02dULL;
  static const uint64_t static_value2 = 0xce127c75dd32e54bULL;
};

template<class ContainerAllocator>
struct DataType< ::sick_scan::SickLocSetOdometryPortSrvRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "sick_scan/SickLocSetOdometryPortSrvRequest";
  }

  static const char* value(const ::sick_scan::SickLocSetOdometryPortSrvRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::sick_scan::SickLocSetOdometryPortSrvRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# Definition of ROS service SickLocSetOdometryPort for sick localization\n"
"# Sets the UDP port of the UDP socket for odometry measurement input.\n"
"# Example call (ROS1):\n"
"# rosservice call SickLocSetOdometryPort \"{port: 3000}\"\n"
"# Example call (ROS2):\n"
"# ros2 service call SickLocSetOdometryPort sick_scan/srv/SickLocSetOdometryPortSrv \"{port: 3000}\"\n"
"# \n"
"\n"
"# \n"
"# Request (input)\n"
"# \n"
"\n"
"uint32 port # The new UDP port of the UDP socket for odometry measurement input. [<min>, <max>] \n"
"\n"
;
  }

  static const char* value(const ::sick_scan::SickLocSetOdometryPortSrvRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace roswrap

namespace roswrap
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::sick_scan::SickLocSetOdometryPortSrvRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.port);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SickLocSetOdometryPortSrvRequest_

} // namespace serialization
} // namespace roswrap

namespace roswrap
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::sick_scan::SickLocSetOdometryPortSrvRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::sick_scan::SickLocSetOdometryPortSrvRequest_<ContainerAllocator>& v)
  {
    s << indent << "port: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.port);
  }
};

} // namespace message_operations
} // namespace roswrap

#endif // SICK_SCAN_MESSAGE_SICKLOCSETODOMETRYPORTSRVREQUEST_H
