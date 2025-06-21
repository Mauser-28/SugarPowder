//7 12
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <windows.h>
#include "functionsV7.h"


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	std::cout << "write message\n";

	try {
		char str[300];
		std::cin.getline(str, 300);
		if (IsAsciiWord(str)) {
			throw "You wrote text with symbol not from ASCII code";
		}
		char newstr[300]{};
		WriteVowelAndLcaseWords(str, newstr);
		std::cout << newstr;
	}

	catch (const char* message) {
		std::cout << "exeption message: " << message << std::endl;
	}
	catch (...) {
		std::cout << "unexpected exeption";
	}
	return 0;
}