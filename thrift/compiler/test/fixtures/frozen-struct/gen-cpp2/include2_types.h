/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#pragma once

#include <thrift/lib/cpp2/GeneratedHeaderHelper.h>
#include <thrift/lib/cpp2/Thrift.h>
#include <thrift/lib/cpp2/gen/module_types_h.h>
#include <thrift/lib/cpp2/protocol/Protocol.h>


// BEGIN declare_enums

// END declare_enums
// BEGIN struct_indirection

// END struct_indirection
// BEGIN forward_declare
namespace some { namespace ns {
class IncludedB;
}} // some::ns
// END forward_declare
// BEGIN typedefs

// END typedefs
// BEGIN hash_and_equal_to
// END hash_and_equal_to
namespace some { namespace ns {
class IncludedB final : private apache::thrift::detail::st::ComparisonOperators<IncludedB> {
 public:

  IncludedB() :
      i32Field(0) {}
  // FragileConstructor for use in initialization lists only.
  IncludedB(apache::thrift::FragileConstructor, int32_t i32Field__arg, std::string strField__arg);
  template <typename _T>
  void __set_field(::apache::thrift::detail::argument_wrapper<1, _T> arg) {
    i32Field = arg.move();
    __isset.i32Field = true;
  }
  template <typename _T>
  void __set_field(::apache::thrift::detail::argument_wrapper<2, _T> arg) {
    strField = arg.move();
    __isset.strField = true;
  }

  IncludedB(IncludedB&&) = default;

  IncludedB(const IncludedB&) = default;

  IncludedB& operator=(IncludedB&&) = default;

  IncludedB& operator=(const IncludedB&) = default;
  void __clear();
  int32_t i32Field;
  std::string strField;

  struct __isset {
    bool i32Field;
    bool strField;
  } __isset = {};
  bool operator==(const IncludedB& rhs) const;
  bool operator<(const IncludedB& rhs) const;

  int32_t get_i32Field() const {
    return i32Field;
  }

  int32_t& set_i32Field(int32_t i32Field_) {
    i32Field = i32Field_;
    __isset.i32Field = true;
    return i32Field;
  }

  const std::string& get_strField() const& {
    return strField;
  }

  std::string get_strField() && {
    return std::move(strField);
  }

  template <typename T_IncludedB_strField_struct_setter = std::string>
  std::string& set_strField(T_IncludedB_strField_struct_setter&& strField_) {
    strField = std::forward<T_IncludedB_strField_struct_setter>(strField_);
    __isset.strField = true;
    return strField;
  }

  template <class Protocol_>
  uint32_t read(Protocol_* iprot);
  template <class Protocol_>
  uint32_t serializedSize(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t serializedSizeZC(Protocol_ const* prot_) const;
  template <class Protocol_>
  uint32_t write(Protocol_* prot_) const;

 private:
  template <class Protocol_>
  void readNoXfer(Protocol_* iprot);

  friend class ::apache::thrift::Cpp2Ops< IncludedB >;
};

void swap(IncludedB& a, IncludedB& b);
extern template void IncludedB::readNoXfer<>(apache::thrift::BinaryProtocolReader*);
extern template uint32_t IncludedB::write<>(apache::thrift::BinaryProtocolWriter*) const;
extern template uint32_t IncludedB::serializedSize<>(apache::thrift::BinaryProtocolWriter const*) const;
extern template uint32_t IncludedB::serializedSizeZC<>(apache::thrift::BinaryProtocolWriter const*) const;
extern template void IncludedB::readNoXfer<>(apache::thrift::CompactProtocolReader*);
extern template uint32_t IncludedB::write<>(apache::thrift::CompactProtocolWriter*) const;
extern template uint32_t IncludedB::serializedSize<>(apache::thrift::CompactProtocolWriter const*) const;
extern template uint32_t IncludedB::serializedSizeZC<>(apache::thrift::CompactProtocolWriter const*) const;

template <class Protocol_>
uint32_t IncludedB::read(Protocol_* iprot) {
  auto _xferStart = iprot->getCurrentPosition().getCurrentPosition();
  readNoXfer(iprot);
  return iprot->getCurrentPosition().getCurrentPosition() - _xferStart;
}

}} // some::ns
namespace apache { namespace thrift {

template <> inline void Cpp2Ops< ::some::ns::IncludedB>::clear( ::some::ns::IncludedB* obj) {
  return obj->__clear();
}

template <> inline constexpr apache::thrift::protocol::TType Cpp2Ops< ::some::ns::IncludedB>::thriftType() {
  return apache::thrift::protocol::T_STRUCT;
}

template <> template <class Protocol> uint32_t Cpp2Ops< ::some::ns::IncludedB>::write(Protocol* proto,  ::some::ns::IncludedB const* obj) {
  return obj->write(proto);
}

template <> template <class Protocol> void Cpp2Ops< ::some::ns::IncludedB>::read(Protocol* proto,  ::some::ns::IncludedB* obj) {
  return obj->readNoXfer(proto);
}

template <> template <class Protocol> uint32_t Cpp2Ops< ::some::ns::IncludedB>::serializedSize(Protocol const* proto,  ::some::ns::IncludedB const* obj) {
  return obj->serializedSize(proto);
}

template <> template <class Protocol> uint32_t Cpp2Ops< ::some::ns::IncludedB>::serializedSizeZC(Protocol const* proto,  ::some::ns::IncludedB const* obj) {
  return obj->serializedSizeZC(proto);
}

}} // apache::thrift
