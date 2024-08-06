#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include "disjoint.h"



class mazeGenerator{

    public:
    mazeGenerator(int size_);

    std::string Maze();

    private:
        int size;
        Disjointset disjointSet;
        std::vector<std::vector<bool>> visited;
        std::vector<std::vector<char>> maze;
        int entrance;
        int exit;
        void generateMaze();

};

#endif

