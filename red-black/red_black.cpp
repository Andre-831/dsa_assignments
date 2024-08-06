#include "red_black.h"

void RBT::postorder_clear(Node* node) {
    if (node == nullptr) return;
    postorder_clear(node->left);
    postorder_clear(node->right);
    delete node;
}

RBT::~RBT() {
    postorder_clear(root);
}

Node* RBT::search(Node* node, int key) {
    if (node == nullptr || node->key == key) {
        return node;
    }
    if (key < node->key) {
        return search(node->left, key);
    } else {
        return search(node->right, key);
    }
}

bool RBT::search(int key) {
    return search(root, key) != nullptr;
}

void RBT::insert(Node*& node, int key) {
    if (node == nullptr) {
        node = new Node(key);
    } else if (key < node->key) {
        insert(node->left, key);
    } else {
        insert(node->right, key);
    }
}

void RBT::insert(int key) {
    Node* node = new Node(key);
    Node* prev = nullptr;
    Node* temp = root;
    
    while (temp != nullptr) {
        prev = temp;
        if (node->key < temp->key) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }
    }
    node->parent = prev;
    if (prev == nullptr) {
        root = node;
    } else if (node->key < prev->key) {
        prev->left = node;
    } else {
        prev->right = node;
    }
    node->color = RED;
    insertFix(node);
}

void RBT::remove(Node*& node) {
    Node* target;
    Node* x;
    Color original_color = node->color;

    if (node->left == nullptr) {
        x = node->right;
        transplant(node, node->right);
    } else if (node->right == nullptr) {
        x = node->left;
        transplant(node, node->left);
    } else {
        target = min_Node(node->right);
        original_color = target->color;
        x = target->right;
        if (target->parent == node) {
            if (x != nullptr) x->parent = target;
        } else {
            transplant(target, target->right);
            target->right = node->right;
            target->right->parent = target;
        }
        transplant(node, target);
        target->left = node->left;
        target->left->parent = target;
        target->color = node->color;
    }
    delete node;
    if (original_color == BLACK) {
        removeFix(x);
    }
}

void RBT::remove(int key) {
    Node* node = search(root, key);
    if (node != nullptr) {
        remove(node);
    }
}

Node* RBT::min_Node(Node* node) {
    if (node == nullptr) return nullptr;
    while (node->left != nullptr) {
        node = node->left;
    }
    return node;
}

int RBT::min() {
    return min_Node(root)->key;
}

Node* RBT::max_Node(Node* node) {
    if (node == nullptr) return nullptr;
    while (node->right != nullptr) {
        node = node->right;
    }
    return node;
}

int RBT::max() {
    return max_Node(root)->key;
}

Node* RBT::successor(Node* node) {
    if (node == nullptr) return nullptr;
    if (node->right != nullptr) return min_Node(node->right);
    Node* temp = node->parent;
    while (temp && node == temp->right) {
        node = temp;
        temp = temp->parent;
    }
    return temp;
}

std::pair<int, bool> RBT::successor(int key) {
    Node* node = search(root, key);
    if (node == nullptr) return std::make_pair(key, false);
    Node* temp = successor(node);
    if (temp == nullptr) return std::make_pair(key, false);
    return std::make_pair(temp->key, true);
}

Node* RBT::predecessor(Node* node) {
    if (node == nullptr) return nullptr;
    if (node->left != nullptr) return max_Node(node->left);
    Node* temp = node->parent;
    while (temp && node == temp->left) {
        node = temp;
        temp = temp->parent;
    }
    return temp;
}

std::pair<int, bool> RBT::predecessor(int key) {
    Node* node = search(root, key);
    if (node == nullptr) return std::make_pair(key, false);
    Node* temp = predecessor(node);
    if (temp == nullptr) return std::make_pair(key, false);
    return std::make_pair(temp->key, true);
}

void RBT::inorder(Node* node) {
    if (node == nullptr) return;
    inorder(node->left);
    std::cout << node->key << " ";
    inorder(node->right);
}

void RBT::inorder_traversal() {
    inorder(root);
    std::cout << std::endl;
}

void RBT::preorder(Node* node) {
    if (node == nullptr) return;
    std::cout << node->key << " ";
    preorder(node->left);
    preorder(node->right);
}

void RBT::preorder_traversal() {
    preorder(root);
    std::cout << std::endl;
}

void RBT::postorder(Node* node) {
    if (node == nullptr) return;
    postorder(node->left);
    postorder(node->right);
    std::cout << node->key << " ";
}

void RBT::postorder_traversal() {
    postorder(root);
    std::cout << std::endl;
}

void RBT::leftRotate(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    if (y->left != nullptr) {
        y->left->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
        root = y;
    } else if (x == x->parent->left) {
        x->parent->left = y;
    } else {
        x->parent->right = y;
    }
    y->left = x;
    x->parent = y;
}

void RBT::rightRotate(Node* x) {
    Node* y = x->left;
    x->left = y->right;
    if (y->right != nullptr) {
        y->right->parent = x;
    }
    y->parent = x->parent;
    if (x->parent == nullptr) {
        root = y;
    } else if (x == x->parent->right) {
        x->parent->right = y;
    } else {
        x->parent->left = y;
    }
    y->right = x;
    x->parent = y;
}

void RBT::insertFix(Node* z) {
    while (z->parent != nullptr && z->parent->color == RED) {
        if (z->parent == z->parent->parent->left) {
            Node* y = z->parent->parent->right;
            if (y != nullptr && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->right) {
                    z = z->parent;
                    leftRotate(z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                rightRotate(z->parent->parent);
            }
        } else {
            Node* y = z->parent->parent->left;
            if (y != nullptr && y->color == RED) {
                z->parent->color = BLACK;
                y->color = BLACK;
                z->parent->parent->color = RED;
                z = z->parent->parent;
            } else {
                if (z == z->parent->left) {
                    z = z->parent;
                    rightRotate(z);
                }
                z->parent->color = BLACK;
                z->parent->parent->color = RED;
                leftRotate(z->parent->parent);
            }
        }
    }
    root->color = BLACK;
}

void RBT::removeFix(Node* x) {
    while (x != root && x->color == BLACK) {
        if (x == x->parent->left) {
            Node* w = x->parent->right;
            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                leftRotate(x->parent);
                w = x->parent->right;
            }
            if (w->left->color == BLACK && w->right->color == BLACK) {
                w->color = RED;
                x = x->parent;
            } else {
                if (w->right->color == BLACK) {
                    w->left->color = BLACK;
                    w->color = RED;
                    rightRotate(w);
                    w = x->parent->right;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->right->color = BLACK;
                leftRotate(x->parent);
                x = root;
            }
        } else {
            Node* w = x->parent->left;
            if (w->color == RED) {
                w->color = BLACK;
                x->parent->color = RED;
                rightRotate(x->parent);
                w = x->parent->left;
            }
            if (w->left->color == BLACK && w->right->color == BLACK) {
                w->color = RED;
                x = x->parent;
            } else {
                if (w->left->color == BLACK) {
                    w->right->color = BLACK;
                    w->color = RED;
                    leftRotate(w);
                    w = x->parent->left;
                }
                w->color = x->parent->color;
                x->parent->color = BLACK;
                w->left->color = BLACK;
                rightRotate(x->parent);
                x = root;
            }
        }
    }
    x->color = BLACK;
}

void RBT::transplant(Node* u, Node* v) {
    if (u->parent == nullptr) {
        root = v;
    } else if (u == u->parent->left) {
        u->parent->left = v;
    } else {
        u->parent->right = v;
    }
    if (v != nullptr) {
        v->parent = u->parent;
    }
}
