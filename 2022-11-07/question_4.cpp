#include <iostream>

int foo(int i) {
	return i + 1;
}

int foo(int *ptr) {
	if (ptr == NULL) {
		return 42;
	}
	return ptr[0];
}


int main() {
	int i = 5;
	std::cout << foo(i) << std::endl;
	std::cout << foo(&i) << std::endl;
	std::cout << foo(NULL) << std::endl;

	return 0;
}
