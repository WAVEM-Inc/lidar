#include "sick_scan/sick_scan_base.h" /* Base definitions included in all header files, added by add_sick_scan_base_header.py. Do not edit this line. */
// Generated by gencpp from file geometry_msgs/PointStamped.msg
// DO NOT EDIT!


#ifndef GEOMETRY_MSGS_MESSAGE_POINTSTAMPED_H
#define GEOMETRY_MSGS_MESSAGE_POINTSTAMPED_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <geometry_msgs/Point.h>

namespace geometry_msgs
{
template <class ContainerAllocator>
struct PointStamped_
{
  typedef PointStamped_<ContainerAllocator> Type;

  PointStamped_()
    : header()
    , point()  {
    }
  PointStamped_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , point(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef  ::geometry_msgs::Point_<ContainerAllocator>  _point_type;
  _point_type point;




  typedef std::shared_ptr< ::geometry_msgs::PointStamped_<ContainerAllocator> > Ptr;
  typedef std::shared_ptr< ::geometry_msgs::PointStamped_<ContainerAllocator> const> ConstPtr;

}; // struct PointStamped_

typedef ::geometry_msgs::PointStamped_<std::allocator<void> > PointStamped;

typedef std::shared_ptr< ::geometry_msgs::PointStamped > PointStampedPtr;
typedef std::shared_ptr< ::geometry_msgs::PointStamped const> PointStampedConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::geometry_msgs::PointStamped_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::geometry_msgs::PointStamped_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace geometry_msgs

namespace roswrap
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': True}
// {'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg'], 'geometry_msgs': ['/tmp/binarydeb/ros-kinetic-geometry-msgs-1.12.5/msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::geometry_msgs::PointStamped_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::geometry_msgs::PointStamped_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::geometry_msgs::PointStamped_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::geometry_msgs::PointStamped_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::geometry_msgs::PointStamped_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::geometry_msgs::PointStamped_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::geometry_msgs::PointStamped_<ContainerAllocator> >
{
  static const char* value()
  {
    return "c63aecb41bfdfd6b7e1fac37c7cbe7bf";
  }

  static const char* value(const ::geometry_msgs::PointStamped_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xc63aecb41bfdfd6bULL;
  static const uint64_t static_value2 = 0x7e1fac37c7cbe7bfULL;
};

template<class ContainerAllocator>
struct DataType< ::geometry_msgs::PointStamped_<ContainerAllocator> >
{
  static const char* value()
  {
    return "geometry_msgs/PointStamped";
  }

  static const char* value(const ::geometry_msgs::PointStamped_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::geometry_msgs::PointStamped_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# This represents a Point with reference coordinate frame and timestamp\n\
Header header\n\
Point point\n\
\n\
================================================================================\n\
MSG: std_msgs/Header\n\
# Standard metadata for higher-level stamped data types.\n\
# This is generally used to communicate timestamped data \n\
# in a particular coordinate frame.\n\
# \n\
# sequence ID: consecutively increasing ID \n\
uint32 seq\n\
#Two-integer timestamp that is expressed as:\n\
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n\
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n\
# time-handling sugar is provided by the client library\n\
time stamp\n\
#Frame this data is associated with\n\
# 0: no frame\n\
# 1: global frame\n\
string frame_id\n\
\n\
================================================================================\n\
MSG: geometry_msgs/Point\n\
# This contains the position of a point in free space\n\
float64 x\n\
float64 y\n\
float64 z\n\
";
  }

  static const char* value(const ::geometry_msgs::PointStamped_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace roswrap

namespace roswrap
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::geometry_msgs::PointStamped_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.point);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct PointStamped_

} // namespace serialization
} // namespace roswrap

namespace roswrap
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::geometry_msgs::PointStamped_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::geometry_msgs::PointStamped_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "point: ";
    s << std::endl;
    Printer< ::geometry_msgs::Point_<ContainerAllocator> >::stream(s, indent + "  ", v.point);
  }
};

} // namespace message_operations
} // namespace roswrap

#endif // GEOMETRY_MSGS_MESSAGE_POINTSTAMPED_H
