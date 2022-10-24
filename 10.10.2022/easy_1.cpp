#include <iostream>


int main() {
	int a, b;
	std::cout << "Enter two numbers: ";
	std::cin >> a >> b;

	int max = (a > b) ? a : b;
	std::cout << max << std::endl;

	return 0;
}
