#include<iostream>
#include<vector>
#include<iomanip>
#include"segment_tree.h"

segmentTree::segmentTree(std::vector<int>&data){
    root = buildTree(data,0,data.size()-1);
}

segmentTree::~segmentTree(){
    destroyTree(root);
}

segmentTree::Node* segmentTree::buildTree(const std::vector<int>& data, int start, int end){
    if(start == end){
        return new Node(data[start], start, end);
    }

    int mid = (start + end) / 2;

    Node*left_child = buildTree(data,start,mid);
    Node*right_child = buildTree(data,mid+1,end);
    
    Node* node = new Node(left_child->value + right_child->value, start, end);
    
    node->left = left_child;
    node->right = right_child;
    return node;
}

int segmentTree::query(int left, int right){
    return query(root,left,right);
}

int segmentTree::query(Node* node, int qleft, int qright){
    if(node->end < qleft || node->start > qright){
        return 0;  //if segment is outside range
    }

    if(node->start >= qleft && node->end <= qright){
        return node->value; //segment is completely in range return nodes value
    }
    int left = query(node->left,qleft,qright);
    int right = query(node->right,qleft,qright);
    return left + right;
}

void segmentTree::update(int index, int value){

    return update(root, index, value);
}

void segmentTree::update(Node* node, int index, int value){
    if(node->start == node->end){ //if leaf node, update value
        node->value = value;
        return;
    }

    int mid = (node->start + node->end) / 2;
    if (index <= mid){ // If the index is in the left subtree, update the left child
        update(node->left,index,value);
    }else{
    update(node->right,index,value);
    }
    // Update the node's value to the sum of its children's values
    node->value = node->right->value + node->left->value; 
}

void segmentTree::destroyTree(segmentTree::Node* node) {
if(node){
    destroyTree(node->left);
    destroyTree(node->right);
    delete node;
}
}

void segmentTree::print(){
print(root,0);
}

void segmentTree::print(Node* node, int indent) {
    if (node != nullptr) {
        if (node->right) {
            print(node->right, indent + 4);
        }
        if (indent) {
            std::cout << std::setw(indent) << ' ';
        }
        if (node->right) {
            std::cout << " /\n" << std::setw(indent) << ' ';
        }
        std::cout << "(" << node->value << ", [" << node->start << ", " << node->end << "])\n";
        if (node->left) {
            std::cout << std::setw(indent) << ' ' << " \\\n";
            print(node->left, indent + 4);
        }
    }
}