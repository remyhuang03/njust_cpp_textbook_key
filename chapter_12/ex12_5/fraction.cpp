#include "fraction.h"

#include <iostream>

int main() {
  Fraction f1(3, 6);
  Fraction f2(2, 4);
  std::cout << static_cast<double>(f1) << " + " << static_cast<double>(f2)
            << " = " << static_cast<double>(f1 + f2) << std::endl;
  std::cout << std::boolalpha << (f1 == f2) << std::endl;
  return 0;
}