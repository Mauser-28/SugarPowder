#include <iostream>
#include <string>
#include "FunctionsV12.h"

int main() {
	std::string str;
	std::cout << "input text\n";
	try {
		std::getline(std::cin, str);
		if (str.length() == 0) {
			throw "You wrote empty text";
		}
		RedactSting(str);
		std::cout << str;
	}

	catch (const char* message) {
		std::cout << "exeption: " << message;
	}
	catch (...) {
		std::cout << "unexepted message";
	}

	return 0;
}

// Get a new string from the given line by performing the following substitution:
// 
// leave the Latin characters		unchanged;
// 
// character «space»				replace with ' + ';
// 
// the remaining characters are		replaced by a string of "%ddd", where ddd is the code of the character to be replaced in the decimal entry,
//									supplemented if necessary with leading zeros up to three digits.