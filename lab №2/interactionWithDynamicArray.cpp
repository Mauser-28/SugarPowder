#include <iostream>

void SetDynamicSize(int32_t& _arraySize) {
	std::cout << "enter array size: ";
	std::cin >> _arraySize;
	if (_arraySize < 0) {
		throw "You can't make negative size array";
	}
	else if (_arraySize == 0) {
		throw "You can't make empty array";
	}
}


void SetArrayElements(double* _array, int32_t _arraySize) {
	std::cout << "set your elements: ";
	for (size_t index{}; index < _arraySize; ++index) {
		std::cin >> _array[index];
	}
}


void SetRange(double& _a, double& _b) {
	std::cout << "set your range\nfrom a: ";
	std::cin >> _a;
	std::cout << "to b: ";
	std::cin >> _b;
	if (_a > _b) {
		std::swap(_a, _b);
	}
}


void RandomArraySet(double* _array, int32_t _arraySize) {
	double a{};
	double b{};
	SetRange(a, b);
	std::srand(static_cast<unsigned>(std::time(0)));
	for (size_t index{}; index < _arraySize; ++index) {
		_array[index] = a + static_cast<double>(std::rand()) / RAND_MAX * (b - a);
	}
}


void PrintArray(double* _array, int32_t _arraySize) {
	for (size_t index{}; index < _arraySize; ++index) {
		std::cout << _array[index] << '\n';
	}
}


void CreateDinamicArray(double*& array, int32_t& arraySize) {
	SetDynamicSize(arraySize);
	array = new double[arraySize];
	std::cout << "what type of setting you prefer most:\n1.set by user\n2.set random numbers\n";
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
		throw "submitted wrong choice of setting type";
		break;
	}
}
