#include <iostream>
#include <iomanip>
#include <random>
#include "Sfunctions.h"

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


void SetArrayElements(double* _array, int32_t _arraySize) {
	std::cout << "\nSet your elements: ";
	for (size_t index{}; index < _arraySize; ++index) {
		std::cin >> _array[index];
		if (std::cin.fail()) {
			throw "\nValue you wrote is not a number";
		}
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


void RandomArraySet(double* _array, int32_t _arraySize) {
	std::random_device rd;
	std::mt19937 gen(rd());
	double a{};
	double b{};
	SetRange(a, b);
	std::uniform_real_distribution <> dist(a, b);
	for (size_t i{}; i < _arraySize; ++i) {
		_array[i] = dist(rd);
	}
}


void PrintArray(double* _array, int32_t _arraySize) {
	std::cout << '\n';
	for (size_t index{}; index < _arraySize; ++index) {
		std::cout << _array[index] << ' ';
	}
}