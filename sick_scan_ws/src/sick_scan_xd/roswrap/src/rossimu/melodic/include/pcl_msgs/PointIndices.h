#include "sick_scan/sick_scan_base.h" /* Base definitions included in all header files, added by add_sick_scan_base_header.py. Do not edit this line. */
// Generated by gencpp from file pcl_msgs/PointIndices.msg
// DO NOT EDIT!


#ifndef PCL_MSGS_MESSAGE_POINTINDICES_H
#define PCL_MSGS_MESSAGE_POINTINDICES_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace pcl_msgs
{
template <class ContainerAllocator>
struct PointIndices_
{
  typedef PointIndices_<ContainerAllocator> Type;

  PointIndices_()
    : header()
    , indices()  {
    }
  PointIndices_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , indices(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef std::vector<int32_t, typename ContainerAllocator::template rebind<int32_t>::other >  _indices_type;
  _indices_type indices;





  typedef std::shared_ptr< ::pcl_msgs::PointIndices_<ContainerAllocator> > Ptr;
  typedef std::shared_ptr< ::pcl_msgs::PointIndices_<ContainerAllocator> const> ConstPtr;

}; // struct PointIndices_

typedef ::pcl_msgs::PointIndices_<std::allocator<void> > PointIndices;

typedef std::shared_ptr< ::pcl_msgs::PointIndices > PointIndicesPtr;
typedef std::shared_ptr< ::pcl_msgs::PointIndices const> PointIndicesConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::pcl_msgs::PointIndices_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::pcl_msgs::PointIndices_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::pcl_msgs::PointIndices_<ContainerAllocator1> & lhs, const ::pcl_msgs::PointIndices_<ContainerAllocator2> & rhs)
{
  return lhs.header == rhs.header &&
    lhs.indices == rhs.indices;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::pcl_msgs::PointIndices_<ContainerAllocator1> & lhs, const ::pcl_msgs::PointIndices_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace pcl_msgs

namespace roswrap
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsFixedSize< ::pcl_msgs::PointIndices_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::pcl_msgs::PointIndices_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::pcl_msgs::PointIndices_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::pcl_msgs::PointIndices_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::pcl_msgs::PointIndices_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::pcl_msgs::PointIndices_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::pcl_msgs::PointIndices_<ContainerAllocator> >
{
  static const char* value()
  {
    return "458c7998b7eaf99908256472e273b3d4";
  }

  static const char* value(const ::pcl_msgs::PointIndices_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x458c7998b7eaf999ULL;
  static const uint64_t static_value2 = 0x08256472e273b3d4ULL;
};

template<class ContainerAllocator>
struct DataType< ::pcl_msgs::PointIndices_<ContainerAllocator> >
{
  static const char* value()
  {
    return "pcl_msgs/PointIndices";
  }

  static const char* value(const ::pcl_msgs::PointIndices_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::pcl_msgs::PointIndices_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header header\n"
"int32[] indices\n"
"\n"
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
;
  }

  static const char* value(const ::pcl_msgs::PointIndices_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace roswrap

namespace roswrap
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::pcl_msgs::PointIndices_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.indices);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct PointIndices_

} // namespace serialization
} // namespace roswrap

namespace roswrap
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::pcl_msgs::PointIndices_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::pcl_msgs::PointIndices_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "indices[]" << std::endl;
    for (size_t i = 0; i < v.indices.size(); ++i)
    {
      s << indent << "  indices[" << i << "]: ";
      Printer<int32_t>::stream(s, indent + "  ", v.indices[i]);
    }
  }
};

} // namespace message_operations
} // namespace roswrap

#endif // PCL_MSGS_MESSAGE_POINTINDICES_H
