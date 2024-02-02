#include "sick_scan/sick_scan_base.h" /* Base definitions included in all header files, added by add_sick_scan_base_header.py. Do not edit this line. */
// Generated by gencpp from file sick_scan/SickReportUserMessageSrv.msg
// DO NOT EDIT!


#ifndef SICK_SCAN_MESSAGE_SICKREPORTUSERMESSAGESRV_H
#define SICK_SCAN_MESSAGE_SICKREPORTUSERMESSAGESRV_H

#include <ros/service_traits.h>


#include <sick_scan/SickReportUserMessageSrvRequest.h>
#include <sick_scan/SickReportUserMessageSrvResponse.h>


namespace sick_scan
{

struct SickReportUserMessageSrv
{

typedef SickReportUserMessageSrvRequest Request;
typedef SickReportUserMessageSrvResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct SickReportUserMessageSrv
} // namespace sick_scan


namespace roswrap
{
namespace service_traits
{


template<>
struct MD5Sum< ::sick_scan::SickReportUserMessageSrv > {
  static const char* value()
  {
    return "251fd2d79c1fd0839dc49b691122a621";
  }

  static const char* value(const ::sick_scan::SickReportUserMessageSrv&) { return value(); }
};

template<>
struct DataType< ::sick_scan::SickReportUserMessageSrv > {
  static const char* value()
  {
    return "sick_scan/SickReportUserMessageSrv";
  }

  static const char* value(const ::sick_scan::SickReportUserMessageSrv&) { return value(); }
};


// service_traits::MD5Sum< ::sick_scan::SickReportUserMessageSrvRequest> should match
// service_traits::MD5Sum< ::sick_scan::SickReportUserMessageSrv >
template<>
struct MD5Sum< ::sick_scan::SickReportUserMessageSrvRequest>
{
  static const char* value()
  {
    return MD5Sum< ::sick_scan::SickReportUserMessageSrv >::value();
  }
  static const char* value(const ::sick_scan::SickReportUserMessageSrvRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::sick_scan::SickReportUserMessageSrvRequest> should match
// service_traits::DataType< ::sick_scan::SickReportUserMessageSrv >
template<>
struct DataType< ::sick_scan::SickReportUserMessageSrvRequest>
{
  static const char* value()
  {
    return DataType< ::sick_scan::SickReportUserMessageSrv >::value();
  }
  static const char* value(const ::sick_scan::SickReportUserMessageSrvRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::sick_scan::SickReportUserMessageSrvResponse> should match
// service_traits::MD5Sum< ::sick_scan::SickReportUserMessageSrv >
template<>
struct MD5Sum< ::sick_scan::SickReportUserMessageSrvResponse>
{
  static const char* value()
  {
    return MD5Sum< ::sick_scan::SickReportUserMessageSrv >::value();
  }
  static const char* value(const ::sick_scan::SickReportUserMessageSrvResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::sick_scan::SickReportUserMessageSrvResponse> should match
// service_traits::DataType< ::sick_scan::SickReportUserMessageSrv >
template<>
struct DataType< ::sick_scan::SickReportUserMessageSrvResponse>
{
  static const char* value()
  {
    return DataType< ::sick_scan::SickReportUserMessageSrv >::value();
  }
  static const char* value(const ::sick_scan::SickReportUserMessageSrvResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace roswrap

#endif // SICK_SCAN_MESSAGE_SICKREPORTUSERMESSAGESRV_H
