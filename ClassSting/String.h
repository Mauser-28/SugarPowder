#ifndef STRING_H
#define STRING_H
#include <iostream>
#include <cstring>

class String
{
private:
	char* str;
	size_t stringSize;
	void setStr(const char*); //
public:
	String(); // 1
	String(const char*); // 2
	String(const String&); // 2
	String(String&&); // 2
	String& operator=(const String&); // 3
	String& operator=(String&&); // 4
	~String(); // 5
	
	String& append(const String&); //
	String& append(const char*); //
	const char* c_str() const; //no estb voprosiki
	size_t length() const; //
	String substr(size_t) const; //
	String substr(size_t, size_t) const; //
	char* getStr() const; //
	size_t getLength() const; //
	
	//void setLength(size_t);
	String erase(size_t); //
	String erase(size_t, size_t); //
	/*size_t find(String) const;
	String insert(size_t, String);
	size_t find_first_of(String);
	int32_t find_last_of(String);*/

	String operator+(const String&) const; //
	String operator+(const char*&) const; //
	String& operator+=(const String&); //
	String& operator+=(const char*&); //
	bool operator==(const String&) const; //
	bool operator!=(const String&) const; //
	bool operator<(const String&) const; //
	bool operator>(const String&) const; //
	bool operator<=(const String&) const; //
	bool operator>=(const String&) const; //

	friend std::ostream& operator<<(std::ostream&, const String&); //

	const size_t npos = static_cast<size_t>(-1); //
};

#endif HEADER