#include <iostream>
#include <cstring>
#include <cassert>


/* Задача 1 */
void bitSet(unsigned &n, unsigned pos) {
	n |= (1u << pos);
}

void bitClear(unsigned &n, unsigned pos) {
	n &= ~(1u << pos);
}

void bitFlip(unsigned &n, unsigned pos) {
	n ^= (1u << pos);
}

bool bitGet(unsigned n, unsigned pos) {
	return (n >> pos) & 1;
}

unsigned bitMask(unsigned count) {
	return (1u << count) - 1;
}

/* Задача 2 */
bool isPow2(const unsigned n) {
	return (n & (n - 1)) == 0;
}

/* Задача 3 */
bool isPangram(const char * const str) {
	unsigned letters = 0;
	for (size_t i = 0; str[i] != '\0'; i++) {
		const char c = str[i];
		if ('a' <= c && c <= 'z') {
			bitSet(letters, c - 'a');
		} else if ('A' <= c && c <= 'Z') {
			bitSet(letters, c - 'A');
		}
	}
	return letters == bitMask(26);
}

/* Задача 4 */
// Use an `unsigned char` so that the right-most
// (sign) bit is not treated differently!
#include <bitset>

size_t countLeadingOnes(unsigned char c) {
	size_t res = 0;
	while(c & 0b10000000) {
		c <<= 1;
		res++;
	}
	return res;
}

size_t strlen_UTF8(const char * str) {
	size_t len = 0;
	while (*str != '\0') {
		const size_t n = countLeadingOnes(*str);
		assert(n != 1); // Impossible according to standard!
		str += n ? n : 1;
		len ++;
	}
	return len;
}

/* Задача 5 */
unsigned countSetBits(unsigned n) {
	// This function operates by looping over the set bits of `n`,
	// counting the number of iterations, and unsetting (clearing)
	// the left-most bit at each iteration. The number of iterations,
	// thus, is equal to the number of set bits of `n`.
	unsigned res = 0;
	while (n != 0) {
		res ++;		// Increase number of iterations by one
		n &= n - 1;	// Clear the left-most bit of `n`.
	}
	return res;
}

unsigned countTrailingZeros(unsigned n) {
	unsigned res = 0;
	while ((n & 0x1) == 0) {	// Check if left-most bit is `0`
		res ++;
		n >>= 1;
	}
	return res;
}

unsigned countLeadingZeros(unsigned n) {
	unsigned res = 0;
	while ((int)n > 0) {	// Check if right-most bit is `0`
		res ++;
		n <<= 1;
	}
	return res;
}
// N.B. The above solutions were chosen for clarity, not efficiency!
// You can find many smarter/more efficient algorithms here:
// https://graphics.stanford.edu/~seander/bithacks.html


int main() {
	std::cout << std::boolalpha;

	/* Задача 1 */
	unsigned n = 0;
	bitSet(n, 2);
	std::cout << n << std::endl;

	bitFlip(n, 3);
	std::cout << n << std::endl;

	bitClear(n, 2);
	std::cout << n << std::endl;

	/* Задача 2 */
	for (auto n: {1, 2, 3, 4, 5, 8, 15, 16, 17, 25, 32, 37, 128, 1024}) {
		std::cout << "isPow2(" << n << ") = " << isPow2(n) << std::endl;
	}

	/* Задача 3 */
	std::cout << isPangram("Once upon a time in the west") << std::endl;
	std::cout << isPangram("The quick brown fox jumps over the lazy dog.") << std::endl;

	/* Задача 4 */
	for (auto s: {"", "Mamma mia!", "Мила мамо!", "你好"}) {
		std::cout << "s = \"" << s << "\""
				<< ", strlen = " << strlen(s)
				<< ", strlen_UTF8 = " << strlen_UTF8(s)
				<< std::endl;
	}

	/* Задача 5 */
	std::cout << countSetBits(0xa) << std::endl;
	std::cout << countSetBits(0xffff) << std::endl;

	std::cout << countTrailingZeros(0x1) << std::endl;
	std::cout << countTrailingZeros(0x100) << std::endl;

	std::cout << countLeadingZeros(0x1) << std::endl;
	std::cout << countLeadingZeros(0x100) << std::endl;

	return 0;
}
