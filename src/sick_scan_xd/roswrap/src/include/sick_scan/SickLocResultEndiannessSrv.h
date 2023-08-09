#include "sick_scan/sick_scan_base.h" /* Base definitions included in all header files, added by add_sick_scan_base_header.py. Do not edit this line. */
// Generated by gencpp from file sick_scan/SickLocResultEndiannessSrv.msg
// DO NOT EDIT!


#ifndef SICK_SCAN_MESSAGE_SICKLOCRESULTENDIANNESSSRV_H
#define SICK_SCAN_MESSAGE_SICKLOCRESULTENDIANNESSSRV_H

#include <ros/service_traits.h>


#include <sick_scan/SickLocResultEndiannessSrvRequest.h>
#include <sick_scan/SickLocResultEndiannessSrvResponse.h>


namespace sick_scan
{

struct SickLocResultEndiannessSrv
{

typedef SickLocResultEndiannessSrvRequest Request;
typedef SickLocResultEndiannessSrvResponse Response;
Request request;
Response response;

typedef Request RequestType;
typedef Response ResponseType;

}; // struct SickLocResultEndiannessSrv
} // namespace sick_scan


namespace roswrap
{
namespace service_traits
{


template<>
struct MD5Sum< ::sick_scan::SickLocResultEndiannessSrv > {
  static const char* value()
  {
    return "88982bf17b34b54e9b8b616fcb4b8f05";
  }

  static const char* value(const ::sick_scan::SickLocResultEndiannessSrv&) { return value(); }
};

template<>
struct DataType< ::sick_scan::SickLocResultEndiannessSrv > {
  static const char* value()
  {
    return "sick_scan/SickLocResultEndiannessSrv";
  }

  static const char* value(const ::sick_scan::SickLocResultEndiannessSrv&) { return value(); }
};


// service_traits::MD5Sum< ::sick_scan::SickLocResultEndiannessSrvRequest> should match
// service_traits::MD5Sum< ::sick_scan::SickLocResultEndiannessSrv >
template<>
struct MD5Sum< ::sick_scan::SickLocResultEndiannessSrvRequest>
{
  static const char* value()
  {
    return MD5Sum< ::sick_scan::SickLocResultEndiannessSrv >::value();
  }
  static const char* value(const ::sick_scan::SickLocResultEndiannessSrvRequest&)
  {
    return value();
  }
};

// service_traits::DataType< ::sick_scan::SickLocResultEndiannessSrvRequest> should match
// service_traits::DataType< ::sick_scan::SickLocResultEndiannessSrv >
template<>
struct DataType< ::sick_scan::SickLocResultEndiannessSrvRequest>
{
  static const char* value()
  {
    return DataType< ::sick_scan::SickLocResultEndiannessSrv >::value();
  }
  static const char* value(const ::sick_scan::SickLocResultEndiannessSrvRequest&)
  {
    return value();
  }
};

// service_traits::MD5Sum< ::sick_scan::SickLocResultEndiannessSrvResponse> should match
// service_traits::MD5Sum< ::sick_scan::SickLocResultEndiannessSrv >
template<>
struct MD5Sum< ::sick_scan::SickLocResultEndiannessSrvResponse>
{
  static const char* value()
  {
    return MD5Sum< ::sick_scan::SickLocResultEndiannessSrv >::value();
  }
  static const char* value(const ::sick_scan::SickLocResultEndiannessSrvResponse&)
  {
    return value();
  }
};

// service_traits::DataType< ::sick_scan::SickLocResultEndiannessSrvResponse> should match
// service_traits::DataType< ::sick_scan::SickLocResultEndiannessSrv >
template<>
struct DataType< ::sick_scan::SickLocResultEndiannessSrvResponse>
{
  static const char* value()
  {
    return DataType< ::sick_scan::SickLocResultEndiannessSrv >::value();
  }
  static const char* value(const ::sick_scan::SickLocResultEndiannessSrvResponse&)
  {
    return value();
  }
};

} // namespace service_traits
} // namespace roswrap

#endif // SICK_SCAN_MESSAGE_SICKLOCRESULTENDIANNESSSRV_H
