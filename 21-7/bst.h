#ifndef BST_H
#define BST_H

#include <iostream>

 struct Node{
    int key;

     Node* left;
     Node* right;
     Node* parent;

     Node(int key) : key(key), left(nullptr), right(nullptr), parent(nullptr) {}

 };

class BST{
    

    public:
        BST() : root(nullptr) {}
        ~BST(); //destructor
        bool search(int key);
        void insert(int key);
        void remove(int key);
        int min();
        int max();
        std::pair<int, bool> predecessor(int key);
        std::pair<int, bool> successor(int key);

        void inorder_traversal();
        void preorder_traversal();
        void postorder_traversal();
        


    private:
        Node* root;
        
        Node* search(Node* node, int key);
        void insert(Node*& node, int key);
        void remove(Node*& node);
        Node* min_Node(Node* node);
        Node* max_Node(Node* node);
        Node* successor(Node* node);
        Node* predecessor(Node* node);

        void inorder(Node* node);
        void preorder(Node* node);
        void postorder(Node* node);
        void postorder_clear(Node* node);

       

};

#endif
