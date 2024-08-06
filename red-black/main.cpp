#include <iostream>
#include <fstream> 
#include <sstream> 
#include <string> 
#include "red_black.h"

/*

Programming Assingment #7, Binary search Tree


this file is to demonstrate a binary search tree with integers

program compiles and runs
testing all functions, traversals with empty tree and it prints out order: then next line is empty
tested with sample input and compared with example output

*/
int main() {
    RBT RBT;
    int key = 0;
    std::string line;
    std::string option;
    std::string value;
    //int result = 0;
    std::pair<int, bool> result;
    while(std::getline(std::cin, line)){
        std::istringstream iss(line);
        iss >> option >> std::ws;
        if(!iss.eof()){
            value = iss.str().substr(iss.tellg());
        }
        

        if (option == "insert" || option == "search" || option == "delete" || 
            option == "predecessor" || option == "successor") {
            
            iss >> value;
            key = std::stoi(value);
        }

        if(option == "insert"){
            //key = std::stoi(value);
            RBT.insert(key);
            std::cout <<"inserted " << key << "." << std::endl;
        }
        else if(option == "search"){
            //key = std::stoi(value);

            if(RBT.search(key)){
                std::cout << key << " found." << std::endl;
            }
            else{
                std::cout << key << " not found." << std::endl;
            }
        }
        else if(option == "delete"){
            //key = std::stoi(value);

            if(RBT.search(key)){
                RBT.remove(key);
                std::cout << "deleted " << key << "." << std::endl;
            }
            else{
                std::cout << "delete " << key <<" - not found." << std::endl;
            }
        }
        else if(option == "min"){
            std::cout << "min is " << RBT.min() << "." << std::endl;
        }
        else if(option == "max"){
            std::cout << "max is " << RBT.max() << "." << std::endl;
        }
        else if(option == "predecessor"){
            //key = std::stoi(value);
            //std::pair<int, bool> result;
            if (RBT.search(key)) {
                result = RBT.predecessor(key);
            if (result.second) {
                std::cout << key << " predecessor is " << result.first << "." << std::endl;
            } else {
                std::cout << "no predecessor for " << key << "." << std::endl;
            }
            } else {
                std::cout << key << " not in tree." << std::endl;
            }
            
        }
        else if(option == "successor"){
            //key = std::stoi(value);
            
            if (RBT.search(key)) {
            result = RBT.successor(key);
                if (result.second) {
                    std::cout << key << " successor is " << result.first << "." << std::endl;
                } else {
                    std::cout << "no successor for " << key << "." << std::endl;
                }
            } else {
                std::cout << key << " not in tree." << std::endl;
            }
        }
        else if (option == "inorder") {
            std::cout <<"inorder traversal:" <<std::endl;
            RBT.inorder_traversal();
            //std::cout << std::endl;
        } 
        else if (option == "preorder") {
            std::cout <<"preorder traversal:" <<std::endl;
            RBT.preorder_traversal();
            //std::cout << std::endl;
        } 
        else if (option == "postorder") {
            std::cout <<"postorder traversal:" <<std::endl;
            RBT.postorder_traversal();
            //std::cout << std::endl;
        }

    }

}

