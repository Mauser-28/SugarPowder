#include "functions.h"

int main() {
    
    setlocale(LC_ALL, ".1251");
    std::cout << "Выберите тип данных:\n1 - int\n2 - double\n3 - char\n4 - string\n5 - Student\n";
    int type; std::cin >> type;
    std::cout << "Введите количество элементов: ";
    int size; std::cin >> size;
    std::cout << "Выберите способ ввода:\n1 - Ввод вручную\n2 - Генерация случайных()\n3 - Чтение из файла\n";
    int method; std::cin >> method;

    std::string inFile = "inData.txt";
    std::string outFile = "outData.txt";

    if (type == 1) {
        int32_t* array = new int32_t[size];

        switch (method) {
        case 1:
            FillArray(array, size);
            SortWithChoise(array, size);
            WriteToFile(outFile, array, size);
            break;
        case 2:
            FillRandomArray(array, size);
            SortWithChoise(array, size);
            WriteToFile(outFile, array, size);
            break;
        case 3:
            ReadFromFile(inFile, array);
            SortWithChoise(array, size);
            PrintArray(array, size);
            break;
        default:
            break;
            delete[] array;
        }
    }
    else if (type == 2) {
        double* array = new double[size];
        switch (method) {
        case 1:
            FillArray(array, size);
            SortWithChoise(array, size);
            WriteToFile(outFile, array, size);
            break;
        case 2:
            FillRandomArray(array, size);
            SortWithChoise(array, size);
            WriteToFile(outFile, array, size);
            break;
        case 3:
            ReadFromFile(inFile, array);
            SortWithChoise(array, size);
            PrintArray(array, size);
            break;
        default:
            break;
            delete[] array;
        }
    }
    else if (type == 3) {
        char* array = new char[size];
        switch (method) {
        case 1:
            FillArray(array, size);
            SortWithChoise(array, size);
            WriteToFile(outFile, array, size);
            break;
        case 2:
            FillRandomArray(array, size);
            SortWithChoise(array, size);
            WriteToFile(outFile, array, size);
            break;
        case 3:
            ReadFromFile(inFile, array);
            SortWithChoise(array, size);
            PrintArray(array, size);
            break;
        default:
            break;
            delete[] array;
        }
    }
    else if (type == 4) {
        std::string* array = new std::string[size];
        switch (method) {
        case 1:
            FillArray(array, size);
            SortWithChoise(array, size);
            WriteToFile(outFile, array, size);
            break;
        case 2:
            /*FillRandomarray(array, size);
            SortWithChoise(array, size);
            WriteToFile(outFile, array, size);*/
            break;
        case 3:
            ReadFromFile(inFile, array);
            SortWithChoise(array, size);
            PrintArray(array, size);
            break;
        default:
            break;
            delete[] array;
        }
    }
    else if (type == 5) {
        Student* array = new Student[size];
        switch (method) {
        case 1:
            FillArray(array, size);
            SortWithChoise(array, size);
            WriteToFile(outFile, array, size);
            break;
        case 2:
            /*FillRandomarray(array, size);
            SortWithChoise(array, size);
            WriteToFile(outFile, array, size);*/
            break;
        case 3:
            ReadFromFile(inFile, array);
            SortWithChoise(array, size);
            PrintArray(array, size);
            break;
        default:
            break;
            delete[] array;
        }
    }
    return 0;
}