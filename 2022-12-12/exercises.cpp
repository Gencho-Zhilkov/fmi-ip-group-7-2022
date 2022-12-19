#include <iostream>

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


int main() {
	std::cout << std::boolalpha;

	unsigned n = 0;
	bitSet(n, 2);
	std::cout << n << ", isPow2: " << isPow2(n) << std::endl;

	bitFlip(n, 3);
	std::cout << n << ", isPow2: " << isPow2(n) << std::endl;

	bitClear(n, 2);
	std::cout << n << ", isPow2: " << isPow2(n) << std::endl;

	std::cout << isPangram("Once upon a time in the west") << std::endl;
	std::cout << isPangram("The quick brown fox jumps over the lazy dog.") << std::endl;

	return 0;
}
