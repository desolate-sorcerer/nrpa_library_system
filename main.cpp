#include "menu.h"
#include <string>

/*
*******Menu********
--lib
  user.h

--func
  izpise opcije
*******************

*****User**********
--lib
  book.h
  record.h

--func
  linked list z knjigami
*******************

*****book**********
--func
  node za linked list
*******************

*****record****
--func
  shrani node v records.txt
******************
*/

int main() {
  User user("janez");
  Menu menu(user);
  menu.start();
}
