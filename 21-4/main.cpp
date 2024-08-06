#include <iostream>
#include <iomanip>
#include <vector>
#include <list>
#include <cmath>

/*
Programming Assingment #4, RadixBucket sort hybrid


this file is to demonstrate a hybrid of radix and bucket sort
reads ints and adds them correctly as input and prints them sorted

program compiles and runs
tested with no words, nothing printed which is correct
tested with a few words, they printed out correctly
tested with 1000 strings, they printed/sorted correctly
tested with 1 million strings sorted and unsorted, they printed/sorted correctly


*/


//d is always 9 
//k is range of each digit 

int get_num(int index,std::vector<int>& A);

void Radix_Bucket_sort(std::vector<int>& A, int n, int d){
    std::list<int> bucket[10];
    for(int i =1; i <= d; i++){
    
        for(int j = 0; j < n; j++){
            int r = (A[j] / static_cast<int>(pow(10, i-1))) % 10; //r = ith digit of A[j]
            bucket[r].push_back(A[j]);
        }
        
        //bucket[j] into A in order
        A.clear();
        for(int j = 0; j < 10; j++){
            for(int num : bucket[j]){
                A.push_back(num);
            }
            bucket[j].clear();
            
        }
    }

}



int main(){
    int input = 0;
    std::vector<int>vect;
    int d = 9;
    
   
    while(std::cin >> input){
        vect.push_back(input);
    }
    int n = vect.size();
     Radix_Bucket_sort(vect, n, d);

    for(int i : vect){
        std::cout << std::setfill('0') << std::setw(9) << i << std::endl;
    }
    return 0;
}