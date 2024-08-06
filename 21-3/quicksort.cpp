#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

/*
Programming Assingment #3, quicksort


this file is to demonstrate Lomuto quicksort
reads ints and adds them to vector correctly as input and prints them sorted

program compiles and runs
tested with no words, nothing printed which is correct
tested with a few words, they printed out correctly
tested with 1 million strings, they printed/sorted correctly



*/


//vector A,  p leftmost index, r rightmost index
//quicksort using Lomutos method

int Partition(std::vector<int>& A, int p, int r);
int med_of_3(std::vector<int>& A, int p, int r);
void Lomuto_QuickSort(std::vector<int>& A, int p, int r);

//extra credit hoares method
int Hoare_Partition(std::vector<int>& A, int p, int r);
void Hoare_QuickSort(std::vector<int>& A, int p, int r);


const int MO3_CONST = 5;
const int HOARE_CONST = 10;


void Lomuto_QuickSort(std::vector<int>& A, int p, int r){

    if(p < r){
        int q = Partition(A,p,r);
        Lomuto_QuickSort(A,p,q-1); //dont "look ahead"
        Lomuto_QuickSort(A,q+1,r);

    }
}


int Partition(std::vector<int>& A, int p, int r){
    

    if(r-p + 1 > MO3_CONST){
        int med = med_of_3(A,p,r);
        std::swap(A[med],A[r]);
       
    }

    int x = A[r]; //select pivot
    int i = p-1; //boundary of "less than x region", initially our of bounds
    for(int j = p; j < r; j++){
        if(A[j] < x){
            i++;
            std::swap(A[i],A[j]);
        }
    }
    std::swap(A[i+1], A[r]);
    return i + 1;
}

int med_of_3(std::vector<int>& A, int p, int r){
    //change this
    int mid = (p + r) / 2;
    if(A[p] > A[r]){
        std::swap(A[p],A[r]);
    }
    if(A[p] > A[mid]){
        std::swap(A[p],A[mid]);
    }
    if(A[r] < A[mid]){
        std::swap(A[r],A[mid]);
    }
    return mid;
}

//Hoares method if time 

int Hoare_Partition(std::vector<int>& A, int p, int r){
     if(r-p + 1 > HOARE_CONST){
        int med = med_of_3(A,p,r);
        std::swap(A[med],A[r]);
    }
    int x = A[p];
    int i = p - 1;
    int j = r + 1;

    while(true){
        do{i = i + 1;}while(A[i] < x);
        do{j = j - 1;}while(A[j] > x);
        if(i >= j) {return j;}
        std::swap(A[i], A[j]);
    }
}
//adjust quicksort for hoares 
void Hoare_QuickSort(std::vector<int>& A, int p, int r){

    if(p < r){
        int q = Hoare_Partition(A,p,r);
        Hoare_QuickSort(A,p,q); 
        Hoare_QuickSort(A,q+1,r);

    }
}



int main(int argc, char**argv){

    bool lomuto = true;
    if(argc> 1 && std::string(argv[1]) == "-h"){
        lomuto = false;
    }
    
    int input = 0;
    std::vector<int>vect;


    while(std::cin >> input){
        vect.push_back(input);
    }
    if(lomuto){
    Lomuto_QuickSort(vect, 0, vect.size() -1);
    }
    else{
        Hoare_QuickSort(vect, 0, vect.size() -1);
    }
    std::cout << "sorted array" << std::endl;

    for(int i : vect){
        std::cout << std::setfill('0') << std::setw(9) << i << std::endl;
    }
    

}
