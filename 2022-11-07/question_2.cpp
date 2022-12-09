#include <iostream>


int main() {
	char c = 'c';
	void *ptr = &c;

	std::cout << ptr << std::endl;
	std::cout << ptr + 1 << std::endl;
	std::cout << *ptr << std::endl;

	return 0;
}
