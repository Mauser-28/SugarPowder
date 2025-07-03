#ifndef FUNCTIONS
#define FUNCTIONS
#include <string>
#include <fstream>

int32_t CountDoublesInFile(std::ifstream&);

bool IsDigit(std::string);

void CreateDoubleArrayWithFile(std::ifstream&, double*);

struct Student {
	std::string name{ " NONAME" };
	std::string surname{ " NOSURNAME" };
	int16_t course{};
	int32_t group{};
	int16_t marks[5]{};
};






void BubbleSort(double* arr, int32_t arrSize);

void SelectionSort(double* arr, int32_t arrSize);

void InsertionSort(double* arr, int32_t arrSize);

void Merge(double* arr, int32_t left, int32_t mid, int32_t right);

void MergeSort(double* arr, int32_t left, int32_t right);
int32_t CountDigitAfterDot(double num);
int32_t CompareByFractionDigits(const void* a, const void* b);

template<typename type>
void FromBiggerToLower(type* arr, int32_t arrSize) {
	int32_t i = {};
	while (i != arrSize || i < arrSize) {
		std::swap(arr[i], arr[arrSize - 1]);
		++i;
		--arrSize;
	}
}

template<typename T>
int32_t Partitions(T* arr, int32_t startIndex, int32_t endIndex) {
	T pivot = arr[endIndex];
	int32_t i = startIndex - 1;
	for (int32_t j = startIndex; j < endIndex; ++j) {
		if (arr[j] < pivot) {
			++i;
			std::swap(arr[i], arr[j]);
		}
	}
	std::swap(arr[i + 1], arr[endIndex]);
	return i + 1;
}

template<typename T>
void QuickSort(T* arr, int32_t startIndex, int32_t endIndex) {
	if (startIndex < endIndex) {
		int32_t pivotIndex = Partitions(arr, startIndex, endIndex);
		QuickSort(arr, startIndex, pivotIndex - 1);
		QuickSort(arr, pivotIndex + 1, endIndex);
	}
}

template<class type>
void ChangeMonotonyOfSorting(type* array, int32_t arraySize) {
	int32_t center{ arraySize / 2 };
	for (int32_t i{}; i <= center; ++i) {
		std::swap(array[i], array[arraySize - 1 - i]);
	}
}

template<class type>
void SortWithSetting(type* array, int32_t arraySize) {
	std::cout << "\nWhat type of sorting you prefer most:\n1.BubbleSort\n2.SelectionSort\n3.InsertionSort\n4.MergeSort\n5.QuickSort\n6.qsort" << std::endl;
	int16_t choiseIndex = 0;
	std::cin >> choiseIndex;
	switch (choiseIndex) {
	case 1:
		BubbleSort(array, arraySize);
		break;
	case 2:
		SelectionSort(array, arraySize);
		break;
	case 3:
		InsertionSort(array, arraySize);
		break;
	case 4:
		MergeSort(array, 0, arraySize - 1);
		break;
	case 5:
		QuickSort(array, 0, arraySize - 1);
		break;
	case 6:
		std::qsort(array, static_cast<size_t>(arraySize), sizeof(double), CompareByFractionDigits);
		break;
	default:
		throw "submitted wrong choice of setting type";
		break;
	}

	choiseIndex = 0;
	std::cout << "\npress 1 to change monotony of array\n";
	std::cin >> choiseIndex;
	if (choiseIndex == 1) {
		ChangeMonotonyOfSorting(array, arraySize);
	}
}


void InitialiseStructArray(Student*&, int32_t);
void InputStudentsInfo(Student*, int32_t);
void SortStudentsByAverMarks(Student*, int32_t);
double CountAverage(int16_t*, int32_t);
void PrintStudentsInfo(Student*, int32_t);

#endif