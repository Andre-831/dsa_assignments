#ifndef RBT_H
#define RBT_H
#include <iostream>
#include <utility> 
/*
Node Color: Each node is either red or black.
Root Property: The root of the tree is always black.
Red Property: Red nodes cannot have red children (no two consecutive red nodes on any path).
Black Property: Every path from a node to its descendant null nodes (leaves) has the same number of black nodes.
Leaf Property: All leaves (NIL nodes) are black.
*/

 enum Color { RED, BLACK };  

 struct Node{
    int key;
    Color color;
     Node* left;
     Node* right;
     Node* parent;

     Node(int key) : key(key), left(nullptr), right(nullptr), parent(nullptr) {}

 };

class RBT{
    

    public:
        RBT() : root(nullptr) {}
        ~RBT(); //destructor
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

        void leftRotate(Node* x); //
        void rightRotate(Node* x); //
        void insertFix(Node* z); //
        void removeFix(Node* x); //

        void transplant(Node* u, Node* v);
//fix insert and remove done 
};

#endif
