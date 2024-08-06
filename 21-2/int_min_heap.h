#ifndef INT_MIN_HEAP_H
#define INT_MIN_HEAP_H

#include <iostream>
#include<algorithm>
#include <sstream>
// integer minimum heap with PQ 
class intMinHeap{
public:
  intMinHeap(int _capacity){
    size =0;
    capacity = _capacity;
    A = new int[_capacity];

  }  // empty heap wth this capacity
  ~intMinHeap(){ delete[] A; }  // clean up allocated memory  
  std::pair<int *, int> heapsort(){
    int *B = A;
    A = new int[size];

    int _size = size;
    
    std::copy_n(B, size, A);
    
    for(int i = size-1; i>0; i--){
      std::swap(A[0],A[i]);
      size--;
      heapify(0);
    }
    size = _size;
    auto ret = std::make_pair(A, size);
    A = B;
    return ret;
  }  // return sorted array and size from heap

  std::string toString(){
    std::stringstream ss;
    for(int i =0; i < size; i++){
      ss << A[i] << " ";
    }
    return ss.str();
  }  

  bool heapinsert(int val){
    //bound check
    if(isFull()){
      return false;
    }
    size++;
    A[size - 1] = val + 1;
    decreasekey(size-1,val);
    return true;
  } // add element to heap; return success


  // min functions should return 0 in empty heaps 
  int minimum(){

    if(isEmpty()){
      throw std::domain_error("Heap is empty");
    }
    return A[0];
  }  // return value of A[root]
  
  int extractmin(){
    int min = A[0];
    A[0] = A[size-1];
    size--;
    heapify(0);
    
    return min;
  } // return and remove A[root]
  
  void decreasekey(int i, int k){
    if(i > size || A[i] < k ){
      return;
    }
    A[i] = k;
    while(i > 0 && A[parent(i)] > A[i]){
      std::swap(A[i],A[parent(i)]);
      i = parent(i);
    }
  }  // A[i] decreased to k
  
  bool isEmpty(){return size==0;}
  bool isFull(){return size == capacity;}
  int getSize(){return size;}

   

private:
  int minOf3(int i, int j, int k){
     int min_ind = i;
     if (j < size && A[j] < A[min_ind]){
      min_ind = j;
     }
     if(k < size && A[k] < A[min_ind]){
      min_ind = k;
     }
    return min_ind;
  } // with bounds check!


  int left(int i){
     return 2 * i + 1;
  }
  int right(int i){
    return 2 * i + 2;
  }
  int parent(int i){
    return (i-1)/2;
  }	

  void buildheap(){
    for(int i = size/2 -1; i >=0; i--){
        heapify(i);
    }
  }  // convert array to a heap


  void heapify(int i){
    int n = minOf3(i,left(i),right(i));

    if(n != i){
        std::swap(A[i],A[n]);
        heapify(n);
    }
  }  // heapify at position i  


  int *A;  // array of integers - data
  int capacity; // size of array A
  int size; // data size in array
  

 };

 #endif