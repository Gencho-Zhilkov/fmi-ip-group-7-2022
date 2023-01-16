#include <iostream>

bool isAlpha(const char c) {
	return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
}

void alphaOnly_helper(char *src, char *dst) {
	if (*src == '\0') {
		*dst = '\0';
	} else if (isAlpha(*src)) {
		if(dst != src) {
			*dst = *src;
		}
		alphaOnly_helper(src + 1, dst + 1);
	} else {
		alphaOnly_helper(src + 1, dst);
	}
}

void alphaOnly(char *str) {
	alphaOnly_helper(str, str);
}

int main() {
	char str[] = "abcd123qqq";
	alphaOnly(str);
	std::cout << str << std::endl;

	return 0;
}
