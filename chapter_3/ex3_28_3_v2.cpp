#include <iostream>
int main()
{
    std::cout << "Please input a floating number: ";
    double floating_number;
    std::cin >> floating_number;
    int integer_part = static_cast<int>(floating_number);
    double decimal_part = floating_number - integer_part;
    std::cout << integer_part << std::endl
              << decimal_part << std::endl;
    return 0;
}