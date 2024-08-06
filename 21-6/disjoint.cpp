#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include "disjoint.h"
#include "maze.h"


    Disjointset::Disjointset(int size) {
            p.resize(size); //parent 
            r.resize(size); //rank
            numsets = size;

            for(unsigned int i = 0; i < p.size(); i++){
                p[i] = i; //parent is itself
                r[i] = 0; //all initially rank 0
            }
        }


    int Disjointset::find(int x){
            /* bounds check here 
            if (x < 0 || x >= p.size()) {
                throw std::out_of_range("Index out of range");
            }
            */
            if(p[x] != x){
                p[x] = find(p[x]);
            }
            return p[x];
        }
        
    void Disjointset::union_set(int x, int y){
        //bounds check x & y 
        int parent_size = p.size();
        if (x < 0 || x >= parent_size || y < 0 || y >= parent_size) {
            throw std::out_of_range("Index out of range");
        }
        link(find(x), find(y));
    }
        
    int Disjointset::get_num_sets(){
        return numsets;
        int count = 0;
        int parent_size = p.size();
        for( int i = 0; i < parent_size; i++){
            if(p[i] == i){
                count++;
            }
        }
        return count;
    }


    int Disjointset::same_component(int x, int y){ return find(x) == find(y);}

    void Disjointset::link(int x, int y){
        if (x == y) return;
        --numsets;
        if (r[x] > r[y]) {
            p[y] = x;
        } else {
            p[x] = y;
            if (r[x] == r[y]) {
                r[y]++;
            }
        }
    }


