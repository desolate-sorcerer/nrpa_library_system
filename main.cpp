#include "menu.h"
#include <string>

int main() {
  User user("janez");
  Menu menu(user);
  menu.start();
}
