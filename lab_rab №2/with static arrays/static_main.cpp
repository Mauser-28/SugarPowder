#include <iostream>

#include "Sfunctions.h"
#include "variant10.h"
#include "variant16.h"

const int16_t MAX_ARRAY_SIZE{ 300 };

int main() {
	int32_t arraySize{};
	try {
		double array[MAX_ARRAY_SIZE]{};
		std::cout << "\nInput array size ";
		SetSize(arraySize);
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

		SwapAbsMaxMin(array, arraySize);
		PrintArray(array, arraySize);
		std::cout << "\nsumm of elements in array after last absolute minimum element is: " << SumAfterLastMin(array, arraySize) << '\n';
		SquareNegativeArrayElements(array, arraySize);
	}

	catch (const char* message) {
		std::cout << "exeption message: " << message << std::endl;
	}
	catch (...) {
		std::cout << "unexpected exeption";
	}


	try {
		double array[MAX_ARRAY_SIZE]{};
		std::cout << "\nInput array size ";
		SetSize(arraySize);
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

		std::cout << "\nresult of multiplying positives of array is: " << MultiplyPositives(array, arraySize);
		PrintArray(array, arraySize);
		std::cout << "\nresult of sum elements before first min element is: " << SumBeforeFirstMin(array, arraySize);
		PrintArray(array, arraySize);
		SortToParityIncreasingArray(array, arraySize);
		PrintArray(array, arraySize);
	}

	catch (const char* message) {
		std::cout << "exeption message: " << message << std::endl;
	}
	catch (...) {
		std::cout << "unexpected exeption";
	}
	return 0;
}