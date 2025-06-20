#include <iostream>

size_t FirstAbsMaxElement(double* _array, int32_t _arraySize) {
	size_t absMaxElementIndex{};
	for (size_t index{ 1 }; index < _arraySize; ++index) {
		if (abs(_array[index]) > abs(_array[absMaxElementIndex])) {
			absMaxElementIndex = index;
		}
	}
	return absMaxElementIndex;
}


size_t FirstAbsMinElement(double* _array, int32_t _arraySize) {
	size_t absMinElementIndex{};
	for (size_t index{ 1 }; index < _arraySize; ++index) {
		if (abs(_array[index]) < abs(_array[absMinElementIndex])) {
			absMinElementIndex = index;
		}
	}
	return absMinElementIndex;
}


void SwapAbsMaxMin(double* _array, int32_t _arraySize) {
	std::swap(_array[FirstAbsMaxElement(_array, _arraySize)], _array[FirstAbsMinElement(_array, _arraySize)]);
}


size_t LastAbsMinElement(double* _array, int32_t _arraySize) {
	size_t absMinElementIndex{};
	for (size_t index{ 1 }; index < _arraySize; ++index) {
		if (abs(_array[index]) <= abs(_array[absMinElementIndex])) {
			absMinElementIndex = index;
		}
	}
	return absMinElementIndex;
}


double SumAfterLastMin(double* _array, int32_t _arraySize) {
	double sum{};
	for (size_t index{ LastAbsMinElement(_array, _arraySize) + 1 }; index < _arraySize; ++index) {
		sum += _array[index];
	}
	return sum;
}


void SquareNegativeArrayElements(double* _array, int32_t _arraySize) {
	for (size_t index{}; index < _arraySize; ++index) {
		if (_array[index] < 0) {
			_array[index] *= _array[index];
		}
	}
}


void IncreaseArray(double* _array, int32_t _arraySize) {
	int32_t counter{ 1 };
	while (counter != 0) {
		counter = 0;
		for (int32_t i{}; i + 1 < _arraySize; ++i) {
			if ((_array[i]) > (_array[i + 1])) {
				std::swap(_array[i], _array[i + 1]);
				++counter;
			}
		}
	}
}