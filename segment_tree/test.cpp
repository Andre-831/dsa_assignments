#include<iostream>
#include<vector>
#include"segment_tree.h"



int main(){
    std::vector<int>data; //={1,3,5,7,9,11};
    data.push_back(1);
    data.push_back(3);
    data.push_back(5);
    data.push_back(7);
    data.push_back(9);
    data.push_back(11);
    segmentTree tree(data);

    std::cout << "sum of data in range : " << tree.query(1,3) << std::endl;
    
    //update value 
    tree.update(1,10);


    std::cout << "updated sum of data in range : " << tree.query(1,3) << std::endl;


}