#include <iostream>

void foo(int x) {
	std::cout << x + 1 << std::endl;
}

void foo(double x) {
	std::cout << 2 * x << std::endl;
}

int main() {
	foo(5);
	foo(3.1415);

	return 0;
}
