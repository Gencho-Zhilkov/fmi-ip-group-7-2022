#include <iostream>
#include <cassert>


bool isAlpha(char c) {
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

const char *lstrip(const char *s) {
	while (*s != '\0' && !isAlpha(*s)) {
		s ++;
	}
	return s;
}

const char *eatWord(const char *s) {
	while (*s != '\0' && isAlpha(*s)) {
		s ++;
	}
	return s;
}

char *longestWord(const char *s) {
	const char *maxWord = nullptr;
	size_t maxLen = 0;

	while(*s != '\0') {
		const char *wordStart = lstrip(s);
		const char *wordEnd = eatWord(wordStart);
		assert(wordStart <= wordEnd);
		const size_t wordLen = wordEnd - wordStart;
		if (wordLen > maxLen) {
			maxLen = wordLen;
			maxWord = wordStart;
		}
		s = wordEnd;
	}

	// Allocate mem & copy longest word.
	char *res = new char[maxLen + 1];
	for(size_t i = 0; i < maxLen; i++) {
		res[i] = maxWord[i];
	}
	res[maxLen] = '\0';
	return res;
}

int main() {
	const char *s = "Lorem ipsum dolor sit amet, consectetur adipiscing elit  ";
	const char *w = longestWord(s);
	std::cout << w << std::endl;
	delete[] w;
	return 0;
}
