#include <iostream>

const int DIGITS[] = {2, 3, 5, 7};
const int N = 4;

int convertTo2357(int n, int k) {
	// Идея: итерираме цифрите на n в 4-ична бройна система
	// и ги мап-ваме: 0 -> 2, 1 -> 3, 2 -> 5, 3 -> 7.
	int res = 0;
	for (int i = 0, m = 1; i < k; i++, m *= 10) {
		const int d = n % N;
		res += DIGITS[d] * m;
		n /= N;
	}

	return res;
}


int main() {
	int n;
	do {
		std::cout << "Enter a positive number: ";
		std::cin >> n;
	} while(n <= 0);

	for (int i = 0, k = 1, z = N; i < n; i ++) {
		// Идея:   имаме N^1=4  едно-цифрени,
		// последвани от N^2=16 дву-цифрени,
		// последвани от N^3=64 3-цифрени,
		// и т.н...
		if (i == z) {
			// тук минаваме от k към (k+1)-цифрени числа
			i = 0;
			k ++;
			n -= z;
			z *= N;
		}
		std::cout << convertTo2357(i, k) << std::endl;
	}
	return 0;
}
