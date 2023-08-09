#include "sick_scan/sick_scan_base.h" /* Base definitions included in all header files, added by add_sick_scan_base_header.py. Do not edit this line. */
// Generated by gencpp from file sick_scan/SickLocResultPoseIntervalSrvResponse.msg
// DO NOT EDIT!


#ifndef SICK_SCAN_MESSAGE_SICKLOCRESULTPOSEINTERVALSRVRESPONSE_H
#define SICK_SCAN_MESSAGE_SICKLOCRESULTPOSEINTERVALSRVRESPONSE_H


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
struct SickLocResultPoseIntervalSrvResponse_
{
  typedef SickLocResultPoseIntervalSrvResponse_<ContainerAllocator> Type;

  SickLocResultPoseIntervalSrvResponse_()
    : interval(0)
    , success(false)  {
    }
  SickLocResultPoseIntervalSrvResponse_(const ContainerAllocator& _alloc)
    : interval(0)
    , success(false)  {
  (void)_alloc;
    }



   typedef int32_t _interval_type;
  _interval_type interval;

   typedef uint8_t _success_type;
  _success_type success;





  typedef std::shared_ptr< ::sick_scan::SickLocResultPoseIntervalSrvResponse_<ContainerAllocator> > Ptr;
  typedef std::shared_ptr< ::sick_scan::SickLocResultPoseIntervalSrvResponse_<ContainerAllocator> const> ConstPtr;

}; // struct SickLocResultPoseIntervalSrvResponse_

typedef ::sick_scan::SickLocResultPoseIntervalSrvResponse_<std::allocator<void> > SickLocResultPoseIntervalSrvResponse;

typedef std::shared_ptr< ::sick_scan::SickLocResultPoseIntervalSrvResponse > SickLocResultPoseIntervalSrvResponsePtr;
typedef std::shared_ptr< ::sick_scan::SickLocResultPoseIntervalSrvResponse const> SickLocResultPoseIntervalSrvResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::sick_scan::SickLocResultPoseIntervalSrvResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::sick_scan::SickLocResultPoseIntervalSrvResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::sick_scan::SickLocResultPoseIntervalSrvResponse_<ContainerAllocator1> & lhs, const ::sick_scan::SickLocResultPoseIntervalSrvResponse_<ContainerAllocator2> & rhs)
{
  return lhs.interval == rhs.interval &&
    lhs.success == rhs.success;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::sick_scan::SickLocResultPoseIntervalSrvResponse_<ContainerAllocator1> & lhs, const ::sick_scan::SickLocResultPoseIntervalSrvResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace sick_scan

namespace roswrap
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::sick_scan::SickLocResultPoseIntervalSrvResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::sick_scan::SickLocResultPoseIntervalSrvResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sick_scan::SickLocResultPoseIntervalSrvResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sick_scan::SickLocResultPoseIntervalSrvResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sick_scan::SickLocResultPoseIntervalSrvResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sick_scan::SickLocResultPoseIntervalSrvResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::sick_scan::SickLocResultPoseIntervalSrvResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "5fbbb521f9143c1864acfd50dae1fd6e";
  }

  static const char* value(const ::sick_scan::SickLocResultPoseIntervalSrvResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x5fbbb521f9143c18ULL;
  static const uint64_t static_value2 = 0x64acfd50dae1fd6eULL;
};

template<class ContainerAllocator>
struct DataType< ::sick_scan::SickLocResultPoseIntervalSrvResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "sick_scan/SickLocResultPoseIntervalSrvResponse";
  }

  static const char* value(const ::sick_scan::SickLocResultPoseIntervalSrvResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::sick_scan::SickLocResultPoseIntervalSrvResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "\n"
"# \n"
"# Response (output)\n"
"# \n"
"\n"
"int32 interval # interval in number of scans, 0-255, 1 (default): result with each processed scan\n"
"bool success # true: success response received from localization controller, false: service failed (timeout or error status from controller)\n"
"\n"
;
  }

  static const char* value(const ::sick_scan::SickLocResultPoseIntervalSrvResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace roswrap

namespace roswrap
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::sick_scan::SickLocResultPoseIntervalSrvResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.interval);
      stream.next(m.success);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SickLocResultPoseIntervalSrvResponse_

} // namespace serialization
} // namespace roswrap

namespace roswrap
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::sick_scan::SickLocResultPoseIntervalSrvResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::sick_scan::SickLocResultPoseIntervalSrvResponse_<ContainerAllocator>& v)
  {
    s << indent << "interval: ";
    Printer<int32_t>::stream(s, indent + "  ", v.interval);
    s << indent << "success: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.success);
  }
};

} // namespace message_operations
} // namespace roswrap

#endif // SICK_SCAN_MESSAGE_SICKLOCRESULTPOSEINTERVALSRVRESPONSE_H
