
/*
Programming Assingment #2, min heap and priority queue


this file is to demonstrate a priority queue
reads ints and adds them to heap correctly as input and prints them when prompted

program compiles and runs
tested with no words, nothing printed which is correct
tested with a few words, they printed out correctly
tested with 1 million strings, they printed correctly
tested with 2.4 million

*/



#include <iostream>
#include <algorithm>
#include <sstream>
#include"int_min_heap.h"
#include <fstream>



int main(){

intMinHeap heap(2400000);
    int input = 0;

        //std::ifstream file("nums.txt");


    while(std::cin >> input){
        //if the input value is a positive integer (greater than zero,) insert it into your object. 
        //This operation prints "insert" and the value that was added.
        if(input > 0){
            heap.heapinsert(input);
            std::cout << "insert: " << input << std::endl;

        } //if the input value is a zero, print the heap and the size of the heap on a single line of text (as a comma seperated list.)
        else if( input == 0){
            std::cout << "heap size: " << heap.getSize() << ": " << heap.toString() << std::endl;
        }
        //If the input value is a -1, extract the minimum value from your object, and print that value on a single line.
        else if(input == -1){
            if(!heap.isEmpty()){
            std::cout << "extract min: " << heap.extractmin() << std::endl;
            }
            else{
                std::cout << "extract min: 0" << std::endl;
            }

        } //If the input value is a -2, call heapsort, and then print, on a single line, as a comma-sperated list the sorted array
        else if(input == -2){
            std::pair<int*, int> sorted_array = heap.heapsort();
            std::cout << "sorted array: [";
            for(int i =0; i < sorted_array.second; i++){
                std::cout << sorted_array.first[i];
               if( i < sorted_array.second - 1){
                  std::cout << ", ";
               }
            }
            std::cout << "]" << std::endl;
        }
    }



}
