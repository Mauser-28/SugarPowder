#include <iostream>
#include "interactionWithDynamicArray.h"
#include "functions.h"
#include <fstream>

int main() {
	std::cout << "where your data will be located:\n1.file\n2.console" << std::endl;
	try {
		std::ifstream fin("fileWithDoubles.txt");
		double* array;
		int32_t arraySize{};
		int16_t choiseIndex{};
		std::cin >> choiseIndex;
		switch (choiseIndex) {
		case 1:
			arraySize = CountDoublesInFile(fin);
			InitialiseDynamicArray(array, arraySize);
			CreateDoubleArrayWithFile(fin, array);
			break;
		case 2:
			CreateDynamicArray(array, arraySize);
			break;
		default:
			throw "\nsubmitted wrong choice of setting type";
			break;
		}

		SortWithSetting(array, arraySize);
		PrintArray(array, arraySize);
		fin.close();
	}

	catch (const char* message) {
		std::cout << "\nexeption message: " << message << std::endl;
	}
	catch (...) {
		std::cout << "\nunexpected exeption";
	}


	try {
		std::cout << "\nInput size of array of student: ";
		int32_t arraySize{};
		std::cin >> arraySize;
		Student* array;
		InitialiseStructArray(array, arraySize);
		InputStudentsInfo(array, arraySize);
		SortStudentsByAverMarks(array, arraySize);
		PrintStudentsInfo(array, arraySize);
	}

	catch (const char* message) {
		std::cout << "exeption message: " << message << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	catch (std::string message) {
		std::cout << "exeption message: " << message << std::endl;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	catch (...) {
		std::cout << "unexpected exeption";
	}

	return 0;
}