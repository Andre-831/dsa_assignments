#include <iostream>
#include <string>
#include "bst.h"


  void BST::postorder_clear(Node* node){
     if (node == nullptr) return;

    postorder_clear(node->left);
    postorder_clear(node->right);
    delete node;
  }
  
  BST::~BST(){
    postorder_clear(root);
  }


  Node* BST::search(Node* node, int key){
    if(node == nullptr || node->key == key){
        return node;
    }
    if(key < node->key){
        return search(node->left, key);
    }
    else{
        return search(node->right, key);
    }
    }

  bool BST::search(int key){
      return search(root,key) != nullptr;
  }


  void BST::insert(Node*& node, int key){
    if (node == nullptr) {
      node = new Node(key);
    } 
    else if (key < node->key) {
      insert(node->left, key);
    } 
    else {
      insert(node->right, key);
    }
  }

  void BST::insert(int key) {
      Node* node = new Node(key);
      Node* prev = nullptr;
      Node* temp = root;
      
      while( temp!= nullptr){
        prev = temp;
        if(node->key < temp->key){
          temp = temp->left;
        }
        else{
          temp = temp->right;
        }
      }
      node->parent = prev;
      if(prev == nullptr){
        root = node;
        return;
      } //attach L or R
      else if (node->key < prev->key) {
      prev->left = node;
      }
      else {
        prev->right = node;
      }
  }


    //delete
      void BST::remove(Node*& node) {
        Node* target;
        Node* temp;
        if(node->left == nullptr || node->right == nullptr) {
            target = node;    
        } else {
            target = successor(node);
        }
        if(target->left != nullptr) {
            temp = target->left;
        } else {
            temp = target->right;
        }
        if(temp != nullptr) {
            temp->parent = target->parent;
        }
        if(target->parent == nullptr) {
            root = temp;
        } else {
            if(target == target->parent->left) {
                target->parent->left = temp;
            } else {
                target->parent->right = temp;
            }
        }
        if(target != nullptr) {
        // copy target value into "Node node"
        // delete target
          node->key = target->key;
          delete target;
        }
}



    void BST::remove(int key){
      Node* node = search(root, key);
      if(node != nullptr) {
        remove(node);
      }
   
    }


    Node* BST::min_Node(Node* node){
        if(node == nullptr) return nullptr;

        while(node->left != nullptr){
            node = node->left;

        }
        return node;
    }

    int BST::min(){
        return min_Node(root)->key;
    }


     Node* BST::max_Node(Node* node){
        if(node == nullptr) return nullptr;

        while(node->right != nullptr){
            node = node->right;
            
        }
        return node;
     }

     int BST::max(){
        return max_Node(root)->key;
     }

     Node* BST::successor(Node* node){
        //bounds check
        if(node == nullptr) return nullptr;

        if(node->right != nullptr) return min_Node(node->right);

        Node* temp = node->parent;
        
        while(temp && node == temp->right){
            node = temp;
            temp = temp->parent;
        }
        return temp;
     }

     std::pair<int, bool> BST::successor(int key) {
          Node* node = search(root, key);  //throw an error check if in tree, check if no successor
          if (node == nullptr) return {key, false};
          Node* temp = successor(node);
          if (temp == nullptr) return {key, false};
      return {temp->key, true};
      }

      Node* BST::predecessor(Node* node){
        if(node == nullptr) return nullptr;
        

        if(node->left != nullptr) return max_Node(node->left);
        
        
        Node* temp = node->parent;
        while(temp && node == temp->left){
            node = temp;
            temp = temp->parent;
        }
        return temp;
      }
//int* or pair
      std::pair<int, bool> BST::predecessor(int key) {
        Node* node = search(root, key);
        if (node == nullptr) return {key, false};  //throw error not in tree
        Node* temp = predecessor(node);
        if (temp == nullptr) return {key, false};  //no predecessor
        return {temp->key, true};
}

      void BST::inorder(Node* node){
        //bounds

        if(node == nullptr) return;

        inorder(node->left);
        //x->print print(x)
        std::cout << node->key << " ";
        inorder(node->right);
      }

      void BST::inorder_traversal(){
        inorder(root);
        std::cout << std::endl;
      }

      void BST:: preorder(Node* node){
        if(node == nullptr) return;

        std::cout << node->key << " ";
        preorder(node->left);
        preorder(node->right);
      }

      void BST::preorder_traversal(){
        preorder(root);
        std::cout << std::endl;
      }

      void BST::postorder(Node* node){
        if(node == nullptr) return;

        postorder(node->left);
        postorder(node->right);
        std::cout << node->key << " ";
      }

      void BST::postorder_traversal(){
        postorder(root);
        std::cout << std::endl;
      }
