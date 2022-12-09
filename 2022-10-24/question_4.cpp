#include <iostream>


int main() {
	int c = 5;
	if (c = 7) {
		int d = 3 + c++;
		int e = ++d + 1;
		std::cout << c << std::endl;
		std::cout << d << std::endl;
		std::cout << e << std::endl;
	}

	return 0;
}
