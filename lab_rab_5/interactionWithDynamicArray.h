#ifndef INTERACTION_WITH_DINAMIC_ARRAY
#define INTERACTION_WITH_DINAMIC_ARRAY


void SetSize(int32_t&);
void InitialiseDynamicArray(int32_t*&, int32_t);
void InitialiseDynamicArray(double*&, int32_t);
void SetArrayElements(int32_t*, int32_t);
void SetArrayElements(double* _array, int32_t _arraySize);
void SetRange(int32_t&, int32_t&);
void SetRange(double&, double&);
void RandomArraySet(int32_t*, int32_t);
void RandomArraySet(double*, int32_t);
void PrintArray(int32_t*, int32_t);
void PrintArray(double* array, int32_t arraySize);
void CreateDynamicArray(int32_t*&, int32_t&);
void CreateDynamicArray(double*& array, int32_t& arraySize);

template<class type>
void DeleteArray(type* array) {
		delete[] array;
}


void InitialiseMatrix(int32_t**&, int32_t, int32_t);
void SetMatrixSize(int32_t&, int32_t&);
bool CheckForSquareMatr(int32_t, int32_t);
void InputMatrixElements(int32_t**, int32_t, int32_t);
void RandomMatrixSet(int32_t**, int32_t, int32_t);
void CreateDynamicMatrix(int32_t**, int32_t, int32_t);
void PrintMatrix(int32_t**, int32_t, int32_t);

template<class type>
void DeleteMatrix(type**& matrix, int32_t rows) {
	for (size_t i{}; i < rows; ++i) {
		delete[] matrix[i];
	}
	delete[] matrix;
}

#endif