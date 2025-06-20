#include <iostream>

double MultiplyPositives(double* _array, int32_t _arraySize) {
	double product{ 1 };
	for (size_t index{}; index < _arraySize; ++index) {
		if (_array[index] > 0) {
			product *= _array[index];
		}
	}
	return product;
}


size_t MinElement(double* _array, int32_t _arraySize) {
	size_t minElementIndex{};
	for (size_t index{ 1 }; index < _arraySize; ++index) {
		if (_array[index] < _array[minElementIndex]) {
			minElementIndex = index;
		}
	}
	return minElementIndex;
}


double SumBeforeFirstMin(double* _array, int32_t _arraySize) {
	double sum{};
	size_t minElementIndex{ MinElement(_array, _arraySize) };
	for (size_t index{}; index < minElementIndex; ++index) {
		sum += _array[index];
	}
	return sum;
}


void SortToParityIncreasingArray(double* _array, int32_t _arraySize) {
	for (uint8_t parity{}; parity < 2; ++parity) {
		int32_t testCounter{ 1 };
		while (testCounter != 0) {
			testCounter = 0;
			for (int32_t index{ parity }; index + 2 < _arraySize; index += 2) {
				if ((_array[index]) > (_array[index + 2])) {
					std::swap(_array[index], _array[index + 2]);
					++testCounter;
				}
			}
		}
	}
}
