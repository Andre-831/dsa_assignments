#include <iostream>
#include <vector>
#include <random>
#include <string>
#include "maze.h"
#include "disjoint.h"
/*
Andre Ballesteros 0414799
Programming Assingment #6, Maze Generator 


this file is to demonstrate a maze generator
using disjoint sets

program compiles and runs
tested 3x3 maze and it created a valid maze 
generated a 10x10 maze and it was valid 
generated a 1000x1000 maze 
generated 2000x2000 maze

*/
int main(int argc, char**argv){

   int size = std::stoi(argv[1]);

    

    //std::cout << "enter size of maze: ";
    //std::cin >> size;

    mazeGenerator maze(size);

   std::string mazeString = maze.Maze();

   
    // Print the maze to the console
    for (unsigned int i = 0; i < mazeString.length(); i++) {
        std::cout << mazeString[i];

    }

}
