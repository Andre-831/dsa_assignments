#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <utility>
#include <algorithm>

std::vector<std::pair<int,int>> reconstruct_path(std::map<std::pair<int, int>, std::pair<int, int>>& parents, 
std::pair<int, int> end){

    std::vector<std::pair<int,int>> path;
    std::pair<int,int>current = end;

    while(current.first != -1){
        path.push_back(current);
        current = parents[current];
    }
    std::reverse(path.begin(),path.end());
    return path;
}



std::vector<std::pair<int,int>>bfs(std::vector<std::string> maze){
    int n = maze.size();
    std::queue<std::pair<int,int>> open;
    std::map<std::pair<int, int>, std::pair<int, int>> parents;
    std::map<std::pair<int, int>, bool> visited;
    int directions[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    


    //start
    open.push(std::make_pair(0,0));
    visited[std::make_pair(0,0)] = true;
    parents[std::make_pair(0,0)] = {-1,-1};

    while(!open.empty()){
        std::pair<int,int> pos = open.front();
       // std::cout << pos.first << pos.second << std::endl;
        open.pop();


        //for each v ∈ Adjacent[u] { // adjacency list or matrix

        for(int i = 0 ; i < 4; i++){
            int x = pos.first + directions[i][0];
            int y = pos.second + directions[i][1];
                //check cell isnt a wall
                if( x >= 0 && x < n && y >= 0 && y < n){
                    if(!(maze[pos.second][pos.first] & (1 << i))){
                        if(!visited[std::make_pair(x,y)]){
                        open.push(std::make_pair(x,y));
                        parents[std::make_pair(x,y)] = pos; //parent of current node as pos
                        visited[std::make_pair(x,y)] = true;
                        //std::cout <<"visited "<< x << "," << y <<"from: " << pos.first <<" ," <<pos.second << std::endl; 
                    }
                    // else{
                    //     //std::cout << x << "," << y << " was already visited" << std::endl;
                    // }
                    }
                    // else{
                    //     //std::cout << x << "," << y << " blocked by wall" << std::endl;
                    // }
                    
                }
                // else{
                //     //std::cout << x << "," << y << " out of bounds" << std::endl;
                // }
        }
    }

    return reconstruct_path(parents,std::make_pair(maze[0].length() -1,maze.size() - 1)); 
}





int main(){

//convert ascii to hex 
    std::vector<std::string> maze;
    std::string line;

    while(std::getline(std::cin, line)){

        for(char &c : line){
            if(c >= '0' && c <= '9'){
                c -= '0';
            }
            if(c >= 'a' && c <= 'f'){
                c = c - 'a' + 10;
            }
            if(c >= 'A' && c <= 'F'){
                c = c - 'A' + 10;
            }
        }
        maze.push_back(line);
    }
    std::vector<std::pair<int, int>> path = bfs(maze);

    for(auto x : path){
        std::cout << "(" << x.first << ", " << x.second << ")" << std::endl;
    }
    
}

