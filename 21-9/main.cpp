#include <iostream>
#include <vector>
#include <sstream>
#include <limits>
#include<string>
#include<tuple>
/*
Andre Ballesteros  0414799
extra credit assignment Floyd Warshall
this assignment demonstrates floyd warshall alrgorithm
I tested it with the sample input and both the distance matrix and parent matrix print
*/
void floyd_Warshall(std::vector<std::vector<int>>& distance, std::vector<std::vector<int>>& parents){
    int size = distance.size();

    int inf = std::numeric_limits<int>::max();

    for( int k = 0; k < size; k++){ //inmtermediate nodes
        
        for(int i = 0; i < size; i++){ //source nodes

            for(int j = 0; j < size; j++){ //destination nodes
                if(distance[i][k] != inf && distance[k][j] != inf && distance[i][k] + distance[k][j] < distance[i][j]){
                    // shorest path i to j
                    distance[i][j] = distance[i][k] + distance[k][j];

                    //update parent node of j
                    parents[i][j] = k + 1;
                }
            }
        }
    }
}

void print_matrix( std::vector<std::vector<int>>& matrix, char name){

    int size = matrix.size();

    std::cout << name << " ";
    for(int i = 1; i <= size; i++){
        std::cout << i << ": ";
    }
    std::cout << std::endl;

    // Print each row of the matrix
    for (int i = 0; i < size; i++) {
        std::cout << i + 1 << ": ";
        for (int j = 0; j < size; j++) {
            // If infinity/null, print .
            if (matrix[i][j] == std::numeric_limits<int>::max()) {
                std::cout << ".";
            } else {
                std::cout << matrix[i][j];
            }
            std::cout << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl; // blank line between matrices
}




int main(){
    std::string line;
    //  std::vector<std::vector<int>> parents;
    //  std::vector<std::vector<int>> distance;
    int max_size = 0;
    std::vector<std::tuple<int,int,int>>edges;
    
    while(std::getline(std::cin,line)){
        std::istringstream ss(line);
        char c_;

        int a,b,c;

        ss >> a >> c_;
        if(c_ == '-' || (c_ >='0' && c_ <= '9')){
            ss.unget();
        }
        ss >> b >> c_;
        if(c_ == '-' || (c_ >='0' && c_ <= '9')){
        
            ss.unget();
        }
        ss >> c;
        //ss >> a >> b >> c;

        max_size = std::max(max_size,std::max(a,b));
        edges.push_back(std::make_tuple(a,b,c));
       // std::cout << a << " " << b << " " << c << std::endl; 
    }

    std::vector<std::vector<int>> parents(max_size, std::vector<int>(max_size, -1));
    std::vector<std::vector<int>> distance(max_size, std::vector<int>(max_size, std::numeric_limits<int>::max()));
    
    for(int i = 0; i < max_size; i++){
        distance[i][i] = 0; //
    }

   for(auto x : edges){
        int a =  std::get<0>(x);
        int b = std::get<1>(x);
        int c = std::get<2>(x);
        distance[a-1][b-1] = c; //set distance from a to b to weight c
        parents[a-1][b-1] = a -1;
    }

    floyd_Warshall(distance, parents);

    print_matrix(distance, 'D');
    print_matrix(parents, 'P');

}


