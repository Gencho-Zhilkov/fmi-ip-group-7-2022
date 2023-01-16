#include <iostream>

int fibs(int n) {
	if (n < 1) {
		return 0;
	} else if (n == 1) {
		return 1;
	} else {
		return fibs(n - 1) + fibs(n - 2);
	}
}

int main() {
	for (int i = 0; i < 10; i ++) {
		std::cout << i << ' ' << fibs(i) << std::endl;
	}
	return 0;
}
