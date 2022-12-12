#include <iostream>
#include <climits>
#include <cassert>


void countsort(unsigned short * const arr, const size_t len) {
	size_t counts[USHRT_MAX]{};

	for (size_t i = 0; i < len; i++) {
		counts[arr[i]]++;
	}

	size_t idx = 0;
	for (size_t i = 0; i < USHRT_MAX; i++) {
		for (size_t j = 0; j < counts[i]; j++) {
			arr[idx] = i;
			idx++;
		}
	}

	assert(idx == len);
}

void printArray(unsigned short * const arr, const size_t len) {
	for (size_t i = 0; i < len; i++) {
		std::cout << arr[i] << ' ';
	}
	std::cout << std::endl;
}

int main() {
	unsigned short xs[]{9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
	countsort(xs, 10);
	printArray(xs, 10);

	return 0;
}
