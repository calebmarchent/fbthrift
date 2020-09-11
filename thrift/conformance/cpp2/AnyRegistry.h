/*
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include <any>
#include <memory>
#include <string>
#include <string_view>
#include <typeindex>
#include <typeinfo>
#include <unordered_map>

#include <folly/Utility.h>
#include <folly/container/F14Map.h>
#include <thrift/conformance/cpp2/AnyRef.h>
#include <thrift/conformance/cpp2/AnySerializer.h>
#include <thrift/conformance/if/gen-cpp2/any_types.h>

namespace apache::thrift::conformance {

// A registry for serializers for use with apache::thrift::conformance::Any.
//
// This registry can be used to store and load
// apache::thrift::conformance::Any values using the registered serializers.
class AnyRegistry {
 public:
  // Store a value in an Any using the registered serializers.
  //
  // Throws std::bad_any_cast if no matching serializer has been registered.
  Any store(any_ref value, const Protocol& protocol) const;
  Any store(const Any& value, const Protocol& protocol) const;
  template <StandardProtocol protocol>
  Any store(any_ref value) {
    return store(value, getStandardProtocol<protocol>());
  }

  // Load a value from an Any using the registered serializers.
  //
  // Throws std::bad_any_cast if no matching serializer has been registered.
  void load(const Any& value, any_ref out) const;
  std::any load(const Any& value) const;
  template <typename T>
  T load(const Any& value) const;

  // Register a type's unique name.
  bool registerType(const std::type_info& type, std::string name);
  // Register an alternative name for the given type.
  //
  // The type must already have been registered.
  bool registerTypeAlt(const std::type_info& type, std::string altName);

  // Register a serializer for a given type.
  //
  // Throws std::out_of_range error if the type has not already been
  // registered.
  bool registerSerializer(
      const std::type_info& type,
      const AnySerializer* serializer);
  bool registerSerializer(
      const std::type_info& type,
      std::unique_ptr<AnySerializer> serializer);

  // Returns the unique type name for the given type, or "" if the type has not
  // been registered.
  std::string_view getTypeName(const std::type_info& type) const;

  // Returns the serializer for the given type and protocol, or nullptr if
  // no matching serializer is found.
  const AnySerializer* getSerializer(
      const std::type_info& type,
      const Protocol& protocol) const;
  const AnySerializer* getSerializer(
      std::string_view name,
      const Protocol& protocol) const;

  // Compile-time Type overloads.
  template <typename T>
  bool registerType(std::string name) {
    return registerType(typeid(T), std::move(name));
  }
  template <typename T>
  bool registerTypeAlt(std::string altName) {
    return registerTypeAlt(typeid(T), std::move(altName));
  }
  template <typename T>
  bool registerSerializer(const AnySerializer* serializer) {
    return registerSerializer(typeid(T), serializer);
  }
  template <typename T>
  bool registerSerializer(std::unique_ptr<AnySerializer> serializer) {
    return registerSerializer(typeid(T), std::move(serializer));
  }

  // Register the given names and serializers for the given type.
  //
  // Returns false iff any registration fails.
  template <
      typename Names = std::vector<std::string>,
      typename Serializers = std::vector<const AnySerializer*>>
  bool registerAll(
      const std::type_info& type,
      Names&& names,
      Serializers&& serializers = {});

  template <
      typename T,
      typename Names = std::vector<std::string>,
      typename Serializers = std::vector<const AnySerializer*>>
  bool registerAll(Names&& names, Serializers&& serializers = {}) {
    return registerAll(
        typeid(T),
        std::forward<Names>(names),
        std::forward<Serializers>(serializers));
  }

 private:
  struct TypeEntry {
    TypeEntry(const std::type_info& type, std::string name)
        : type(type), name(std::move(name)) {}

    const std::type_info& type;
    const std::string name;
    folly::F14FastMap<Protocol, const AnySerializer*> serializers;
  };

  std::vector<std::unique_ptr<AnySerializer>> owned_serializers_;
  folly::F14FastMap<std::type_index, TypeEntry> registry_;
  folly::F14FastMap<std::string, std::type_index> rev_index_;

  // Gets the TypeEntry for the given type, or null if the type has not been
  // registered.
  const TypeEntry* getTypeEntry(std::string_view name) const;
  const TypeEntry* getTypeEntry(const std::type_index& index) const;
  const TypeEntry* getTypeEntry(const std::type_info& type) const {
    return getTypeEntry(std::type_index(type));
  }

  const AnySerializer* getSerializer(
      const TypeEntry* entry,
      const Protocol& protocol) const;
};

// Implementation details.

template <typename T>
T AnyRegistry::load(const Any& value) const {
  T out;
  load(value, out);
  return out;
}

template <typename Names, typename Serializers>
bool AnyRegistry::registerAll(
    const std::type_info& type,
    Names&& names,
    Serializers&& serializers) {
  auto nameItr = names.begin();
  if (nameItr == names.end() ||
      !registerType(type, folly::forward_like<Names>(*nameItr++))) {
    return false;
  }

  // TODO(afuller): Make success atomic.
  bool success = true;
  for (; nameItr != names.end(); ++nameItr) {
    success &= registerTypeAlt(type, folly::forward_like<Names>(*nameItr));
  }
  for (auto& serializer : serializers) {
    success &=
        registerSerializer(type, folly::forward_like<Serializers>(serializer));
  }
  return success;
}

} // namespace apache::thrift::conformance
