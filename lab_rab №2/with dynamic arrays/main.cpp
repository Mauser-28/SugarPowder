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
		CreateDynamicArray(array, arraySize);
		SwapAbsMaxMin(array, arraySize);
		PrintArray(array, arraySize);
		std::cout << "\nsumm of elements in array after last absolute minimum element is: " << SumAfterLastMin(array, arraySize) << '\n';
		SquareNegativeArrayElements(array, arraySize);
		DeleteArray(array);
	}

	catch (const char* message) {
		std::cout << "exeption message: " << message << std::endl;
	}
	catch (...) {
		std::cout << "unexpected exeption";
	}


	try {
		CreateDynamicArray(array, arraySize);
		std::cout << "\nresult of multiplying positives of array is: " << MultiplyPositives(array, arraySize);
		PrintArray(array, arraySize);
		std::cout << "\nresult of sum elements before first min element is: " << SumBeforeFirstMin(array, arraySize);
		PrintArray(array, arraySize);
		SortToParityIncreasingArray(array, arraySize);
		PrintArray(array, arraySize);
		DeleteArray(array);
	}

	catch (const char* message) {
		std::cout << "exeption message: " << message << std::endl;
	}
	catch (...) {
		std::cout << "unexpected exeption";
	}
	return 0;
}