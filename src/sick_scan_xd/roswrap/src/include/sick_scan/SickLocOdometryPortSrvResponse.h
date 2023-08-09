#include "sick_scan/sick_scan_base.h" /* Base definitions included in all header files, added by add_sick_scan_base_header.py. Do not edit this line. */
// Generated by gencpp from file sick_scan/SickLocOdometryPortSrvResponse.msg
// DO NOT EDIT!


#ifndef SICK_SCAN_MESSAGE_SICKLOCODOMETRYPORTSRVRESPONSE_H
#define SICK_SCAN_MESSAGE_SICKLOCODOMETRYPORTSRVRESPONSE_H


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
struct SickLocOdometryPortSrvResponse_
{
  typedef SickLocOdometryPortSrvResponse_<ContainerAllocator> Type;

  SickLocOdometryPortSrvResponse_()
    : port(0)
    , success(false)  {
    }
  SickLocOdometryPortSrvResponse_(const ContainerAllocator& _alloc)
    : port(0)
    , success(false)  {
  (void)_alloc;
    }



   typedef uint32_t _port_type;
  _port_type port;

   typedef uint8_t _success_type;
  _success_type success;





  typedef std::shared_ptr< ::sick_scan::SickLocOdometryPortSrvResponse_<ContainerAllocator> > Ptr;
  typedef std::shared_ptr< ::sick_scan::SickLocOdometryPortSrvResponse_<ContainerAllocator> const> ConstPtr;

}; // struct SickLocOdometryPortSrvResponse_

typedef ::sick_scan::SickLocOdometryPortSrvResponse_<std::allocator<void> > SickLocOdometryPortSrvResponse;

typedef std::shared_ptr< ::sick_scan::SickLocOdometryPortSrvResponse > SickLocOdometryPortSrvResponsePtr;
typedef std::shared_ptr< ::sick_scan::SickLocOdometryPortSrvResponse const> SickLocOdometryPortSrvResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::sick_scan::SickLocOdometryPortSrvResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::sick_scan::SickLocOdometryPortSrvResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::sick_scan::SickLocOdometryPortSrvResponse_<ContainerAllocator1> & lhs, const ::sick_scan::SickLocOdometryPortSrvResponse_<ContainerAllocator2> & rhs)
{
  return lhs.port == rhs.port &&
    lhs.success == rhs.success;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::sick_scan::SickLocOdometryPortSrvResponse_<ContainerAllocator1> & lhs, const ::sick_scan::SickLocOdometryPortSrvResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace sick_scan

namespace roswrap
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::sick_scan::SickLocOdometryPortSrvResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::sick_scan::SickLocOdometryPortSrvResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sick_scan::SickLocOdometryPortSrvResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sick_scan::SickLocOdometryPortSrvResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sick_scan::SickLocOdometryPortSrvResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sick_scan::SickLocOdometryPortSrvResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::sick_scan::SickLocOdometryPortSrvResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "eab9e3edf2e953793a7a218ea447017c";
  }

  static const char* value(const ::sick_scan::SickLocOdometryPortSrvResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xeab9e3edf2e95379ULL;
  static const uint64_t static_value2 = 0x3a7a218ea447017cULL;
};

template<class ContainerAllocator>
struct DataType< ::sick_scan::SickLocOdometryPortSrvResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "sick_scan/SickLocOdometryPortSrvResponse";
  }

  static const char* value(const ::sick_scan::SickLocOdometryPortSrvResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::sick_scan::SickLocOdometryPortSrvResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n"
"# \n"
"# Response (output)\n"
"# \n"
"\n"
"uint32 port # The new UDP port of the UDP socket for odometry measurement input. [<min>, <max>] \n"
"bool success # true: success response received from localization controller, false: service failed (timeout or error status from controller)\n"
"\n"
;
  }

  static const char* value(const ::sick_scan::SickLocOdometryPortSrvResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace roswrap

namespace roswrap
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::sick_scan::SickLocOdometryPortSrvResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.port);
      stream.next(m.success);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SickLocOdometryPortSrvResponse_

} // namespace serialization
} // namespace roswrap

namespace roswrap
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::sick_scan::SickLocOdometryPortSrvResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::sick_scan::SickLocOdometryPortSrvResponse_<ContainerAllocator>& v)
  {
    s << indent << "port: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.port);
    s << indent << "success: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.success);
  }
};

} // namespace message_operations
} // namespace roswrap

#endif // SICK_SCAN_MESSAGE_SICKLOCODOMETRYPORTSRVRESPONSE_H
