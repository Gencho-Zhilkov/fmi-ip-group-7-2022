#include <algorithm>
#include <iterator>
#include <iostream>
#include <random>
#include <vector>

int getSecret() {
	// Generate a 4-digit random number without repeating digits
	std::vector<int> digits = {1, 2, 3, 4, 5, 6, 7, 8, 9};
	std::random_device rd;
	std::mt19937 g(rd());
	std::shuffle(digits.begin(), digits.end(), g);

	int res = 0;
	for(int i = 0; i < 4; i++) {
		res = 10 * res + digits[i];
	}
	return res;
}

int main() {
	const int secret = getSecret();
	// std::cout << secret << std::endl;
	// Your code goes here ...
	return 0;
}
