#include <iostream>
#include "functions.h"
#include "interactionWithDynamicArray.h"

int main() {

	std::cout << "for correct working of this program you must choise square size matrix with rule:\n\neach line and column at the same time must have only one 0!\n";

	int32_t rows{};
	int32_t cols{};
	int32_t** matrix{};
	try {
		SetMatrixSize(rows, cols);
		InitialiseMatrix(matrix, rows, cols);
		CreateDynamicMatrix(matrix, rows, cols);
		PrintMatrix(matrix, rows, cols);
		if (!CheckForSquareMatr(rows, cols)) {
			throw "matrix need to have square size to solve this problem";
		}
		bool isChanged{};
		ChangeToZeroDiagMatr(matrix, rows);
		PrintMatrix(matrix, rows, cols);
	}

	catch (const char* message) {
		std::cout << "exeption message: " << message << std::endl;
	}
	catch (...) {
		std::cout << "unexpected exeption";
	}
	

	try {
		if (!CheckForSquareMatr(rows, cols)) {
			throw "matrix need to have square size to solve this problem";
		}
		std::cout << CountMultOfDsideTriangle(matrix, rows);
	}

	catch (const char* message) {
		std::cout << "exeption message: " << message << std::endl;
	}
	catch (...) {
		std::cout << "unexpected exeption";
	}

	DeleteMatrix(matrix, rows);

	return 0;
}