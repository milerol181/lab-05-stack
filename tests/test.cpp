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
TEST(Example, second_test) {
  std::string error1;
  std::string check = "Stack is empty!";
  try {Stack<int> first;
  first.push(9);
  first.pop();
  first.head();}
   catch (std::string ERROR) {
    error1 = ERROR;
    std::cout << "mistake is here: " << ERROR << std::endl;
  }
  EXPECT_EQ(error1, check);
}