#pragma once
#include <string>
class Book {
private:
  int id;
  Book *next;
  Book *prev;
  std::string naslov;
  std::string avtor;

public:
  Book() { prev = next = nullptr; };
  Book(std::string naslov, std::string avtor) {
    this->naslov = naslov;
    this->avtor = avtor;
    prev = next = nullptr;
  }
  ~Book() {}
  void setNext(Book *next) { this->next = next; }
  void setPrev(Book *prev) { this->prev = prev; }
  void setId(int id) { this->id = id; }
  Book *getNext() { return next; }
  Book *getPrev() { return prev; }
  std::string getNaslov() { return naslov; }
  std::string getAvtor() { return avtor; }
  int getId() { return id; }
};
