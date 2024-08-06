#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include "disjoint.h"
#include "maze.h"







mazeGenerator:: mazeGenerator(int size_) : size(size_),  disjointSet(size_ * size_){
        maze.resize(size, std::vector<char>(size, 0x0F)); //set maze
        entrance = 0;
        exit = size * size - 1;
        maze[exit / size][exit % size] = 0x0E;
        maze[entrance / size][entrance % size] = 0x0B;

    }


std::string mazeGenerator::Maze(){
    std::string result;
    generateMaze();

    for(int i =0; i < size; i++){
        for(int j = 0; j < size; j++){
            result += "0123456789ABCDEF"[static_cast<int>(maze[i][j])];
        }
        result += '\n';
    }
    return result;
   }


void mazeGenerator::generateMaze(){

        
        int directions[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        
        std::vector<int>indecies_of_maze; //fill this with 0 - n^2 -1 
        
        for(int i = 0; i < size*size; i++) {
            indecies_of_maze.push_back(i);
        }

        //random number
        std::random_device rd;
        std::mt19937 g(rd());

       
        std::uniform_int_distribution<>  distrib(0, 3);

        while(disjointSet.get_num_sets() != 1){
            //std::cout << disjointSet.get_num_sets() << std::endl;
            //disjointSet.debug();
            std::shuffle(indecies_of_maze.begin(), indecies_of_maze.end(), g);
             // Shuffle the indices of the cells in the maze
            

        for(int i : indecies_of_maze){
            int random_direction = distrib(g); 
            //std::cout << i << ": " << random_direction << std::endl;
            int direction_x = directions[random_direction][0];
            int direction_y = directions[random_direction][1];

            int x = i % size;
            int y = i / size;

            int next_x = x + direction_x;
            int next_y = y + direction_y;

            if(next_x >= 0 && next_x < size && next_y >= 0 && next_y < size){
               // std::cout << x << ", " << y << " : " << next_x << ", " << next_y << std::endl;
                if(!disjointSet.same_component(i,next_x + size * next_y)){
                //std::cout << "join cells\n";

               

           
                    //remove wall
                    maze[y][x] &= ~(1u << random_direction);
                    maze[next_y][next_x] &= ~(1u << ((random_direction + 2) % 4));

                    disjointSet.union_set(x + y * size, next_x + next_y * size);

                    
                }
                    
            }
           
        }


    }

    }

