/*
Andre Ballesteros
aballest@pengo
dreb1204@gmail.com
21-1.cpp
Programming Assingment #1, linked lists review and stacks


this file is to demonstrate the stack working which is lifo
reads strings and adds them to stack(push) as input and prints them (pop)

program compiles and runs
tested with no words, nothing printed which is correct
tested with a few words, they printed out correctly
tested with 1 million strings, they printed correctly

*/
#include <iostream>
#include <string>
#include "stack.h"


int main(){
  Stack<std::string> stack;
    std::string input;

    while (std::getline(std::cin, input)) {
        stack.push(input);
    }

    while (!stack.isEmpty()) {
        std::cout << stack.pop() << std::endl;
    }

return 0;
}