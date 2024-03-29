#include <iostream>
#include <stdexcept>
#include <cassert>


// bit-set operations
void bitSet(unsigned &bits, const size_t bit) {
	assert(bit < 8 * sizeof(bits));
	bits |= (1u << bit);
}

bool bitIsSet(const unsigned bits, const size_t bit) {
	assert(bit < 8 * sizeof(bits));
	return bits & (1u << bit);
}

// Check for duplicate values. Uses bitsets for efficiency.
bool isValid(const int sudoku[9][9]) {
	unsigned rows[9] = {};
	unsigned cols[9] = {};
	unsigned boxes[3][3] = {};

	for(size_t i = 0; i < 9; i++) {
		for (size_t j = 0; j < 9; j++) {
			const int val = sudoku[i][j];
			assert(val >=0 && val <= 9);
			if (val == 0) { // Cell is empty
				continue;
			}

			// Check if we've already seen this value
			if (bitIsSet(rows[i], val) ||
				bitIsSet(cols[j], val) ||
				bitIsSet(boxes[i/3][j/3], val)) {
				return false;
			}

			// If not, account it in the bit-sets
			bitSet(rows[i], val);
			bitSet(cols[j], val);
			bitSet(boxes[i/3][j/3], val);
		}
	}

	return true;
}


bool canUse(int sudoku[9][9], size_t row, size_t col, int val) {
	// Check row `row` and column `col` for `val`
	for(size_t n = 0; n < 9; n++) {
		if (sudoku[row][n] == val || sudoku[n][col] == val) {
			return false;
		}
	}

	// Check the box
	const size_t boxI = 3 *(row / 3), boxJ = 3 * (col / 3);
	for (size_t i = 0; i < 3; i ++) {
		for(size_t j = 0; j < 3; j ++) {
			if (sudoku[boxI + i][boxJ + j] == val) {
				return false;
			}
		}
	}
	return true;
}

bool solve(int sudoku[9][9], size_t cell) {
	assert (isValid(sudoku));

	if (cell == 9 * 9) {
		// We've assigned a valid value to all cells: Sudoku is solved!
		return true;
	}

	const size_t i = cell / 9, j = cell % 9;
	const int val = sudoku[i][j];
	if (val != 0) {
		// Cell already has a value: Move on to next one...
		return solve(sudoku, cell + 1);
	}

	// Empty cell: Try out assigning all possible values
	// and see if one leads to a valid solution.
	for (int v = 1; v <= 9; v++) {
		if (!canUse(sudoku, i, j, v)) {
			continue;
		}

		sudoku[i][j] = v;
		if (solve(sudoku, cell + 1)) {
			return true;
		}
	}

	// No valid solution exists, given the values before current cell
	sudoku[i][j] = 0;
	return false;
}

bool solve(int sudoku[9][9]) {
	return solve(sudoku, 0);
}


// char ops
bool isDigit(const char c) {
	return c >= '0' && c <= '9';
}

int toDigit(const char c) {
	assert(isDigit(c));
	return c - '0';
}

// Fill sudoku from values `str`. Empty cells are denoted by `.` or `0`.
void fillFromString(int sudoku[9][9], const char *str) {
	size_t n = 0;
	for(; n < 81 && str[n] != '\0'; n++) {
		const size_t i = n / 9, j = n % 9;
		const char c = str[n];

		if (c == '.') {
			sudoku[i][j] = 0;
		} else if (isDigit(c)) {
			sudoku[i][j] = toDigit(c);
		} else {
			throw std::invalid_argument("Invalid cell value!");
		}
	}

	// If str has less than 81 characters, fill the rest with 0-s.
	for (; n < 81; n++) {
		const size_t i = n / 9, j = n % 9;
		sudoku[i][j] = 0;
	}

	if (!isValid(sudoku)) {
		throw std::invalid_argument("Invalid sudoku!");
	}
}

// Pretty-print a sudoku on `stdout`
void print(int sudoku[9][9]) {
	for (size_t i = 0; i < 9; i++) {
		if (i == 3 || i == 6) {
			std::cout << " ------+-------+------" << std::endl;
		}
		for (size_t j = 0; j < 9; j++) {
			if (j == 3 || j == 6) {
				std::cout << " |";
			}
			const int val = sudoku[i][j];
			const char c = val ? val + '0': '.';
			std::cout << ' ' << c;
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}


// You can find some puzzles at:   https://norvig.com/top95.txt
// Corresponding solutions are at: https://norvig.com/top95solutions.html
int main() {
	char line[9*9 +1]; // +1 char for '\0'
	std::cin.getline(line, sizeof(line));

	int sudoku[9][9];
	try {
		fillFromString(sudoku, line);

		// pretty-print first
		print(sudoku);

		const bool solved = solve(sudoku);
		if (!solved) {
			std::cerr << "No solution found!" << std::endl;
		}

		print(sudoku);
	} catch (std::exception &e) {
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}
