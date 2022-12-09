#include <iostream>


void printRotations(int *xs, size_t len) {
	for (size_t i = 0; i < len; i ++) {
		for (size_t j = i; j < i + len; j ++) {
			std::cout << xs[j % len] << ' ';
		}
		std::cout << std::endl;
	}

}

int main() {
	int xs[] = {1, 2, 3, 4};
	printRotations(xs, 4);
	return 0;
}
