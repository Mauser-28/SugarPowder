#ifndef FUNCTIONS
#define FUNCTIONS

#include <iostream>
#include <random>
#include <fstream>

struct Student {
	int course{};
	int group{};
	std::string surname;
	std::string name;
	std::string patronymic;
	int32_t grade1{};
	int32_t grade2{};
	int32_t grade3{};
};

std::istream& operator>>(std::istream&, Student&);

std::ostream& operator<<(std::ostream&, Student&);

bool operator>(const Student&, const Student&);

bool operator<(const Student&, const Student&);

bool operator<=(const Student&, const Student&);

template<class type>
void FillArray(type* array, int32_t arrSize) {
	for (int32_t i{}; i < arrSize; ++i) {
		std::cin >> array[i];
	}
}

void FillRandomArray(int*, int);
void FillRandomArray(double*, int);
void FillRandomArray(char*, int);

template<class type>
void ReadFromFile(std::string filename, type*& array) {
	std::ifstream in(filename);

	type temp{};
	int32_t size{};
	while (in >> temp) {
		++size;
	}
	array = new type[size];
	in.clear();
	in.seekg(0, std::ios::beg);
	for (int32_t i = 0; i < size; ++i) {
		in >> array[i];
	}
	in.close();
}

bool IsReversed();

template <class type>
void BubbleSort(type* array, int32_t arrSize) {
	bool reverse{ IsReversed() };
	bool isSwaped{ false };
	--arrSize;
	for (int32_t i{}; i < arrSize; ++i){
		for (int32_t j{}; j < arrSize-i ; ++j) {
			if ((array[j] > array[j + 1]) ^ reverse) {
				std::swap(array[j], array[j + 1]);
				isSwaped = true;
			}
		}
		if (!isSwaped) {
			return;
		}
	}
}


template <class type>
void ShakerSort(type* array, int32_t arrSize) {
	bool reverse{ IsReversed() };
	bool isSwaped{ true };
	int32_t start{};
	int32_t end{--arrSize};
	while (isSwaped) {
		isSwaped = false;
		for (int32_t i{start}; i < end; ++i) {
			if ((array[i] > array[i + 1]) ^ reverse) {
				std::swap(array[i], array[i + 1]);
				isSwaped = true;
			}
		}
		if (!isSwaped) {
			return;
		}
		--end;
		for (int32_t i{end}; i > start; --i) {
			if ((array[i - 1] > array[i]) ^ reverse) {
				std::swap(array[i - 1], array[i]);
				isSwaped = true;
			}
		}
		++start;
	}
}


template <class type>
void CombSort(type array, int32_t arrSize) {
	bool reverse{ IsReversed() };
	int32_t stepSize{ static_cast<int32_t>(arrSize * 0.8) };
	bool isSwaped{ true };
	while (stepSize > 1 || isSwaped) {
		if (stepSize > 1) {
			stepSize = static_cast<int32_t>(stepSize * 0.8);
		}
		isSwaped = false;
		for (int32_t i{}; i + stepSize < arrSize; ++i) {
			if ((array[i] > array[i + stepSize]) ^ reverse) {
				std::swap(array[i], array[i + stepSize]);
				isSwaped = true;
			}
		}
	}
}


template <class type>
void InsertionSort(type* array, int32_t arrSize) {
	bool reverse{ IsReversed() };
	for (int32_t i{ 1 }; i < arrSize; ++i) {
		for (int32_t j{ i }; j > 0 && ((array[j - 1] > array[j]) ^ reverse); --j) {
			std::swap(array[j - 1], array[j]);
		}
	}
}


template <class type>
void SelectionSort(type* array, int32_t size){
	bool reverse{ IsReversed() };
	int32_t min{};
	for (int32_t i{}; i < size - 1; ++i){
		min = i;
		for (int32_t j{ i + 1 }; j < size; ++j){
			if ((array[j] > array[min]) ^ reverse){
				min = j;
			}
		}
		if (min != i){
			std::swap(array[i], array[min]);
		}
	}
}

template <class type>
int32_t QuickSortCompare(type* array, int32_t min, int32_t max){
	type stapleElement{ array[max] };
	int32_t staplePlace{ min - 1 };

	for (int32_t i{ min }; i < max; ++i){
		if (array[i] < stapleElement){
			++staplePlace;
			std::swap(array[i], array[staplePlace]);
		}
	}
	std::swap(array[max], array[staplePlace + 1]);
	return staplePlace + 1;
}

template <class type>
void QuickSort(type* array, int32_t min, int32_t max)
{
	if (min < max)
	{
		int32_t center = QuickSortCompare(array, min, max);
		QuickSort(array, min, center - 1);
		QuickSort(array, center + 1, max);
	}
}


template<class type>
void Merge(type* array, int32_t left, int32_t mid, int32_t right) {
	int32_t min{ mid - left + 1 };
	int32_t max{ right - mid };

	type* leftarr = new type[min];
	type* rightarr = new type[max];

	for (int32_t i{}; i < min; ++i) {
		leftarr[i] = array[left + i];
	}
	for (int32_t j{}; j < max; ++j) {
		rightarr[j] = array[mid + 1 + j];
	}

	int32_t i{}, j{}, k{ left };

	while (i < min && j < max) {
		if (leftarr[i] <= rightarr[j]) {
			array[k++] = leftarr[i++];
		}
		else {
			array[k++] = rightarr[j++];
		}
	}

	while (i < min) {
		array[k++] = leftarr[i++];
	}
	while (j < max) {
		array[k++] = rightarr[j++];
	}

	delete[] leftarr;
	delete[] rightarr;
}


template<class type>
void MergeSort(type* array, int32_t left, int32_t right) {
	if (left < right) {
		int32_t mid{ left + (right - left) / 2 };
		MergeSort(array, left, mid);
		MergeSort(array, mid + 1, right);
		Merge(array, left, mid, right);
	}
}


template <class type>
void SortWithChoise(type array, int32_t arrSize) {
	std::cout << "choise the sort:\n\n1. BubbleSort\n2. ShakerSort\n3. CombSort\n4. InsertionSort\n5. SelectionSort\n6. QuickSort\n7. MergeSort";
	int16_t choisenIndex{};
	std::cin >> choisenIndex;
	switch (choisenIndex) {
	case 1:
		BubbleSort(array, arrSize);
		break;
	case 2:
		ShakerSort(array, arrSize);
		break;
	case 3:
		CombSort(array, arrSize);
		break;
	case 4:
		InsertionSort(array, arrSize);
		break;
	case 5:
		SelectionSort(array, arrSize);
		break;
	case 6:
		QuickSort(array, 0, arrSize - 1);
		break;
	case 7:
		MergeSort(array, 0, arrSize - 1);
		break;
	default:
		break;
	}
}


template <class type>
void PrintArray(type array, int32_t arrSize) {
	for (int32_t i{}; i < arrSize; ++i) {
		std::cout << array[i] << ' ';
	}
}


template<class type>
void WriteToFile(const std::string& filename, type* array, int size) {
	std::ofstream out(filename);
	for (int i = 0; i < size; ++i)
		out << array[i] << "\n";
}
#endif