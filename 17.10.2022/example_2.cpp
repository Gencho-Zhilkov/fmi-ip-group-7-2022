#include <iostream>
#include <bitset>

int main() {
    //   a = 8,      b = 7,      c = 5
    char a = 0b1000, b = 0b0111, c = 0b0101;
    std::cout << "    a = " << std::bitset<8>(a) << std::endl;
    std::cout << "    b = " << std::bitset<8>(b) << std::endl;
    std::cout << "    c = " << std::bitset<8>(c) << std::endl;
    std::cout << std::endl;

    std::cout << "a & b = " << std::bitset<8>(a & b) << std::endl;
    std::cout << "a | b = " << std::bitset<8>(a | b) << std::endl;
    std::cout << "a ^ b = " << std::bitset<8>(a ^ b) << std::endl;
    std::cout << std::endl;

    std::cout << "b & c = " << std::bitset<8>(b & c) << std::endl;
    std::cout << "b | c = " << std::bitset<8>(b | c) << std::endl;
    std::cout << "b ^ c = " << std::bitset<8>(b ^ c) << std::endl;
    std::cout << std::endl;

    std::cout << "   ~a = " << std::bitset<8>(~a) << std::endl;
    std::cout << "   ~b = " << std::bitset<8>(~b) << std::endl;
    std::cout << "   ~c = " << std::bitset<8>(~c) << std::endl;
}
