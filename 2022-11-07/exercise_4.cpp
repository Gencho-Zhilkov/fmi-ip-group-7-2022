#include <iostream>

template <typename T>
void printArray(const T * const xs, const size_t size) {
	for (size_t i = 0; i < size; i++) {
		std::cout << xs[i] << ' ';
	}
	std::cout << std::endl;
}

template <typename T>
void swap(T * const x, T * const y) {
	T tmp = *x;
	*x = *y;
	*y = tmp;
}

bool isPrime(const int n) {
	for (int i = 2; i <= n / 2; i ++) {
		if (n % i == 0) {
			return false;
		}
	}
	return (n > 1);
}

size_t primePartition(int * const xs, const size_t size) {
	size_t count = 0;
	for (size_t i = 0; i < size; i++) {
		if(isPrime(xs[i])) {
			swap(&xs[i], &xs[count]);
			count++;
		}
	}
	return count;
}

int main() {
	int xs[] = {2, 3, 8, 12, 5, 6, 17, 1};
	const int size = sizeof(xs) / sizeof(xs[0]);

	std::cout << primePartition(xs, size) << std::endl;
	printArray(xs, size);

	return 0;
}
