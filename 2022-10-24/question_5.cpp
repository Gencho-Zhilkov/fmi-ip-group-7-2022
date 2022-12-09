#include <iostream>


int main() {
	int c = 5;
	int d = ++c + c++;
	std::cout << c << std::endl;
	std::cout << d << std::endl;

	return 0;
}
