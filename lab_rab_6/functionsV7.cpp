#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <cctype>


bool IsAsciiWord(char* str) {
	size_t length{strlen(str)};
	for (size_t i{}; i < length; ++i) {
		if (str[i] <= 0 && str[i] > 256) {
			return false;
		}
	}
	return true;
}


void WriteVowelAndLcaseWords(char* str, char* newStr) {
	char vowels[]{ "aAeEiIoOuUyY" };
	char delim[]{ " ,.?!:;_" };
	char copyStr[300]{};
	strcpy(copyStr, str);
	char* token = strtok(copyStr, delim);
	while (token != NULL) {
		if (strchr(vowels, *token) != NULL) {
			token[0] = (char)tolower(token[0]);
			strcat(newStr, token);
			strcat(newStr, " ");
		}
		token = strtok(NULL, delim);
	}
}