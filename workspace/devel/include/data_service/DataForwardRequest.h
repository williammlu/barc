// Generated by gencpp from file data_service/DataForwardRequest.msg
// DO NOT EDIT!


#ifndef DATA_SERVICE_MESSAGE_DATAFORWARDREQUEST_H
#define DATA_SERVICE_MESSAGE_DATAFORWARDREQUEST_H


#include <string>
#include <vector>
#include <map>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <data_service/TimeSignal.h>
#include <data_service/CustomSignal.h>

namespace data_service
{
template <class ContainerAllocator>
struct DataForwardRequest_
{
  typedef DataForwardRequest_<ContainerAllocator> Type;

  DataForwardRequest_()
    : time_signal()
    , custom_signal()
    , experiment_name()  {
    }
  DataForwardRequest_(const ContainerAllocator& _alloc)
    : time_signal(_alloc)
    , custom_signal(_alloc)
    , experiment_name(_alloc)  {
  (void)_alloc;
    }



   typedef  ::data_service::TimeSignal_<ContainerAllocator>  _time_signal_type;
  _time_signal_type time_signal;

   typedef  ::data_service::CustomSignal_<ContainerAllocator>  _custom_signal_type;
  _custom_signal_type custom_signal;

   typedef std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other >  _experiment_name_type;
  _experiment_name_type experiment_name;




  typedef boost::shared_ptr< ::data_service::DataForwardRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::data_service::DataForwardRequest_<ContainerAllocator> const> ConstPtr;

}; // struct DataForwardRequest_

typedef ::data_service::DataForwardRequest_<std::allocator<void> > DataForwardRequest;

typedef boost::shared_ptr< ::data_service::DataForwardRequest > DataForwardRequestPtr;
typedef boost::shared_ptr< ::data_service::DataForwardRequest const> DataForwardRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::data_service::DataForwardRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::data_service::DataForwardRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}

} // namespace data_service

namespace ros
{
namespace message_traits
{



// BOOLTRAITS {'IsFixedSize': False, 'IsMessage': True, 'HasHeader': False}
// {'data_service': ['/home/odroid/barc/workspace/src/data_service/msg'], 'std_msgs': ['/opt/ros/kinetic/share/std_msgs/cmake/../msg']}

// !!!!!!!!!!! ['__class__', '__delattr__', '__dict__', '__doc__', '__eq__', '__format__', '__getattribute__', '__hash__', '__init__', '__module__', '__ne__', '__new__', '__reduce__', '__reduce_ex__', '__repr__', '__setattr__', '__sizeof__', '__str__', '__subclasshook__', '__weakref__', '_parsed_fields', 'constants', 'fields', 'full_name', 'has_header', 'header_present', 'names', 'package', 'parsed_fields', 'short_name', 'text', 'types']




template <class ContainerAllocator>
struct IsFixedSize< ::data_service::DataForwardRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::data_service::DataForwardRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct IsMessage< ::data_service::DataForwardRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::data_service::DataForwardRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::data_service::DataForwardRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::data_service::DataForwardRequest_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::data_service::DataForwardRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "66879b37a6a1d948514d4b887d4a03a9";
  }

  static const char* value(const ::data_service::DataForwardRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x66879b37a6a1d948ULL;
  static const uint64_t static_value2 = 0x514d4b887d4a03a9ULL;
};

template<class ContainerAllocator>
struct DataType< ::data_service::DataForwardRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "data_service/DataForwardRequest";
  }

  static const char* value(const ::data_service::DataForwardRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::data_service::DataForwardRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "TimeSignal time_signal\n\
CustomSignal custom_signal\n\
string experiment_name\n\
\n\
================================================================================\n\
MSG: data_service/TimeSignal\n\
string name\n\
float64[] timestamps\n\
string signal\n\
\n\
================================================================================\n\
MSG: data_service/CustomSignal\n\
string id\n\
string signal\n\
";
  }

  static const char* value(const ::data_service::DataForwardRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::data_service::DataForwardRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.time_signal);
      stream.next(m.custom_signal);
      stream.next(m.experiment_name);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct DataForwardRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::data_service::DataForwardRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::data_service::DataForwardRequest_<ContainerAllocator>& v)
  {
    s << indent << "time_signal: ";
    s << std::endl;
    Printer< ::data_service::TimeSignal_<ContainerAllocator> >::stream(s, indent + "  ", v.time_signal);
    s << indent << "custom_signal: ";
    s << std::endl;
    Printer< ::data_service::CustomSignal_<ContainerAllocator> >::stream(s, indent + "  ", v.custom_signal);
    s << indent << "experiment_name: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other > >::stream(s, indent + "  ", v.experiment_name);
  }
};

} // namespace message_operations
} // namespace ros

#endif // DATA_SERVICE_MESSAGE_DATAFORWARDREQUEST_H