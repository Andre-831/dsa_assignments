#ifndef SEGMENT_TREE_H
#define SEGMENT_TREE_H

#include<iostream>
#include<vector>

class segmentTree{

public:
    segmentTree(std::vector<int>&data);
    ~segmentTree(); //destructor

    int query(int left, int right);//the sum of elements in the range [left, right]


    void update(int index, int value); // Update the element at index to a new value

    void print(); //print visualization of the tree

  
private:

  struct Node{
    int value;
    int start;
    int end;
    Node* left;
    Node* right;

     Node(int value, int start, int end) : value(value), start(start), end(end), left(nullptr), right(nullptr) {}
  };

    Node* root;

    Node* buildTree(const std::vector<int>& data, int start, int end); // Helper function to build the segment tree
    int query(Node* node, int qleft, int qright); //helper function to query the sum
    void update(Node* node, int index, int value); // helpler function
    void destroyTree(Node* node);
    void print(Node* node, int indent = 0); // Helper function for printing
};

#endif