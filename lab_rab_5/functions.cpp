#include <iostream>


bool CheckForZeroMainDiag(int32_t** matrix, int32_t power) {
	for (size_t j{}; j < power; ++j) {
		int32_t counter{};
		for (size_t i{}; i < power; ++i) {
			if (matrix[i][j] == 0) {
				++counter;
			}
		}
		if (counter != 1) {
			return 0;
		}

	}

	for (size_t i{}; i < power; ++i) {
		int32_t counter{};
		for (size_t j{}; j < power; ++j) {
			if (matrix[i][j] == 0) {
				++counter;
			}
		}
		if (counter != 1) {
			return 0;
		}
	}
	return 1;
}


void ChangeToZeroDiagMatr(int32_t** matrix, int32_t power) {
	std::cout << '\n';
	if (!CheckForZeroMainDiag(matrix, power)) {
		throw "this matrix won't be zerodiagonal after rows changing";
	}
	for (size_t j{}; j < power; ++j) {
		for (size_t i{}; i < power; ++i) {
			if (matrix[i][j] == 0 && i != j) {
				std::swap(matrix[i], matrix[j]);
			}
		}
	}
}


int64_t CountMultOfDsideTriangle(int32_t** matrix, int32_t power) {
	int64_t matrMult{1};
	for (size_t i{}; i < power; ++i) {
		for (size_t j{}; j < i; ++j) {
			matrMult *= matrix[i][j];
		}
	}
	return matrMult;
}