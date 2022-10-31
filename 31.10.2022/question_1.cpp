#include <iostream>


int main() {
	int c = 5, d = 7;

	if (c < d) {
		int c = 10;
		d = c;
	}

	std::cout << "c = " << c << ", d = " << d << std::endl;

	return 0;
}
