#include <iostream>


int main() {
    double a = 0.1, b = 0.2;
    double c = a + b;

    std::cout << "Floating-point precision is " << std::cout.precision() << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;

    std::cout.precision(100);
    std::cout << "Floating-point precision is now " << std::cout.precision() << std::endl;
    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "c = " << c << std::endl;
}
