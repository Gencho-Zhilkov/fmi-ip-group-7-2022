#include <iostream>


int main() {
	int a, b;
	std::cout << "Enter two numbers: ";
	std::cin >> a >> b;

	double mean = 0.5 * (a + b);
	std::cout << mean << std::endl;

	return 0;
}
