#pragma once
#include "user.h"
#include <iostream>
#include <stdlib.h>
#include <string>
class Menu {
private:
  enum screen { MAIN = 1, BOOKS = 2, ADD = 3, QUIT = 4 };
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
    std::cout << "(4) exit\n";
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
  void clearScreen() { system("clear"); }
  void select() {
    char input;
    while (true) {
      std::cin >> input;
      if (input < '5' && input > '0')
        break;
      else
        std::cout << "option 1-4\n";
    }

    if (input == '1')
      setOption(MAIN);

    if (input == '2')
      setOption(BOOKS);

    if (input == '3')
      setOption(ADD);

    if (input == '4')
      setOption(QUIT);
  }
  void setOption(screen option) { this->option = option; }
};
