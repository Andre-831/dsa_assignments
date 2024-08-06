 #include <iostream> 
 #include <fstream> 
 #include <sstream> 
 #include <string> 
 #include <exception>
 #include "hashTable.h"
/*
Programming Assingment #5, Hashtable 


this file is to demonstrate a hashtable
prompt user with options to interact with the hashtable
(1)load (2)insert (3)delete (4)search (5)clear (6)save (7)quit

program compiles and runs
tested loading a file with keys and values and it worked. Using this I also deleted,searched, inserted, and saved
tested by manually entering keys and values and tested the other options with it as well.
*/

class data : public record {
public:
    data(int _id, std::string _value) : id(_id), value(_value) {};
    virtual int getID() { return id; };
    virtual record *clone() { return new data(id, value); };
    std::string get_value() { return value; }
    virtual std::string to_string(){
        return std::to_string(id) + " " + value;
    }
private:
    int id = 0;
    std::string value;
};

int main(){ 
    hashTable table(17800); 
    int option = 0; 
    //int id = 0;
    std::string id;
    std::string filename; 
    std::string line;
    std::string value;
    std::ifstream inputfile;
    std::istringstream iss;
    std::ofstream outputfile;
    std::string input;
    

   

    while(option != 7){
        std::cout << "(1)load (2)insert (3)delete (4)search (5)clear (6)save (7)quit -- Your choice? ";
        std::getline(std::cin, input);
        try{
        option = std::stoi(input);
        }
        catch(std::exception& e){
            std::cout << "Invalid input." << std::endl;
            continue;
            }
        
        if(option == 1){ //option to read from a file for input
            std::cout << "read hash table - filename? ";
            std::getline(std::cin, filename);

            inputfile.open(filename);
            if(inputfile.is_open()){
                // Read the file line by line
                while(std::getline(inputfile, line)){
                    iss.clear();
                    iss.str(line);
                    iss >> id >> std::ws;
                    table.insert(new data(std::stoi(id), iss.str().substr(iss.tellg())));
                }
                inputfile.close();
            }
            }
          
        else if(option == 2){ //option 2 is to manually insert 
            std::cout << "input new record: " << std::endl;
            std::getline(std::cin,line);
            iss.str(line);
            iss >> id >> std::ws;
            value = iss.str().substr(iss.tellg());

            // new data record and insert it to hash table
            data* rec = new data(std::stoi(id), value);
            //record* copy = rec->clone();
            table.insert(rec);
       }
       else if(option == 3){ //deletes a record by giving the key
        std::cout << " delete record - key? ";
        std::getline(std::cin, id);
        int id_ = stoi(id);
        data* deleted_data = dynamic_cast<data*>(table.search(id_));
        
            if(deleted_data){
            table.delete_record(id_);
            std::cout << "delete: " << id << " " << deleted_data-> get_value() << std::endl;
            }
            else{
                std::cout << "Delete not found: " << id << std::endl;
        }

       }
       else if(option == 4){ //searches for a record 
            std::cout << "search for record - key? ";
            std::getline(std::cin, id);
            int id_ = stoi(id);
            data* found_data = dynamic_cast<data*>(table.search(id_));
            if(found_data){
                std::cout << "Found: " << id << " " << found_data ->get_value() << std::endl;
            }
            else{
                std::cout << "search not found: " << id << std::endl;
            }

       }
       else if(option == 5){ //clears hashtable
            std::cout << "clearing hash table." << std::endl;
            table.clear();
       }
       else if(option == 6){ //saves hashtable to a file
            std::cout << "write hash table - filename? ";
            std::getline(std::cin, filename);
            outputfile.open(filename);

            if(outputfile.is_open()){
                table.to_file(outputfile);
                outputfile.close();
            }

        }

    


    }
}
