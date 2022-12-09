#include <iostream>


int reverseDigits(int n) {
	int res = 0;
	while (n != 0) {
		res = 10 * res + n % 10;
		n /= 10;
	}
	return res;
}

bool isPalindrome(int n) {
	return n == reverseDigits(n);
}


int main() {
	int n;
	std::cin >> n;
	std::cout << std::boolalpha << isPalindrome(n) << std::endl;
	return 0;
}
