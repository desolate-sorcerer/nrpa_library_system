#pragma once
#include <fstream>
#include <iostream>
#include <string>
class Record{
public:
    Record(){}
    ~Record(){}
    void addRecord(Book *book){
        std::fstream file("records.txt", std::ios::app);
        if(!file.is_open()){
            std::cout << "cant open file\n";
        }
        else{
            file << "id: " << book->getId() << std::endl;
            file << "\tnaslov: " << book->getNaslov() << std::endl;
            file << "\tavtor: " << book->getAvtor() << std::endl;
        }
        file.close();
    }
    void readReecord(){
        std::fstream file("records.txt");
        file.seekg(0);
        if(!file.is_open()){
            std::cout << "cant open file\n";
        }
        else{
            std::string s;
            while(std::getline(file, s)){
                std::cout << s << "\n";
            }
            file.close();
        }
    }
};
