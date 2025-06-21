#include <iostream>
#include <string>

std::string TakeAsciiNum(char symbol) {
	if (symbol >= 0 && symbol < 10) {
		return "00" + std::to_string(symbol);
	}
	if (symbol >= 10 && symbol < 100) {
		return "0" + std::to_string(symbol);
	}
	if (symbol >= 100 && symbol < 256) {
		return std::to_string(symbol);
	}
	return "";
}


void RedactSting(std::string& str) {
	for (size_t i{}; i < str.length(); ++i) {
		if (str[i] == ' ') {
			str[i] = '+';
		}
		if (str[i] != '+' && (str[i] < 65 || str[i] > 122)) {
			std::string symbolNum = TakeAsciiNum(str[i]);
			if (symbolNum[0] == '\0') {
				throw "You wrote text with symbol not from ASCII code";
			}
			str.erase(i, 1);
			str.insert(i, "%" + symbolNum);
			i += 3;
		}
	}
}