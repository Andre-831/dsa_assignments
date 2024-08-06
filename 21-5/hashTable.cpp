 
#include "hashTable.h"
#include <iostream>
#include <list>
#include <fstream> 
#include <sstream> 
#include <string> 
 //this file has all function definitions

 hashTable::hashTable(int size) : m(size){
     // Initialize the hash table
    // Create a new dynamic array of linked lists with size 'size'
   table = new std::list<record*>[size];

  }
   hashTable::~hashTable(){ 
    clear();
   delete[] table;
   };

  void hashTable::insert(record *r){
    // int _hash = hash(r->getID());
    // table[_hash].push_back(r);
    record *r_copy = r->clone(); // Create a copy of the record to store in the hash table
    int _hash = hash(r_copy->getID());
    table[_hash].push_back(r_copy); // Add the copy of the record to the list at the calculated index
  }
  void hashTable::delete_record(int key){
    int _hash = hash(key);
    std::list<record*>&bucket = table[_hash];

    for(auto it = bucket.begin(); it != bucket.end(); ++it){
      if((*it)->getID() == key){
        delete *it;
       it = bucket.erase(it);
       return;
      }
    }
     //return nullptr;
  }
  
  record *hashTable::search(int key){ //search for record 
    record *found_record = find(key);

    if(found_record){
      return found_record->clone();
    }
    return nullptr;
  }

  record *hashTable::find(int key){ //find a record in hashtable
    int _hash = hash(key);
  std::list<record*>&bucket = table[_hash];
    for(record *r :bucket){
      if(r->getID() == key){
        return r;
      }
    }
    return nullptr;
  }

  int hashTable::hash(record *r){
    int key = r->getID();

    return (hash(key));

  } // hash value for record

  int hashTable::hash(int key){
    const double c = 0.61803398875;
   
    return (int) (m * ((c * key) - (int)(c * key)));
  } //hash value for key

  void hashTable::clear(){
    for(int i = 0; i < m ; i++){
      for(auto it = table[i].begin(); it != table[i].end(); ++it){
        delete(*it);
        *it = nullptr;
      }
      table[i].clear();
    }
  }

  void hashTable::to_file(std::ofstream& outputfile){ //write hashtable contents to a file
    for(int i = 0; i < m ; i++){
      for(auto it = table[i].begin(); it != table[i].end(); ++it){
        outputfile << (*it)->to_string() << std::endl;
      }
    }
  }
