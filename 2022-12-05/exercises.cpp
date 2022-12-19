#include <iostream>
#include <cassert>


/* Задача 1 */
bool isLower(const char c) {
	return c >= 'a' && c <= 'z';
}

bool isUpper(const char c) {
	return c >= 'A' && c <= 'Z';
}

bool isDigit(const char c) {
	return c >= '0' && c <= '9';
}

char toUpper(const char c) {
	return isLower(c) ? c - 'a' + 'A': c;
}

char toLower(const char c) {
	return isUpper(c) ? c - 'A' + 'a': c;
}

int toDigit(const char c) {
	assert(isDigit(c));
	return c - '0';
}


/* Задача 2 */
int atoiPrivate(const char * const str) {
	int res = 0;
	for(size_t i = 0; isDigit(str[i]); i++) {
		res = 10 * res + toDigit(str[i]);
	}
	return res;
}

int atoi(const char * const str) {
	assert(str != nullptr);

	switch (*str) {
		case '+':
			return atoiPrivate(str+1);
		case '-':
			return -atoiPrivate(str+1);
		default:
			return atoiPrivate(str);
	}
}


/* Задача 3 */
bool isPangram(const char * const str) {
	bool letters[26] = {};

	for (size_t i = 0; str[i] != '\0'; i++) {
		const char c = str[i];
		if (isUpper(c)) {
			letters[c - 'A'] = true;
		} else if (isLower(c)) {
			letters[c - 'a'] = true;
		}
	}

	for (size_t i = 0; i < 26; i++) {
		if (!letters[i]) {
			return false;
		}
	}
	return true;
}


int main() {
	std::cout << atoi("571") << std::endl;
	std::cout << atoi("-13") << std::endl;
	std::cout << atoi("3.1415") << std::endl;

	std::cout << std::boolalpha;
	std::cout << isPangram("Lorem ipsum dolor.") << std::endl;
	std::cout << isPangram("The quick brown fox jumps over the lazy dog.") << std::endl;

	return 0;
}
