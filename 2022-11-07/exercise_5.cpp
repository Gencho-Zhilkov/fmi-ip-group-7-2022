#include <cassert>
#include <iostream>


size_t nextRow(const int * const xs, const size_t offset, const size_t size) {
	const int x = xs[offset];
	for (size_t i = offset + 1; i < size; i++) {
		if (xs[i] != x) {
			return i;
		}
	}
	return size;
}

void longestRow(const int * const xs, const size_t size) {
	size_t offset = 0;
	size_t longestOffset = -1, longestLength = 0;

	while (offset < size) {
		const size_t nextOffset = nextRow(xs, offset, size);
		assert(nextOffset > offset);

		const size_t length = nextOffset - offset;
		if(length > longestLength) {
			longestOffset = offset;
			longestLength = length;
		}

		offset = nextOffset;
	}
	std::cout << "Longets row: start = " << longestOffset << ", len = " << longestLength << std::endl;
}

int main() {
	const int xs[] = {2, 2, 2, 3, 3, 5, 5, 5, 5, 1, 2, 3, 2, 2, 2, 3};
	const size_t size = sizeof(xs) / sizeof(xs[0]);
	longestRow(xs, size);
	return 0;
}
