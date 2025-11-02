#pragma once
#include "book.h"
#include <iomanip>
#include <iostream>
#include <string>
class User {
private:
  std::string name;
  Book *root;

public:
  User() {}
  User(std::string name) {
    this->name = name;
    root = nullptr;
  }
  ~User() {
    Book *temp = root;
    while (temp != nullptr) {
      Book *next = temp->getNext();
      delete temp;
      temp = next;
    }
  }

  std::string getName() { return name; }
  void setName(std::string name) { this->name = name; }

  void addBook(std::string naslov, std::string avtor) {
    Book *new_book = new Book(naslov, avtor);

    if (root == nullptr) {
      new_book->setId(1);
      root = new_book;
    } else {
      Book *temp = root;
      while (temp->getNext() != nullptr) {
        temp = temp->getNext();
      }
      temp->setNext(new_book);
      new_book->setPrev(temp);
      new_book->setId(temp->getId() + 1);
    }
  }
  void printBooks() {
    std::cout << "ID" << std::setw(24);
    std::cout << "AVTOR" << std::setw(22);
    std::cout << "NASLOV\n\n";
    Book *temp = root;
    while (temp != nullptr) {
      std::cout << temp->getId() << std::setw(20 + temp->getAvtor().size());
      std::cout << temp->getAvtor()
                << std::setw(20 - temp->getAvtor().size() +
                             temp->getNaslov().size());
      std::cout << temp->getNaslov() << "\n";
      temp = temp->getNext();
    }
  }
};
