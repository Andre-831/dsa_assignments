#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include "segment_tree.h"

int main() {
    std::vector<int> data;
    segmentTree* tree = nullptr; // Pointer to manage segmentTree object

    std::string line;
    std::string option;
    int key = 0;
    int left, right, index, value;

    while (std::getline(std::cin, line)) {
        std::istringstream iss(line);
        iss >> option;

        if (option == "insert") {
            // Read the value to be inserted
            if (iss >> key) {
                data.push_back(key);
                // Rebuild the segment tree with updated data
                delete tree; // Clean up the old tree
                tree = new segmentTree(data);
                std::cout << "Inserted value: " << key << std::endl;
            } else {
                std::cout << "Invalid value for insert" << std::endl;
            }
        } 
        else if (option == "query") {
            // Read the range for the query
            if (iss >> left >> right) {
                if (tree != nullptr) {
                    std::cout << "Sum of range [" << left << ", " << right << "] : " << tree->query(left, right) << std::endl;
                }
            } else {
                std::cout << "Invalid range for query" << std::endl;
            }
        } 
        else if (option == "update") {
            // Read the index and value for the update
            if (iss >> index >> value) {
                if (index >= 0 && index < data.size()) {
                    data[index] = value;
                    // Rebuild the segment tree with updated data
                    delete tree; // Clean up the old tree
                    tree = new segmentTree(data);
                    std::cout << "Updated index " << index << " to value " << value << std::endl;
                } else {
                    std::cout << "Invalid index for update" << std::endl;
                }
            } else {
                std::cout << "Invalid index or value for update" << std::endl;
            }
        } 
        else if(option == "print"){
            if(tree!= nullptr){
                tree->print();
            }
        }
        else if (option == "exit") {
            break; // Exit the loop and end the program
        } 
        else {
            std::cout << "Unknown command" << std::endl;
        }
    }

    delete tree; // Clean up the segment tree before exiting

    return 0;
}

