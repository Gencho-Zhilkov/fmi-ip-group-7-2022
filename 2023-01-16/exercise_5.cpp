#include <iostream>
#include <cassert>

void partition(int *start, int *end, int* &left, int* &right) {
	// After partition all elements in [start .. left) are < pivot,
	// all elements in [left .. right) are == pivot, and
	// all elements in [right .. end) are > pivot
	// More efficient implementations do exist, but this one is the
	// simplest one conceptually that I could think of. Unfortunatelly,
	// beside not being optimal, this sort is not stable either.
	assert(end - start > 1);

	const int *mid = start + (end - start) / 2;
	const int pivot = *mid;

	left = right = start;

	for (int *ptr = start; ptr < end; ptr++) {
		const int val = *ptr;
		if (val < pivot) {
			*ptr = *right;
			*right = *left;
			*left = val;
			left++;
			right++;
		} else if (val == pivot) {
			*ptr = *right;
			*right = val;
			right++;
		}
	}
}

void quicksort(int *start, int *end) {
	assert(end >= start);
	if (end - start <= 1) {
		return;
	}

	int *left, *right;
	partition(start, end, left, right);

	quicksort(start, left);
	quicksort(right, end);
}

void quicksort(int xs[], size_t len) {
	quicksort(xs, xs + len);
}

void printArray(int xs[], size_t len) {
	for (size_t i = 0; i < len; i ++) {
		std::cout << xs[i] << ' ';
	}
	std::cout << std::endl;
}

int main() {
	size_t n;
	std::cout << "Enter number of elements: ";
	std::cin >> n;
	int *xs = new int[n];
	for (size_t i = 0; i < n; i ++) {
		std::cin >> xs[i];
	}

	quicksort(xs, n);
	printArray(xs, n);

	return 0;
}
