#include <iostream>
#include <cstdlib>
#include <ctime>

#include "interactionWithDynamicArray.h"
#include "variant10.h"
#include "variant16.h"


int main() {
	int32_t arraySize{};
	double* array{};
	try {
		CreateDinamicArray(array, arraySize);
		PrintArray(array, arraySize);
		SwapAbsMaxMin(array, arraySize);
		std::cout << "\nsumm of elements in array after last absolute minimum element is: " << SumAfterLastMin(array, arraySize) << '\n';
		SquareNegativeArrayElements(array, arraySize);
		PrintArray(array, arraySize);
		delete[] array;
	}

	catch (const char* message) {
		std::cout << "exeption message: " << message << std::endl;
		arraySize = 1;
	}
	catch (...) {
		std::cout << "unexpected exeption";
	}


	try {
		CreateDinamicArray(array, arraySize);
		PrintArray(array, arraySize);
		std::cout << "result of multiplying positives of array is: " << MultiplyPositives(array, arraySize);
		std::cout << "result of sum elements before first min element is: " << SumBeforeFirstMin(array, arraySize);
		SortToParityIncreasingArray(array, arraySize);
		delete[] array;
	}

	catch (const char* message) {
		std::cout << "exeption message: " << message << std::endl;
		arraySize = 1;
	}
	catch (...) {
		std::cout << "unexpected exeption";
	}
	return 0;
}