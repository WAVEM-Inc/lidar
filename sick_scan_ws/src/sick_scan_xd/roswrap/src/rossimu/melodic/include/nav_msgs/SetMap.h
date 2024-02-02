#include "sick_scan/sick_scan_base.h" /* Base definitions included in all header files, added by add_sick_scan_base_header.py. Do not edit this line. */
// Generated by gencpp from file nav_msgs/SetMap.msg
// DO NOT EDIT!


#ifndef NAV_MSGS_MESSAGE_SETMAP_H
#define NAV_MSGS_MESSAGE_SETMAP_H

#include <ros/service_traits.h>


#include <nav_msgs/SetMapRequest.h>
#include <nav_msgs/SetMapResponse.h>


namespace nav_msgs
{

struct SetMap
{

typedef SetMapRequest Request;
typedef SetMapResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct SetMap
} // namespace nav_msgs


namespace roswrap
{
namespace service_traits
{


template<>
struct MD5Sum< ::nav_msgs::SetMap > {
  static const char* value()
  {
    return "c36922319011e63ed7784112ad4fdd32";
  }

  static const char* value(const ::nav_msgs::SetMap&) { return value(); }
};

template<>
struct DataType< ::nav_msgs::SetMap > {
  static const char* value()
  {
    return "nav_msgs/SetMap";
  }

  static const char* value(const ::nav_msgs::SetMap&) { return value(); }
};


// service_traits::MD5Sum< ::nav_msgs::SetMapRequest> should match
// service_traits::MD5Sum< ::nav_msgs::SetMap >
template<>
struct MD5Sum< ::nav_msgs::SetMapRequest>
{
  static const char* value()
  {
    return MD5Sum< ::nav_msgs::SetMap >::value();
  }
  static const char* value(const ::nav_msgs::SetMapRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::nav_msgs::SetMapRequest> should match
// service_traits::DataType< ::nav_msgs::SetMap >
template<>
struct DataType< ::nav_msgs::SetMapRequest>
{
  static const char* value()
  {
    return DataType< ::nav_msgs::SetMap >::value();
  }
  static const char* value(const ::nav_msgs::SetMapRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::nav_msgs::SetMapResponse> should match
// service_traits::MD5Sum< ::nav_msgs::SetMap >
template<>
struct MD5Sum< ::nav_msgs::SetMapResponse>
{
  static const char* value()
  {
    return MD5Sum< ::nav_msgs::SetMap >::value();
  }
  static const char* value(const ::nav_msgs::SetMapResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::nav_msgs::SetMapResponse> should match
// service_traits::DataType< ::nav_msgs::SetMap >
template<>
struct DataType< ::nav_msgs::SetMapResponse>
{
  static const char* value()
  {
    return DataType< ::nav_msgs::SetMap >::value();
  }
  static const char* value(const ::nav_msgs::SetMapResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace roswrap

#endif // NAV_MSGS_MESSAGE_SETMAP_H
