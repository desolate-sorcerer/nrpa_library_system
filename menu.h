#pragma once
#include "user.h"
#include <iostream>
#include <stdlib.h>
#include <string>
class Menu {
private:
  enum screen { MAIN, BOOKS, ADD, RECORD, QUIT };
  screen option;
  bool exit;
  User user;

public:
  Menu(User user) {
    option = MAIN;
    exit = false;
    this->user = user;
  }
  ~Menu() {}
  void start() {
    while (!exit) {
      switch (option) {

      case MAIN:
        clearScreen();
        printMain();
        select();
        break;

      case BOOKS:
        clearScreen();
        printBooks();
        select();
        break;

      case ADD:
        clearScreen();
        addBooks();
        setOption(MAIN);
        break;

      case RECORD:
        clearScreen();
        printRecord();
        select();
        break;

      case QUIT:
        exit = true;
        break;
      }
    }
  }

  void printMain() {
    std::cout << "Main Menu\n";
    std::cout << "---------\n";
    std::cout << "(1) main menu\n";
    std::cout << "(2) print your library\n";
    std::cout << "(3) add book\n";
    std::cout << "(4) show records\n";
    std::cout << "(5) exit\n";
  }

  void printBooks() {
    std::cout << "Your Lybrary\n";
    std::cout << "------------\n";
    user.printBooks();
  }

  void addBooks() {
    std::cin.ignore();
    std::string naslov, avtor;

    std::cout << "naslov: ";
    getline(std::cin, naslov);

    std::cout << "avtor: ";
    getline(std::cin, avtor);

    user.addBook(naslov, avtor);
  }

  void select() {
    char input;
    while (true) {
      std::cin >> input;
      if (input >= '1' && input <= '5')
        break;
      else
        std::cout << "error: option 1-5\n";
    }

    switch (input) {
    case '1':
      setOption(MAIN);
      break;
    case '2':
      setOption(BOOKS);
      break;
    case '3':
      setOption(ADD);
      break;
    case '4':
      setOption(RECORD);
      break;
    case '5':
      setOption(QUIT);
      break;
    }
  }

  void printRecord() { user.getRecords(); }

  void setOption(screen option) { this->option = option; }
  void clearScreen() { system("clear"); }
};
