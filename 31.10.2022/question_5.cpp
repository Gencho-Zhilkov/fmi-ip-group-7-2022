#include <iostream>


int main() {
	int c = 5, d = 7, e = 2;
	int f = ++(e = c + d);

	std::cout << "e = " << e << ", f = " << f << std::endl;

	return 0;
}
