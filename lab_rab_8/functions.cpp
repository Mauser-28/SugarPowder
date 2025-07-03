#include <iostream>
#include "interactionWithDynamicArray.h"
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include "functions.h"

bool IsDigit(std::string str) {
	std::istringstream checkStream(str);
	double num{};
	char symb{};
	return (checkStream >> num) && !(checkStream >> symb);
}


int32_t CountDoublesInFile(std::ifstream& fin) {
	fin.clear();
	fin.seekg(0, std::ios::beg);
	int32_t counter{};
	std::string str{};
	while (fin >> str) {
		if (IsDigit(str)) {
			++counter;
		}
	}
	return counter;
}


void CreateDoubleArrayWithFile(std::ifstream& fin, double* array){
	fin.clear();
	fin.seekg(0, std::ios::beg);
	std::string str{};
	int32_t i{};
	while (fin >> str) {
		if (IsDigit(str)) {
			array[i] = std::stod(str);
			++i;
		}
	}
}


void BubbleSort(double* arr, int32_t arrSize) {
	bool isSwapped = true;
	while (isSwapped == true) {
		isSwapped = false;
		for (int32_t i = {}; i < arrSize - 1; ++i) {
			if (arr[i] > arr[i + 1]) {
				std::swap(arr[i], arr[i + 1]);
				isSwapped = true;
			}
		}
		arrSize -= 1;
	}
}

void SelectionSort(double* arr, int32_t arrSize) {
	for (int32_t i = {}; i < arrSize - 1; ++i) {
		int32_t indexOfMin = { i };
		for (int32_t j = { i + 1 }; j < arrSize; ++j) {
			if (arr[j] < arr[indexOfMin]) {
				indexOfMin = j;
			}
		}
		if (indexOfMin != i) {
			std::swap(arr[i], arr[indexOfMin]);
		}
	}
}

void InsertionSort(double* arr, int32_t arrSize) {
	for (int32_t i = { 1 }; i < arrSize; ++i) {
		double key = arr[i];
		int32_t j = i - 1;
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			--j;
		}
		arr[j + 1] = key;
	}
}

void Merge(double* arr, int32_t left, int32_t mid, int32_t right) {
	int32_t size1 = mid - left + 1;
	int32_t size2 = right - mid;
	double* L = new double[size1];
	double* R = new double[size2];
	for (int32_t i = {}; i < size1; ++i)
		L[i] = arr[left + i];
	for (int32_t j = {}; j < size2; ++j)
		R[j] = arr[mid + 1 + j];
	int32_t i = {};
	int32_t j = {};
	int32_t k = { left };
	while (i < size1 && j < size2) {
		if (L[i] <= R[j]) {
			arr[k] = L[i];
			++i;
		}
		else {
			arr[k] = R[j];
			++j;
		}
		++k;
	}
	while (i < size1) {
		arr[k] = L[i];
		++i;
		++k;
	}
	while (j < size2) {
		arr[k] = R[j];
		++j;
		++k;
	}
	delete[] L;
	delete[] R;
}


void MergeSort(double* arr, int32_t left, int32_t right) {
	if (left < right) {
		int32_t mid = (left + right) / 2;

		MergeSort(arr, left, mid);

		MergeSort(arr, mid + 1, right);

		Merge(arr, left, mid, right);
	}
}


int32_t CountDigitAfterDot(double num) {
	std::ostringstream oss;
	oss << std::fixed << std::setprecision(7) << num;
	std::string str = oss.str();
	int32_t pos = static_cast<int32_t>(str.find('.'));
	if (pos == std::string::npos) {
		return 0;
	}
	int32_t count = str.size() - pos - 1;
	while (count > 0 && str.back() == '0') {
		str.pop_back();
		--count;
	}
	return count;
}

int32_t CompareByFractionDigits(const void* a, const void* b) {
	double da = *(const double*)a;
	double db = *(const double*)b;

	int32_t countA = CountDigitAfterDot(da);
	int32_t countB = CountDigitAfterDot(db);

	return countA - countB;
}


void InitialiseStructArray(Student*& array, int32_t arraySize) {
	if (arraySize <= 0) {
		throw "Size cannot be negative";
	}
	array = new Student[arraySize];
}

void InputStudentsInfo(Student* array, int32_t arrSize) {
	std::cout << "enter the range of your rating system: ";
	int32_t leftSide{};
	int32_t rightSide{};
	SetRange(leftSide, rightSide);
	for (int32_t i = {}; i < arrSize; ++i) {
		std::cout << "\nname:";
		std::cin.ignore();
		getline(std::cin, array[i].name);
		if (array[i].name.empty()) {
			throw "Name cannot be empty";
		}
		std::cout << "surname:";
		getline(std::cin, array[i].surname);
		if (array[i].surname.empty()) {
			throw "Surname cannot be empty";
		}
		std::cout << "course:";
		if (!(std::cin >> array[i].course && array[i].course > 0 && array[i].course < 6)) {
			throw "The course number must be positive and not more than 5";
		}
		std::cout << "group:";
		if (!(std::cin >> array[i].group && array[i].group > 0)) {
			throw "The group number must be positive";
		}


		std::cout << "Input 5 marks:";
		for (int32_t j = {}; j < 5; ++j) {
			std::cout << "\ninput " << j + 1 << " mark:" << std::endl;
			if (!(std::cin >> array[i].marks[j] && array[i].marks[j] >= leftSide && array[i].marks[j] <= rightSide)) {
				throw "Marks must be from " + std::to_string(leftSide) + " to " + std::to_string(rightSide);
			}
		}
	}
}

void SortStudentsByAverMarks(Student* array, int32_t arraySize) {
	double* averages{};
	InitialiseDynamicArray(averages, arraySize);
	for (int32_t i{}; i < arraySize; ++i) {
		averages[i] = CountAverage(array[i].marks, 5);
	}

	bool isSwapped = true;
	while (isSwapped == true) {
		isSwapped = false;
		for (int32_t i = {}; i < arraySize - 1; ++i) {
			if (averages[i] > averages[i + 1]) {
				std::swap(array[i], array[i + 1]);
				std::swap(averages[i], averages[i + 1]);
				isSwapped = true;
			}
		}
		arraySize -= 1;
	}
}

double CountAverage(int16_t* array, int32_t arraySize) {
	int32_t sumOfMarks{};
	for (int32_t i{}; i < arraySize; ++i) {
		sumOfMarks += array[i];
	}
	return static_cast<double>(sumOfMarks) / arraySize;
}

void PrintStudentsInfo(Student* array, int32_t arraySize) {
	for (int32_t i = {}; i < arraySize; ++i) {
		std::cout << "\nName: " << array[i].name;
		std::cout << "\nSurname: " << array[i].surname;
		std::cout << "\nGroup: " << array[i].course;
		std::cout << "\nClass: " << array[i].group;
		std::cout << "\nMarks: ";
		for (int32_t j = {}; j < 5; ++j) {
			std::cout << array[i].marks[j] << " ";
		}
		std::cout << "\nAverage mark: " << CountAverage(array[i].marks, 5) << "\n\n";
	}
}