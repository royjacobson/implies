#include <implies/implies.hpp>
#include <gtest/gtest.h>

TEST(implies, simple_truth_table) {
  using namespace implies;
  static_assert(  Bool(false) --> Bool(false));
  static_assert(  Bool(false) --> Bool(true));
  static_assert(!(Bool(true)  --> Bool(false)));
  static_assert(  Bool(true)  --> Bool(true));
}

TEST(implies, concatenated_statements) {
  using namespace implies;
  static_assert(!(Bool(false) --> Bool(false) --> Bool(false)));
  static_assert(  Bool(false) --> Bool(false) --> Bool(true));
  static_assert(!(Bool(false) --> Bool(true)  --> Bool(false)));
  static_assert(  Bool(false) --> Bool(true)  --> Bool(true));
  static_assert(  Bool(true)  --> Bool(false) --> Bool(false));
  static_assert(  Bool(true)  --> Bool(false) --> Bool(true));
  static_assert(!(Bool(true)  --> Bool(true)  --> Bool(false)));
  static_assert(  Bool(true)  --> Bool(true)  --> Bool(true));
}
