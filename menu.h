#pragma once
#include "user.h"
#include <iostream>
#include <stdlib.h>
#include <string>
class Menu {
private:
  enum screen { MAIN = 1, BOOKS = 2, ADD = 3, RECORD = 4, QUIT = 5 };
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
      if (input < '6' && input > '0')
        break;
      else
        std::cout << "error: option 1-4\n";
    }

    if (input == '1')
      setOption(MAIN);

    if (input == '2')
      setOption(BOOKS);

    if (input == '3')
      setOption(ADD);

    if(input == '4')
        setOption(RECORD);

    if (input == '5')
      setOption(QUIT);
  }

  void printRecord(){
      user.getRecords();
  }

  void setOption(screen option) { this->option = option; }
  void clearScreen() { system("cls"); }
};
