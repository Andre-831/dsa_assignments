/*
Andre Ballesteros
aballest@pengo
dreb1204@gmail.com
linked_list.h
Programming Assingment #1, linked lists review and stacks
*/
#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <initializer_list>
#include <iostream>
#include <string>

template <typename T>
class LinkedList {
  struct Node;

 public:
  LinkedList() {}

  //  Constructs a list with a copy of each of the elements in init_list, in the
  //  same order.
  LinkedList(std::initializer_list<T> init_list) {
    for (const T& val : init_list) this->insert_back(val);
  }
  /** Destroys each of the contained elements, and deallocates all memory
   * allocated by this list. */
  ~LinkedList() {
    while (size_) {
      remove_front();
    }
  }

  // Constructs a container with a copy of each of the elements in another, in
  // the same order.
  LinkedList(const LinkedList<T>& another) { this->operator=(another); }

  T& back() const {
    if (this->size_ == 0) {
      throw std::domain_error("list is empty");
    }
    return this->tail_->data;
  }

  bool empty() const {
    if (this->size_ == 0) {
      return true;
    } else {
      return false;
    }
  }
//front of list
  T& front() const {
    if (this->size_ == 0) {
      throw std::domain_error("list is empty");
    }
    return this->head_->data;
  }
//not used
  bool operator!=(const LinkedList<T>& another) {
    if (this->size_ == another.size()) {
      for (Node *cur = this->head_, *another_cur = another.head_; cur;
           cur = cur->next, another_cur = another_cur->next) {
        if (cur->data != another_cur->data) {
          return true;
        }
      }
      return false;
    }
    return true;
  }

  LinkedList& operator=(const LinkedList<T>& another) {
    Node* cur = head_;
    while (cur) {
      this->remove_back();
      cur = head_;
    }

    Node* temp = another.head_;
    while (temp) {
      this->insert_back(temp->data);
      temp = temp->next;
    }
    return *this;
  }

  LinkedList& operator=(std::initializer_list<T> init_list) {
    Node* cur = head_;
    while (cur) {
      this->remove_front();
      cur = head_;
    }
    for (const T& val : init_list) this->insert_back(val);

    return *this;
  }
//not used 
  bool operator==(const LinkedList<T>& another) {
    return !(this->operator!=(another));
  }
//remove val from back
  void remove_back() {
    Node* tail_copy = this->tail_;
    if (this->size_ == 0) {
      throw std::domain_error("list is empty");
    } else if (this->size_ == 1) {
      this->head_ = this->tail_ = nullptr;
      delete tail_copy;
      this->size_ = 0;
    } else {
      this->tail_ = this->tail_->prev;
      this->tail_->next = nullptr;
      delete tail_copy;
      --this->size_;
    }
  }
//remove val from front 
  void remove_front() {
    Node* head_copy = this->head_;
    if (this->size_ == 0) {
      throw std::domain_error("list is empty");
    } else if (this->size_ == 1) {
      this->head_ = this->tail_ = nullptr;
      delete head_copy;
      this->size_ = 0;
    } else {
      this->head_ = this->head_->next;
      this->head_->prev = nullptr;
      delete head_copy;
      --this->size_;
    }
  }
//insert val from back
  void insert_back(T val) {
    Node* new_node = new Node{val};
    if (this->size_ == 0) {
      this->head_ = this->tail_ = new_node;
    } else {
      this->tail_->next = new_node;
      new_node->prev = this->tail_;
      this->tail_ = new_node;
    }
    ++this->size_;
  }
//insert val from front
  void insert_front(T val) {
    Node* new_node =
        new Node{val};  // Must eventually be deleted in the destructor!
    if (this->size_ == 0) {
      this->head_ = this->tail_ = new_node;
    } else {
      new_node->next = this->head_;
      this->head_->prev = new_node;
      this->head_ = new_node;
    }
    ++this->size_;
  }
//remove a val 
  void remove(const T& val) {
    Node* cur = this->head_;

    while (cur) {
      Node* next = cur->next;

      if (cur->data == val) {
        if (cur == this->head_) {
          this->remove_front();
        } else if (cur == this->tail_) {
          this->remove_back();
        } else {
          Node* temp = cur;
          cur->prev->next = cur->next;
          cur->next->prev = cur->prev;
          cur = cur->next;
          delete temp;
          --size_;
          continue;
        }
      }
      cur = next;
    }
  }
//not used
  void resize(std::size_t n) {
    if (n == this->size_) {
      return;
    } else if (n < this->size_) {
      while (n < this->size_) {
        this->remove_back();
      }
    } else {
      auto last = this->tail_->data;
      while (n > this->size_) {
        this->insert_back(last);
      }
    }
  }
//not used
  void resize(std::size_t n, const T& fill_value) {
    if (n == this->size_) {
      return;
    } else if (n < this->size_) {
      while (n < this->size_) {
        this->remove_back();
      }
    } else {
      while (n > size_) {
        this->insert_back(fill_value);
      }
    }
  }
//not used 
  void reverse() {
    if (this->size_ < 2) {
      return;
    }
    Node* temp = head_->next;
    tail_ = head_;
    tail_->next = nullptr;
    while (temp) {
      Node* next = temp->next;
      head_->prev = temp;
      temp->next = head_;
      head_ = temp;
      head_->prev = nullptr;
      temp = next;
    }
  }
//size of list 
  std::size_t size() const {
    Node* cur = this->head_;

    std::size_t count = 0;

    while (cur) {
      ++count;
      cur = cur->next;
    }
    return count;
  }
  void clear() {
    if (size_ == 0) {
      return;
    }
    while (head_) {
      this->remove_back();
    }
  }
//not used 
  void unique() {
    if (size_ < 2) {
      return;
    }
    Node* cur = head_;

    while (cur) {
      Node* next = cur->next;
      while (next->data == cur->data) {
        if (next == this->tail_) {
          this->remove_back();
          break;
        } else {
          Node* temp = next;
          next->prev->next = next->next;
          next->next->prev = next->prev;
          next = cur->next;
          delete temp;
          --size_;
          continue;
        }
      }
      cur = cur->next;
    }
  }

  friend std::ostream& operator<<(std::ostream& out,
                                  const LinkedList<T>& list) {
    if (list.empty()) {
      out << "[]";
      return out;
    }
    out << "[";
    for (Node* t = list.head_; t != list.tail_; t = t->next) {
      out << t->data << ", ";
    }
    out << list.tail_->data << "]";
    return out;
  }

  // Deletes all values in this list.

 private:
  struct Node {
    // Constructor(s)?
    Node(const T &val){
      data = val;
    }
    // Other member functions?
    T data;  // Actual value for list element
    Node* next = nullptr;
    Node* prev = nullptr;
  };
  Node* head_ = nullptr;
  Node* tail_ = nullptr;
  std::size_t size_ = 0;
};

#endif  // LINKED_LIST_H_