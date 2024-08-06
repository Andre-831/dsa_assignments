/*
Andre Ballesteros
aballest@pengo
dreb1204@gmail.com
linked_list.h
Programming Assingment #1, linked lists review and stacks
this file is impkentation of stack which is lifo, last in first out
*/

#ifndef STACK_H_
#define STACK_H_

#include <initializer_list>
#include "linked_list.h"

template <typename T>
class Stack{
  public:
    Stack() {}

   //adds value to stack
   void push(T value){
     list.insert_front(value);
   }
//removes value from stack(pops it from the front)
   T pop(){
    if (isEmpty()) {
      throw std::domain_error("Stack is empty");
    }
    T value = list.front();
    list.remove_front();
    return value;
   }
//checks if the stack is empty
   bool isEmpty(){
    return list.empty();
   }

  private:
  LinkedList<T> list;

};
#endif //STACK_H_