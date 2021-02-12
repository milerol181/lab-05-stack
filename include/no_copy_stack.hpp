//
// Created by milerol on 12.02.2021.
//

#ifndef LAB_05_STACK_NO_COPY_STACK_HPP
#define LAB_05_STACK_NO_COPY_STACK_HPP
#include "Stack.hpp"
template <typename T>
class no_copy_stack
{
 public:
  no_copy_stack() : element_top(nullptr) {};
  template <typename ... Args>
  void push_emplace(Args&&... value);
  void push(T&& value){
    node<T>* new_node = new node<T>;
    new_node->data = value;
    new_node->element_next = element_top;
    element_top = new_node;
  }
  const T& head() const {
    if (empty()) throw std::runtime_error("Stack is empty!");
    return element_top->data;
  }
  T pop() {
    if (empty()) throw std::runtime_error("Stack is empty!");
    node<T> *delete_node = element_top;
    element_top = delete_node->element_next;
    delete delete_node;
    return data;
  }
  ~no_copy_stack(){
    while (element_top){
      node<T> *delete_node = element_top;
      element_top = delete_node->element_next;
      delete delete_node;
  }

 private:
  node<T> *element_top;
};
#endif  // LAB_05_STACK_NO_COPY_STACK_HPP
