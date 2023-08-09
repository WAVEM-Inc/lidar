#include "sick_scan/sick_scan_base.h" /* Base definitions included in all header files, added by add_sick_scan_base_header.py. Do not edit this line. */
// Generated by gencpp from file sick_scan/SickLdmrsObjectArray.msg
// DO NOT EDIT!


#ifndef SICK_SCAN_MESSAGE_SICKLDMRSOBJECTARRAY_H
#define SICK_SCAN_MESSAGE_SICKLDMRSOBJECTARRAY_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <sick_scan/SickLdmrsObject.h>

namespace sick_scan
{
template <class ContainerAllocator>
struct SickLdmrsObjectArray_
{
  typedef SickLdmrsObjectArray_<ContainerAllocator> Type;

  SickLdmrsObjectArray_()
    : header()
    , objects()  {
    }
  SickLdmrsObjectArray_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , objects(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef std::vector< ::sick_scan::SickLdmrsObject_<ContainerAllocator> , typename ContainerAllocator::template rebind< ::sick_scan::SickLdmrsObject_<ContainerAllocator> >::other >  _objects_type;
  _objects_type objects;





  typedef std::shared_ptr< ::sick_scan::SickLdmrsObjectArray_<ContainerAllocator> > Ptr;
  typedef std::shared_ptr< ::sick_scan::SickLdmrsObjectArray_<ContainerAllocator> const> ConstPtr;

}; // struct SickLdmrsObjectArray_

typedef ::sick_scan::SickLdmrsObjectArray_<std::allocator<void> > SickLdmrsObjectArray;

typedef std::shared_ptr< ::sick_scan::SickLdmrsObjectArray > SickLdmrsObjectArrayPtr;
typedef std::shared_ptr< ::sick_scan::SickLdmrsObjectArray const> SickLdmrsObjectArrayConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::sick_scan::SickLdmrsObjectArray_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::sick_scan::SickLdmrsObjectArray_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::sick_scan::SickLdmrsObjectArray_<ContainerAllocator1> & lhs, const ::sick_scan::SickLdmrsObjectArray_<ContainerAllocator2> & rhs)
{
  return lhs.header == rhs.header &&
    lhs.objects == rhs.objects;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::sick_scan::SickLdmrsObjectArray_<ContainerAllocator1> & lhs, const ::sick_scan::SickLdmrsObjectArray_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace sick_scan

namespace roswrap
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::sick_scan::SickLdmrsObjectArray_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::sick_scan::SickLdmrsObjectArray_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sick_scan::SickLdmrsObjectArray_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::sick_scan::SickLdmrsObjectArray_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sick_scan::SickLdmrsObjectArray_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::sick_scan::SickLdmrsObjectArray_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::sick_scan::SickLdmrsObjectArray_<ContainerAllocator> >
{
  static const char* value()
  {
    return "09128101facd48306fd0cf85eaf2be8f";
  }

  static const char* value(const ::sick_scan::SickLdmrsObjectArray_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x09128101facd4830ULL;
  static const uint64_t static_value2 = 0x6fd0cf85eaf2be8fULL;
};

template<class ContainerAllocator>
struct DataType< ::sick_scan::SickLdmrsObjectArray_<ContainerAllocator> >
{
  static const char* value()
  {
    return "sick_scan/SickLdmrsObjectArray";
  }

  static const char* value(const ::sick_scan::SickLdmrsObjectArray_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::sick_scan::SickLdmrsObjectArray_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# ROS-1: \n"
"Header header\n"
"# ROS-2: \n"
"# std_msgs/Header header\n"
"SickLdmrsObject[] objects\n"
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
"MSG: sick_scan/SickLdmrsObject\n"
"int32 id\n"
"\n"
"# ROS-1:\n"
"time tracking_time                      # since when the object is tracked\n"
"time last_seen\n"
"\n"
"# ROS-2:\n"
"#builtin_interfaces/Time tracking_time  # since when the object is tracked\n"
"#builtin_interfaces/Time last_seen\n"
"\n"
"geometry_msgs/TwistWithCovariance velocity\n"
"\n"
"geometry_msgs/Pose bounding_box_center\n"
"geometry_msgs/Vector3 bounding_box_size\n"
"\n"
"geometry_msgs/PoseWithCovariance object_box_center\n"
"geometry_msgs/Vector3 object_box_size\n"
"\n"
"geometry_msgs/Point[] contour_points\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/TwistWithCovariance\n"
"# This expresses velocity in free space with uncertainty.\n"
"\n"
"Twist twist\n"
"\n"
"# Row-major representation of the 6x6 covariance matrix\n"
"# The orientation parameters use a fixed-axis representation.\n"
"# In order, the parameters are:\n"
"# (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)\n"
"float64[36] covariance\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Twist\n"
"# This expresses velocity in free space broken into its linear and angular parts.\n"
"Vector3  linear\n"
"Vector3  angular\n"
"\n"
"================================================================================\n"
"MSG: geometry_msgs/Vector3\n"
"# This represents a vector in free space. \n"
"# It is only meant to represent a direction. Therefore, it does not\n"
"# make sense to apply a translation to it (e.g., when applying a \n"
"# generic rigid transformation to a Vector3, tf2 will only apply the\n"
"# rotation). If you want your data to be translatable too, use the\n"
"# geometry_msgs/Point message instead.\n"
"\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
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
"\n"
"================================================================================\n"
"MSG: geometry_msgs/PoseWithCovariance\n"
"# This represents a pose in free space with uncertainty.\n"
"\n"
"Pose pose\n"
"\n"
"# Row-major representation of the 6x6 covariance matrix\n"
"# The orientation parameters use a fixed-axis representation.\n"
"# In order, the parameters are:\n"
"# (x, y, z, rotation about X axis, rotation about Y axis, rotation about Z axis)\n"
"float64[36] covariance\n"
;
  }

  static const char* value(const ::sick_scan::SickLdmrsObjectArray_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace roswrap

namespace roswrap
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::sick_scan::SickLdmrsObjectArray_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.objects);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SickLdmrsObjectArray_

} // namespace serialization
} // namespace roswrap

namespace roswrap
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::sick_scan::SickLdmrsObjectArray_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::sick_scan::SickLdmrsObjectArray_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "objects[]" << std::endl;
    for (size_t i = 0; i < v.objects.size(); ++i)
    {
      s << indent << "  objects[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::sick_scan::SickLdmrsObject_<ContainerAllocator> >::stream(s, indent + "    ", v.objects[i]);
    }
  }
};

} // namespace message_operations
} // namespace roswrap

#endif // SICK_SCAN_MESSAGE_SICKLDMRSOBJECTARRAY_H
