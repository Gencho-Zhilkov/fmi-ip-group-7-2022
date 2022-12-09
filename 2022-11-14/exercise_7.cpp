#include <iostream>


bool increasing(int *xs, size_t len) {
	for (size_t i = 1; i < len; i++) {
		if (xs[i-1] > xs[i]) {
			return false;
		}
	}
	return true;
}

int main() {
	std::cout << std::boolalpha;
	{
		int xs[] = {1, 2, 3, 4};
		std::cout << increasing(xs, 4) << std::endl;
	}
	{
		int xs[] = {1, 2, 2, 4};
		std::cout << increasing(xs, 4) << std::endl;
	}
	{
		int xs[] = {1, 3, 2, 5};
		std::cout << increasing(xs, 4) << std::endl;
	}
	return 0;
}
