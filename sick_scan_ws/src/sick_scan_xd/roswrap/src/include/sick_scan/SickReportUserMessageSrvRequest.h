#include "sick_scan/sick_scan_base.h" /* Base definitions included in all header files, added by add_sick_scan_base_header.py. Do not edit this line. */
// Generated by gencpp from file sick_scan/SickReportUserMessageSrvRequest.msg
// DO NOT EDIT!


#ifndef SICK_SCAN_MESSAGE_SICKREPORTUSERMESSAGESRVREQUEST_H
#define SICK_SCAN_MESSAGE_SICKREPORTUSERMESSAGESRVREQUEST_H


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
struct SickReportUserMessageSrvRequest_
{
  typedef SickReportUserMessageSrvRequest_<ContainerAllocator> Type;

  SickReportUserMessageSrvRequest_()
    : usermessage()  {
    }
  SickReportUserMessageSrvRequest_(const ContainerAllocator& _alloc)
    : usermessage(_alloc)  {
  (void)_alloc;
    }



   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _usermessage_type;
  _usermessage_type usermessage;





  typedef std::shared_ptr< ::sick_scan::SickReportUserMessageSrvRequest_<ContainerAllocator> > Ptr;
  typedef std::shared_ptr< ::sick_scan::SickReportUserMessageSrvRequest_<ContainerAllocator> const> ConstPtr;

}; // struct SickReportUserMessageSrvRequest_

typedef ::sick_scan::SickReportUserMessageSrvRequest_<std::allocator<void> > SickReportUserMessageSrvRequest;

typedef std::shared_ptr< ::sick_scan::SickReportUserMessageSrvRequest > SickReportUserMessageSrvRequestPtr;
typedef std::shared_ptr< ::sick_scan::SickReportUserMessageSrvRequest const> SickReportUserMessageSrvRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::sick_scan::SickReportUserMessageSrvRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::sick_scan::SickReportUserMessageSrvRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::sick_scan::SickReportUserMessageSrvRequest_<ContainerAllocator1> & lhs, const ::sick_scan::SickReportUserMessageSrvRequest_<ContainerAllocator2> & rhs)
{
  return lhs.usermessage == rhs.usermessage;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::sick_scan::SickReportUserMessageSrvRequest_<ContainerAllocator1> & lhs, const ::sick_scan::SickReportUserMessageSrvRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace sick_scan

namespace roswrap
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::sick_scan::SickReportUserMessageSrvRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::sick_scan::SickReportUserMessageSrvRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sick_scan::SickReportUserMessageSrvRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sick_scan::SickReportUserMessageSrvRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sick_scan::SickReportUserMessageSrvRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sick_scan::SickReportUserMessageSrvRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::sick_scan::SickReportUserMessageSrvRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "7bd60f6e741b97c1cf891ee07a12d676";
  }

  static const char* value(const ::sick_scan::SickReportUserMessageSrvRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x7bd60f6e741b97c1ULL;
  static const uint64_t static_value2 = 0xcf891ee07a12d676ULL;
};

template<class ContainerAllocator>
struct DataType< ::sick_scan::SickReportUserMessageSrvRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "sick_scan/SickReportUserMessageSrvRequest";
  }

  static const char* value(const ::sick_scan::SickReportUserMessageSrvRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::sick_scan::SickReportUserMessageSrvRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# Definition of ROS service SickReportUserMessage for sick localization\n"
"# Method to report messages to the localization system.\n"
"# Example call (ROS1):\n"
"# rosservice call SickReportUserMessage \"{usermessage: test_message}\"\n"
"# Example call (ROS2):\n"
"# ros2 service call SickReportUserMessage sick_scan/srv/SickReportUserMessageSrv \"{usermessage: test_message}\"\n"
"# \n"
"\n"
"# \n"
"# Request (input)\n"
"# \n"
"\n"
"string usermessage # The message transmitted to the localization system. Max length = 400 \n"
"\n"
;
  }

  static const char* value(const ::sick_scan::SickReportUserMessageSrvRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace roswrap

namespace roswrap
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::sick_scan::SickReportUserMessageSrvRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.usermessage);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SickReportUserMessageSrvRequest_

} // namespace serialization
} // namespace roswrap

namespace roswrap
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::sick_scan::SickReportUserMessageSrvRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::sick_scan::SickReportUserMessageSrvRequest_<ContainerAllocator>& v)
  {
    s << indent << "usermessage: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.usermessage);
  }
};

} // namespace message_operations
} // namespace roswrap

#endif // SICK_SCAN_MESSAGE_SICKREPORTUSERMESSAGESRVREQUEST_H
