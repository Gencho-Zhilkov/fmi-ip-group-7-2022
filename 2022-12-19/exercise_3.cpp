#include <iostream>


bool isSolved(int (&board)[9][9]) {
	unsigned rows[9] = {};
	unsigned cols[9] = {};
	unsigned boxes[3][3] = {};

	for (size_t row = 0; row < 9; row++) {
		for (size_t col = 0; col < 9; col++) {
			const int cell = board[row][col];
			if (cell < 0 || cell > 9) {
				throw "Invalid cell value!";
			}
			if (cell == 0) {
				continue;
			}

			const unsigned mask = 1u << (cell - 1);
			rows[row] |= mask;
			cols[col] |= mask;
			boxes[row/3][col/3] |= mask;
		}
	}

	const unsigned allSet = 0x1ff;
	for (size_t i = 0; i < 9; i++) {
		if(rows[i] != allSet || cols[i] != allSet) {
			return false;
		}
	}
	for (size_t i = 0; i < 3; i++) {
		for (size_t j = 0; j < 3; j++) {
			if (boxes[i][j] != allSet) {
				return false;
			}
		}
	}

	return true;
}

int main() {
	int board[9][9] = {
		{5, 3, 4, 6, 7, 8, 9, 1, 2},
		{6, 7, 2, 1, 9, 5, 3, 4, 8},
		{1, 9, 8, 3, 4, 2, 5, 6, 7},
		{8, 5, 9, 7, 6, 1, 4, 2, 3},
		{4, 2, 6, 8, 5, 3, 7, 9, 1},
		{7, 1, 3, 9, 2, 4, 8, 5, 6},
		{9, 6, 1, 5, 3, 7, 2, 8, 4},
		{2, 8, 7, 4, 1, 9, 6, 3, 5},
		{3, 4, 5, 2, 8, 6, 1, 7, 9}
	};
	// for (size_t i = 0; i < 9; i++) {
	// 	for (size_t j = 0; j < 9; j++) {
	// 		int n;
	// 		std::cin >> n;
	// 		board[i][j] = n;
	// 	}
	// }

	std::cout << std::boolalpha;
	try {
		std::cout << isSolved(board) << std::endl;
	} catch(const char *e) {
		std::cerr << e << std::endl;
		return 1;
	}
	return 0;
}
