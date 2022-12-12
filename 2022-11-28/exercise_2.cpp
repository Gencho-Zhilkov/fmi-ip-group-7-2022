#include <iostream>
#include <cassert>


enum {
	DEAD = 0,
	ALIVE = 1,
};

const int BOARD_SIZE = 64;

int board[2][BOARD_SIZE][BOARD_SIZE];
unsigned n = 0;


int& cellState(unsigned n, int i, int j) {
	return board[n%2][(i + BOARD_SIZE) % BOARD_SIZE][(j + BOARD_SIZE) % BOARD_SIZE];
}

int countLiveNeighbours(unsigned n, int i, int j) {
	assert(0 <= i && i < BOARD_SIZE);
	assert(0 <= j && j < BOARD_SIZE);
	int res = -cellState(n, i, j);
	for (int row = i-1; row <= i+1; row++) {
		for (int col = j-1; col <= j+1; col++) {
			res += cellState(n, row, col);
		}
	}
	return res;
}

int calcNextState(unsigned n, int i, int j) {
	switch (countLiveNeighbours(n, i, j)) {
		case 2:
			return cellState(n, i, j);
		case 3:
			return ALIVE;
		default:
			return DEAD;
	}
}

void move() {
	for (size_t i = 0; i < BOARD_SIZE; i++) {
		for (size_t j = 0; j < BOARD_SIZE; j++) {
			cellState(n+1, i, j) = calcNextState(n, i, j);
		}
	}
	n++;
}

void printBoard() {
	for (size_t i = 0; i < BOARD_SIZE; i++) {
		for (size_t j = 0; j < BOARD_SIZE; j++) {
			std::cout << (cellState(n, i, j) ? 'x' : '.');
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}


int main() {
	std::cout << "Enter initial number of live cells: ";
	unsigned m;
	std::cin >> m;
	if (m > BOARD_SIZE * BOARD_SIZE) {
		std::cerr << "Too many live cells!" << std::endl;
		return 1;
	}

	unsigned n = 0;
	for (unsigned i = 0; i < m; i++) {
		std::cout << "Enter cell " << i << " coordinates: ";
		unsigned row, col;
		std::cin >> row >> col;
		if (row >= BOARD_SIZE || col >= BOARD_SIZE) {
			std::cerr << "Invalid cell: (" << row << ", " << col << ")" << std::endl;
			return 1;
		}
		cellState(n, row, col) = ALIVE;
	}

	printBoard();
	move();
	printBoard();
	return 0;
}
