#ifndef HASH_TABLE_H
#define HASH_TABLE_H


#include <iostream>
#include <list>

// abstract base class for data
//   also overload operator= if necessary
//   and/or copy constructor, destructor 
// clone method invokes copy constructor
// to make a copy of the object
class record{
public:
  virtual int getID() = 0; // or something similar 
  virtual record *clone() = 0; // or something similar
  // anything else that you think is appropriate 

  //turn record to string
  virtual std::string to_string() = 0;
  virtual ~record() = default;
};


class hashTable{

public:
  hashTable(int=100); // build a table
  void insert(record *); // insert copy of record
  void delete_record(int); // delete a record
  // return pointer to a copy of found record, or 0
  record *search(int); //return clone
  void clear();
  void to_file(std::ofstream& outputfile);
  ~hashTable(); //destructor
private:
  // find return value: some type of index
  record *find(int); // helper search fn
  int hash(record *); // hash value for record
  int hash(int); // hash value for key  
  const int m; // size of table
   std::list<record*> *table;// array of m lists that hold records
  // other members as desired
};



  

 #endif

