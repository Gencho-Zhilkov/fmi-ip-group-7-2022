#include <iostream>


int main() {
	size_t n, m;
	std::cout << "Enter number of rows: ";
	std::cin >> n;

	std::cout << "Enter number of columns: ";
	std::cin >> m;

	int **matrix = new int*[n];
	for(size_t i = 0; i < n; i ++) {
		matrix[i] = new int[m];

		for(size_t j = 0; j < m; j ++) {
			// std::cout << "Enter cell " << i << ", " << j << ": ";
			std::cin >> matrix[i][j];
		}
	}

	size_t *maxColumnForRow = new size_t[n]();
	size_t *minRowForColumn = new size_t[m]();

	for (size_t i = 0; i < n; i ++) {
		for (size_t j = 0; j < m; j ++) {
			if (matrix[i][j] > matrix[i][maxColumnForRow[i]]) {
				maxColumnForRow[i] = j;
			}
			if (matrix[i][j] < matrix[minRowForColumn[j]][j]) {
				minRowForColumn[j] = i;
			}
		}
	}

	for (size_t i = 0; i < n; i ++) {
		const size_t maxColumn = maxColumnForRow[i];
		const size_t minRow = minRowForColumn[maxColumn];
		if (minRow == i) {
			std::cout << minRow << ", " << maxColumn << ": " << matrix[minRow][maxColumn] << std::endl;
		}
	}

	// Free up memory
	for (size_t i = 0; i < n; i ++) {
		delete[] matrix[i];
	}
	delete[] matrix;

	return 0;
}
