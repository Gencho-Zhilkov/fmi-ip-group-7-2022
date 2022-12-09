#include <iostream>


bool isPrefix(int *xs, int *ys, size_t xlen) {
	for (size_t i = 0; i < xlen; i++) {
		if (xs[i] != ys[i]) {
			return false;
		}
	}
	return true;
}

bool isSubarray(int *xs, size_t xlen, int *ys, size_t ylen) {
	for(size_t i = 0; i + xlen <= ylen; i++) {
		if (isPrefix(xs, &ys[i], xlen)) {
			return true;
		}
	}
	return false;
}


int main() {
	int xs[] = {1, 2, 3};
	int ys[] = {2, 3, 1, 2, 3, 5};
	int zs[] = {2, 3, 1, 2, 5, 3};

	std::cout << std::boolalpha;
	std::cout << isSubarray(xs, 3, xs, 3) << std::endl;
	std::cout << isSubarray(xs, 3, ys, 5) << std::endl;
	std::cout << isSubarray(xs, 3, zs, 5) << std::endl;
	return 0;
}
