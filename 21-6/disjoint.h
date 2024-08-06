#ifndef DISJOINT_H
#define DISJOINT_H




#include <iostream>
#include <vector>
#include <random>
#include <algorithm>



class Disjointset{

public:

    Disjointset(int size);

    // void debug() {
    //     for (int i : p) {
    //         std::cout << i << " ";

    //     }
    //     std::cout << std::endl;
    // }
    int find(int x);

    void union_set(int x, int y);

    int get_num_sets();

    int same_component(int x, int y);
   

private:
    std::vector<int> p;
    std::vector<int> r; // rank
    int numsets;

    void link(int x, int y);
};


#endif