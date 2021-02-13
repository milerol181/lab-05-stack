//
// Created by milerol on 12.02.2021.
//

#ifndef LAB_05_STACK_NO_COPY_STACK_HPP
#define LAB_05_STACK_NO_COPY_STACK_HPP
#include <iostream>

template <typename T>
class no_copy_stack
{
  node<T> *element_top;
 public:
  no_copy_stack() : element_top(nullptr) {};
  no_copy_stack(const no_copy_stack& no_copy_stack) = delete; // конструктор копирования (запрещен)
  no_copy_stack(no_copy_stack&& no_copy_stack) = default; // конструктор перемещения
  no_copy_stack &operator=(const no_copy_stack& no_copy_stack) = delete; //перегрузка копирования
  no_copy_stack &operator=(no_copy_stack && no_copy_stack)  = default; //перегрузка перемещения
  template <typename... Args>
  void push_emplace(Args&&... value){
    element_top = new node<T>{{std::forward<Args>(value)...}, element_top};
  }

  void push(T&& value){
    element_top = new node<T> {std::forward<T>(value), element_top};
  }
  const T& head() const {
    if (!element_top) throw std::runtime_error("Stack is empty!");
    return element_top->data;
  }
  T pop() {
    if (!element_top) throw std::runtime_error("Stack is empty!");
    node<T> *delete_node = element_top;
    T data = std::move(element_top->data);
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
  }
};
#endif  // LAB_05_STACK_NO_COPY_STACK_HPP
