#include <iostream>


int main() {
	std::cout << "Enter a number: ";

	int n;
	std::cin >> n;

	int s = n * (n + 1) / 2;
	std::cout << "Sum = " << s << std::endl;

	return 0;
}
