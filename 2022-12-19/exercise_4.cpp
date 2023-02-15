#include <iostream>
#include <stdexcept>
#include <cstring>
#include <cassert>


const size_t MAX_SIZE = 1024;
const char UP = '^';
const char DOWN = 'v';
const char LEFT = '<';
const char RIGHT = '>';
const char FINISH = '+';
const char EMPTY = ' ';


bool areValid(const size_t i, const size_t j, const size_t rows, const size_t cols) {
	// Check if coordinates (i, j) are valid (i.e. inside the labyrinth)
	return i < rows && j < cols; // size_t guarantees `i` and `j` are positive
}

bool isEmpty(const char labyrinth[][MAX_SIZE], const size_t i, const size_t j) {
	// Is this an empty cell? Assumes validity check are done beforehand.
	return labyrinth[i][j] == EMPTY;
}

bool isExit(const size_t i, const size_t j, const size_t rows, const size_t cols) {
	// Have we arrived at one of the boundaries?
	return i == 0 || i == rows - 1 || j == 0 || j == cols - 1;
}

void printLabyrint(char labyrinth[][MAX_SIZE], const size_t rows, const size_t cols) {
	for (size_t i = 0; i < rows; i++) {
		for(size_t j = 0; j < cols; j ++) {
			std::cout << labyrinth[i][j];
		}
		std::cout << std::endl;
	}
}

bool findExit(char labyrinth[][MAX_SIZE], const size_t rows, const size_t cols,
		const size_t i, const size_t j) {
	assert(areValid(i, j, rows, cols));

	if (!isEmpty(labyrinth, i, j)) {
		return false;
	}

	if (isExit(i, j, rows, cols)) {
		labyrinth[i][j] = FINISH;
		return true;
	}

	// Try going in each direction in turn.
	labyrinth[i][j] = UP;
	if (findExit(labyrinth, rows, cols, i-1, j)) {
		return true;
	}

	labyrinth[i][j] = DOWN;
	if (findExit(labyrinth, rows, cols, i+1, j)) {
		return true;
	}

	labyrinth[i][j] = LEFT;
	if (findExit(labyrinth, rows, cols, i, j-1)) {
		return true;
	}

	labyrinth[i][j] = RIGHT;
	if (findExit(labyrinth, rows, cols, i, j+1)) {
		return true;
	}

	labyrinth[i][j] = EMPTY;
	return false;
}

void solveLabyrinth(char labyrinth[][MAX_SIZE], const size_t rows, const size_t cols,
		const size_t startRow, const size_t startCol) {

	if (!areValid(startRow, startCol, rows, cols)) {
		throw std::invalid_argument("Ivalid starting coordinates!");
	}

	if (!isEmpty(labyrinth, startRow, startCol)) {
		throw std::invalid_argument("Starting position inside a wall!");
	}

	bool found = findExit(labyrinth, rows, cols, startRow, startCol);
	if (!found) {
		throw std::runtime_error("Could not find an exit!");
	}
}

int main() {
	char labyrinth[MAX_SIZE][MAX_SIZE];
	size_t rows, cols;

	do {
		std::cout << "Enter number of rows and columns: ";
		std::cin >> rows >> cols;
	} while (rows > MAX_SIZE || cols > MAX_SIZE);

	std::cin.ignore();
	std::cout << "Enter labyrinth:" << std::endl;
	for (size_t i = 0; i < rows; i++) {
		char line[MAX_SIZE+1];	// +1 for terminating '\0'
		std::cin.getline(line, MAX_SIZE);
		if (strlen(line) != cols) {
			std::cerr << "Wrong length! Skipping line ..." << std::endl;
			i--;
		} else {
			// Using `memcpy` instead of `strcpy` here ensures that
			// we will copy only the chars, without the final '\0'.
			memcpy(labyrinth[i], line, cols);
		}
	}

	size_t startRow, startCol;
	std::cout << "Enter starting point: ";
	std::cin >> startRow >> startCol;

	try {
		solveLabyrinth(labyrinth, rows, cols, startRow, startCol);
	} catch (const std::exception& ex) {
		std::cerr << ex.what() << std::endl;
		return 1;
	}

	// Print out the solution:
	std::cout << std::endl;
	printLabyrint(labyrinth, rows, cols);
	return 0;
}
