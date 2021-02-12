// Copyright 2020 Your Name <your_email>

#include <gtest/gtest.h>
#include "Stack.hpp"
#include <string>

TEST(Example, EmptyTest) {
    EXPECT_TRUE(true);
}
TEST(Example, first_test) {
  Stack<int> first;
  first.push(7);
  EXPECT_EQ(first.head(), 7);
}
TEST(stack, push_lvalue) {
  Stack<unsigned> buffer;
  EXPECT_THROW(buffer.head(), std::runtime_error);
  unsigned value_1 = 10;
  unsigned value_2 = 20;
  unsigned value_3 = 30;
  buffer.push(value_1);
  buffer.push(value_2);
  buffer.push(value_3);
  EXPECT_EQ(buffer.head(),value_3);
}
TEST(stack, push_rvalue) {
  Stack<unsigned> buffer;
  EXPECT_THROW(buffer.head(), std::runtime_error);
  unsigned value_1 = 10;
  buffer.push(10);
  buffer.push(20);
  EXPECT_EQ(buffer.head(),20);
  buffer.push(std::move(value_1));
  EXPECT_EQ(buffer.head(),10);
}
TEST(stack, test_pop) {
  Stack<unsigned> buffer;
  EXPECT_THROW(buffer.pop(), std::runtime_error);
  unsigned value_1 = 10;
  unsigned value_2 = 20;
  unsigned value_3 = 30;
  buffer.push(value_1);
  buffer.push(value_2);
  buffer.push(value_3);
  buffer.pop();
  EXPECT_EQ(buffer.head(),value_2);
  buffer.pop();
  EXPECT_EQ(buffer.head(),value_1);
  buffer.pop();
  EXPECT_THROW(buffer.head(),std::runtime_error);
}
TEST(stack, test_head) {
  Stack<unsigned> buffer;
  EXPECT_THROW(buffer.head(), std::runtime_error);
  buffer.push(10);
  EXPECT_EQ(buffer.head(), 10);
  buffer.push(20);
  EXPECT_EQ(buffer.head(), 20);
  buffer.push(30);
  EXPECT_EQ(buffer.head(), 30);
  buffer.pop();
  EXPECT_EQ(buffer.head(), 20);
}
template <typename T>
struct big_data {
  T value_1;
  T value_2;
  T value_3;
};
TEST(stack, push_rvalue_string) {
  big_data<std::string> buffer_1;
  buffer_1.value_1 = "dog";
  buffer_1.value_2 = "cat";
  buffer_1.value_3 = "bird";
  Stack<big_data<std::string>> buffer_2;
  buffer_2.push(std::move(buffer_1));
  EXPECT_EQ(buffer_2.head().value_1, buffer_1.value_1);
  EXPECT_EQ(buffer_2.head().value_2, buffer_1.value_2);
  EXPECT_EQ(buffer_2.head().value_3, buffer_1.value_3);
}
TEST(stack, test_move){
  EXPECT_EQ(std::is_move_constructible<Stack<unsigned>>::value, true);
  EXPECT_EQ(std::is_move_assignable<Stack<unsigned>>::value, true);
  EXPECT_TRUE(std::is_move_constructible
                  <Stack<big_data<std::string>>>::value);
  EXPECT_TRUE(std::is_move_assignable
                  <Stack<big_data<std::string>>>::value);
}