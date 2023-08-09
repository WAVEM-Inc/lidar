#include "sick_scan/sick_scan_base.h" /* Base definitions included in all header files, added by add_sick_scan_base_header.py. Do not edit this line. */
// Generated by gencpp from file visualization_msgs/InteractiveMarkerPose.msg
// DO NOT EDIT!


#ifndef VISUALIZATION_MSGS_MESSAGE_INTERACTIVEMARKERPOSE_H
#define VISUALIZATION_MSGS_MESSAGE_INTERACTIVEMARKERPOSE_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <geometry_msgs/Pose.h>

namespace visualization_msgs
{
template <class ContainerAllocator>
struct InteractiveMarkerPose_
{
  typedef InteractiveMarkerPose_<ContainerAllocator> Type;

  InteractiveMarkerPose_()
    : header()
    , pose()
    , name()  {
    }
  InteractiveMarkerPose_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , pose(_alloc)
    , name(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef  ::geometry_msgs::Pose_<ContainerAllocator>  _pose_type;
  _pose_type pose;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _name_type;
  _name_type name;





  typedef std::shared_ptr< ::visualization_msgs::InteractiveMarkerPose_<ContainerAllocator> > Ptr;
  typedef std::shared_ptr< ::visualization_msgs::InteractiveMarkerPose_<ContainerAllocator> const> ConstPtr;

}; // struct InteractiveMarkerPose_

typedef ::visualization_msgs::InteractiveMarkerPose_<std::allocator<void> > InteractiveMarkerPose;

typedef std::shared_ptr< ::visualization_msgs::InteractiveMarkerPose > InteractiveMarkerPosePtr;
typedef std::shared_ptr< ::visualization_msgs::InteractiveMarkerPose const> InteractiveMarkerPoseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::visualization_msgs::InteractiveMarkerPose_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::visualization_msgs::InteractiveMarkerPose_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::visualization_msgs::InteractiveMarkerPose_<ContainerAllocator1> & lhs, const ::visualization_msgs::InteractiveMarkerPose_<ContainerAllocator2> & rhs)
{
  return lhs.header == rhs.header &&
    lhs.pose == rhs.pose &&
    lhs.name == rhs.name;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::visualization_msgs::InteractiveMarkerPose_<ContainerAllocator1> & lhs, const ::visualization_msgs::InteractiveMarkerPose_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace visualization_msgs

namespace roswrap
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::visualization_msgs::InteractiveMarkerPose_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::visualization_msgs::InteractiveMarkerPose_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::visualization_msgs::InteractiveMarkerPose_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::visualization_msgs::InteractiveMarkerPose_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::visualization_msgs::InteractiveMarkerPose_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::visualization_msgs::InteractiveMarkerPose_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::visualization_msgs::InteractiveMarkerPose_<ContainerAllocator> >
{
  static const char* value()
  {
    return "a6e6833209a196a38d798dadb02c81f8";
  }

  static const char* value(const ::visualization_msgs::InteractiveMarkerPose_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xa6e6833209a196a3ULL;
  static const uint64_t static_value2 = 0x8d798dadb02c81f8ULL;
};

template<class ContainerAllocator>
struct DataType< ::visualization_msgs::InteractiveMarkerPose_<ContainerAllocator> >
{
  static const char* value()
  {
    return "visualization_msgs/InteractiveMarkerPose";
  }

  static const char* value(const ::visualization_msgs::InteractiveMarkerPose_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::visualization_msgs::InteractiveMarkerPose_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# Time/frame info.\n"
"Header header\n"
"\n"
"# Initial pose. Also, defines the pivot point for rotations.\n"
"geometry_msgs/Pose pose\n"
"\n"
"# Identifying string. Must be globally unique in\n"
"# the topic that this message is sent through.\n"
"string name\n"
"\n"
"================================================================================\n"
"MSG: std_msgs/Header\n"
"# Standard metadata for higher-level stamped data types.\n"
"# This is generally used to communicate timestamped data \n"
"# in a particular coordinate frame.\n"
"# \n"
"# sequence ID: consecutively increasing ID \n"
"uint32 seq\n"
"#Two-integer timestamp that is expressed as:\n"
"# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n"
"# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n"
"# time-handling sugar is provided by the client library\n"
"time stamp\n"
"#Frame this data is associated with\n"
"string frame_id\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Pose\n"
"# A representation of pose in free space, composed of position and orientation. \n"
"Point position\n"
"Quaternion orientation\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Point\n"
"# This contains the position of a point in free space\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Quaternion\n"
"# This represents an orientation in free space in quaternion form.\n"
"\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
"float64 w\n"
;
  }

  static const char* value(const ::visualization_msgs::InteractiveMarkerPose_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace roswrap

namespace roswrap
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::visualization_msgs::InteractiveMarkerPose_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.pose);
      stream.next(m.name);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct InteractiveMarkerPose_

} // namespace serialization
} // namespace roswrap

namespace roswrap
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::visualization_msgs::InteractiveMarkerPose_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::visualization_msgs::InteractiveMarkerPose_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "pose: ";
    s << std::endl;
    Printer< ::geometry_msgs::Pose_<ContainerAllocator> >::stream(s, indent + "  ", v.pose);
    s << indent << "name: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.name);
  }
};

} // namespace message_operations
} // namespace roswrap

#endif // VISUALIZATION_MSGS_MESSAGE_INTERACTIVEMARKERPOSE_H
