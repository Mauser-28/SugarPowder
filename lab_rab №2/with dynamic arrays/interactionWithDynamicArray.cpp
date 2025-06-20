#include <iostream>
#include <iomanip>
#include <random>

void SetSize(int32_t& _arraySize) {
	std::cout << "\nenter size: ";
	std::cin >> _arraySize;
	if (_arraySize < 0) {
		throw "\nYou can't make negative size";
	}
	if (_arraySize == 0) {
		throw "\nYou can't set empty size";
	}
}


void InitialiseDynamicArray(int32_t*& array, int32_t arraySize) {
	array = new int32_t[arraySize]{};
}


void InitialiseDynamicArray(double*& array, int32_t arraySize) {
	array = new double[arraySize]{};
}


void SetArrayElements(int32_t* _array, int32_t _arraySize) {
	std::cout << "\nSet your elements: ";
	for (size_t index{}; index < _arraySize; ++index) {
		std::cin >> _array[index];
		if (std::cin.fail()) {
			throw "\nValue you wrote is not a number";
		}
	}
}


void SetArrayElements(double* _array, int32_t _arraySize) {
	std::cout << "\nSet your elements: ";
	for (size_t index{}; index < _arraySize; ++index) {
		std::cin >> _array[index];
		if (std::cin.fail()) {
			throw "\nValue you wrote is not a number";
		}
	}
}


void SetRange(int32_t& _a, int32_t& _b) {
	std::cout << "\nSet your range\nfrom a: ";
	std::cin >> _a;
	std::cout << "to b: ";
	std::cin >> _b;
	if (_a > _b) {
		std::swap(_a, _b);
	}
}


void SetRange(double& _a, double& _b) {
	std::cout << "\nSet your range\nfrom a: ";
	std::cin >> _a;
	std::cout << "to b: ";
	std::cin >> _b;
	if (_a > _b) {
		std::swap(_a, _b);
	}
}


void RandomArraySet(int32_t* _array, int32_t _arraySize) {
	std::random_device rd;
	std::mt19937 gen(rd());
	int32_t a{};
	int32_t b{};
	SetRange(a, b);
	std::uniform_int_distribution <> dist(a, b);
	for (size_t i{}; i < _arraySize; ++i) {
		_array[i] = dist(rd);
	}
}


void RandomArraySet(double* _array, int32_t _arraySize) {
	std::random_device rd;
	std::mt19937 gen(rd());
	int32_t a{};
	int32_t b{};
	SetRange(a, b);
	std::uniform_real_distribution <> dist(a, b);
	for (size_t i{}; i < _arraySize; ++i) {
		_array[i] = dist(rd);
	}
}


void PrintArray(int32_t* _array, int32_t _arraySize) {
	std::cout << '\n';
	for (size_t index{}; index < _arraySize; ++index) {
		std::cout << _array[index] << ' ';
	}
}


void PrintArray(double* _array, int32_t _arraySize) {
	std::cout << '\n';
	for (size_t index{}; index < _arraySize; ++index) {
		std::cout << _array[index] << ' ';
	}
}


void CreateDynamicArray(int32_t*& array, int32_t& arraySize) {
	SetSize(arraySize);
	InitialiseDynamicArray(array, arraySize);
	std::cout << "\nWhat type of setting you prefer most:\n1.set by user\n2.set random numbers\n";
	int32_t choiceIndex{};
	std::cin >> choiceIndex;
	switch (choiceIndex) {
	case 1:
		SetArrayElements(array, arraySize);
		break;
	case 2:
		RandomArraySet(array, arraySize);
		break;
	default:
		throw "\nSubmitted wrong choice of setting type";
		break;
	}
}


void CreateDynamicArray(double*& array, int32_t& arraySize) {
	SetSize(arraySize);
	InitialiseDynamicArray(array, arraySize);
	std::cout << "\nWhat type of setting you prefer most:\n1.set by user\n2.set random numbers\n";
	int32_t choiceIndex{};
	std::cin >> choiceIndex;
	switch (choiceIndex) {
	case 1:
		SetArrayElements(array, arraySize);
		break;
	case 2:
		RandomArraySet(array, arraySize);
		break;
	default:
		throw "\nSubmitted wrong choice of setting type";
		break;
	}
}





void InitialiseMatrix(int32_t**& matrix, int32_t rows, int32_t cols) {
	matrix = new int32_t * [rows];
	for (int32_t i{}; i < rows; ++i) {
		matrix[i] = new int32_t[cols]{};
	}
}


void SetMatrixSize(int32_t& rows, int32_t& cols) {
	std::cout << "\nSet count of rows: ";
	std::cin >> rows;
	if (rows < 1) {
		throw "\nCount of rows can't be below 1";
	}
	std::cout << "set count of columns: ";
	std::cin >> cols;
	if (cols < 1) {
		throw "\nCount of cols can't be below 1";
	}
}


bool CheckForSquareMatr(int32_t rows, int32_t cols) {
	return rows == cols;
}


void InputMatrixElements(int32_t** matrix, int32_t rows, int32_t cols) {
	std::cout << "\nInput elements of matrix\n";
	for (int32_t i{}; i < rows; ++i) {
		for (int32_t j{}; j < cols; ++j) {
			std::cin >> matrix[i][j];
		}
	}
}


void RandomMatrixSet(int32_t** matrix, int32_t rows, int32_t cols) {
	std::random_device rd;
	std::mt19937 gen(rd());
	int32_t a{};
	int32_t b{};
	SetRange(a, b);
	std::uniform_int_distribution <> dist(a, b);
	for (size_t i{}; i < rows; ++i) {
		for (size_t j{}; j < cols; ++j) {
			matrix[i][j] = dist(rd);
		}
	}
}


void PrintMatrix(int32_t** matrix, int32_t rows, int32_t cols) {
	for (int32_t i{}; i < rows; ++i) {
		for (int32_t j{}; j < cols; ++j) {
			std::cout << std::setw(5) << matrix[i][j];
		}
		std::cout << '\n';
	}
}


void CreateDynamicMatrix(int32_t** matrix, int32_t rows, int32_t cols) {
	if (rows < 0) {
		throw "\nCount of rows can't be below zero";
	}
	if (cols < 0) {
		throw "\nCount of cols can't be below zero";
	}
	if (rows == 0 || cols == 0) {
		throw "\nYou can't make empty matrix";
	}

	std::cout << "\nWhat type of setting you prefer most:\n1.set by user\n2.set random numbers\n";
	int32_t choiceIndex{};
	std::cin >> choiceIndex;
	switch (choiceIndex) {
	case 1:
		InputMatrixElements(matrix, rows, cols);
		break;
	case 2:
		RandomMatrixSet(matrix, rows, cols);
		break;
	default:
		throw "\nSubmitted wrong choice of setting type";
		break;
	}
}