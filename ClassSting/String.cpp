#define _CRT_SECURE_NO_WARNINGS 
#include "String.h"  ///////!Qwerty1 - Moodle; !Qwerty! - computer


String::String() {
    this->stringSize = 0;
    this->str = new char[1];
    this->str[0] = '\0';
}


String::String(const char*/*&*/ cstr) { // а что с \0 ??? записи типа "" и '\0' 'symbol'
    this->stringSize = std::strlen(cstr);
    this->str = new char[this->stringSize + 1];
    std::strcpy(this->str, cstr);
}


String::String(const String& s) : str(new char[s.stringSize + 1]), stringSize(s.stringSize){
    std::strcpy(this->str, s.str);
}


String::String(String&& val) : str(val.str), stringSize(val.stringSize) {
    val.str = nullptr;
    val.stringSize = 0;
}

String& String::operator=(const String& rhs) {
    if (this != &rhs) {
        this->setStr(rhs.str);
    }
    return *this;
}

String& String::operator= (String&& val)  {
    this->str = val.str;
    this->stringSize = val.stringSize;
    val.str = nullptr;
    val.stringSize = 0;
    return *this;
}

String::~String() {
    delete[] str;
    str = nullptr;
}


String& String::append(const String& rhs) {
    char* newData = new char[this->stringSize + rhs.stringSize + 1];
    std::strcpy(newData, this->str);
    std::strcat(newData, rhs.str);
    delete[] this->str;
    this->stringSize += rhs.stringSize;
    this->str = newData;
    return *this;
}


String& String::append(const char* cstr) {
    String str(cstr);
    return this->append(str);
}


const char* String::c_str() const {
    char* temp = new char[this->stringSize + 1];
    std::strcpy(temp, this->str);
    return temp;
}


size_t String::length() const { // считается по байтам а не по колву эл-тов
    return this->stringSize;
}


String String::substr(const size_t start, size_t count) const { // совет: уменьшить в будущем start на 1
    if (start >= this->stringSize) {
        return String();
    }
    if (start + count > this->stringSize) {
        count = this->stringSize - start;
    }
    String result;
    result.stringSize = count;
    result.str = new char[count + 1]; // два раза new хорошо это или плохо? но я думаю что здесь лучше поступить так
    for (size_t i = 0; i < count; ++i) {
        result.str[i] = this->str[start + i];
    }
    result.str[count] = '\0';
    return result;
}


String String::substr(const size_t start) const {
    return this->substr(start, this->stringSize - start);
}


char* String::getStr() const {
    return this->str;
}


size_t String::getLength() const {
    return this->stringSize;
}


void String::setStr(const char* cstr) {
    delete[] this->str;
    this->stringSize = std::strlen(cstr);
    this->str = new char[this->stringSize + 1];
    std::strcpy(this->str, cstr);
}
//
//
//void String::setLength(size_t newLength) {
//    this->stringSize = newLength;
//}


//String String::erase(const size_t start, size_t count) { // совет: уменьшить в будущем start на 1 aboba
//    if (start >= this->stringSize || count == 0) {
//        return *this;
//    }
//    if (start + count > this->stringSize) {
//        count = this->stringSize - start;
//    }
//    size_t newlength = this->stringSize - count;
//    char* newstr = new char[newlength + 1];
//    for (size_t i{}; i < start; ++i) {
//        newstr[i] = this->str[i];
//    }
//    for (size_t i{ start + count }; i < this->stringSize; ++i) {
//        newstr[i - count] = str[i];
//    }
//    newstr[newlength] = '\0';
//    return String(newstr);
//}

String String::erase(const size_t start, size_t count) { // "this text have no sense" start = 3 count = 4
    return this->substr(0, start) + this->substr(start + count);
}

String String::erase(const size_t start) {
    return this->erase(start, this->stringSize - start);
}





String String::operator+(const String& rhs) const {
    String temp = *this;
    return temp += rhs;
}


String String::operator+(const char*& rhs) const {
    String temp = *this;
    return temp += rhs;
}


String& String::operator+=(const String& str) {
    return this->append(str);
}


String& String::operator+=(const char*& cstr) {
    return this->append(cstr);
}























bool String::operator==(const String& s1) const {
    if (this->stringSize != s1.stringSize) {
        return false;
    }
    return std::strcmp(str, s1.str) == 0;
}


bool String::operator!=(const String& s1) const {
    return !(*this == s1);
}


bool String::operator<(const String& rhs) const {
    return std::strcmp(this->str, rhs.str) < 0;
}


bool String::operator>(const String& rhs) const {
    return rhs < *this;
}


bool String::operator<=(const String& rhs) const {
    return !(*this > rhs);
}


bool String::operator>=(const String& rhs) const {
    return !(*this < rhs);
}


std::ostream& operator<<(std::ostream& os, const String& rhs) {
    os << rhs.str;
    return os;
}



























//size_t String::find(String s1) const
//{
//    if (this->stringSize < s1.stringSize)
//    {
//        return npos;
//    }
//    for (size_t i{}; i <= ((*this).length() - s1.length()); ++i)
//    {
//        if (s1.substr(i, (*this).length()) == (*this))
//        {
//            return i;
//        }
//    }
//    return npos;
//}


//String String::insert(size_t start, String st)
//{
//    if (start > static_cast<size_t>(this->stringSize))
//    {
//        return *this;
//    }
//
//    size_t resultLength = this->stringSize + st.stringSize;
//    char* newStr = new char[resultLength + 1];
//
//
//    for (size_t i{}; i < start; ++i)
//    {
//        newStr[i] = this->str[i];
//    }
//
//    for (size_t i{}; i < static_cast<size_t>(st.stringSize); ++i)
//    {
//        newStr[start + i] = st.str[i];
//    }
//
//
//    for (size_t i{ start }; i < static_cast<size_t>(this->stringSize); ++i)
//    {
//        newStr[st.stringSize + i] = this->str[i];
//    }
//
//    newStr[resultLength] = '\0';
//
//    String result(newStr);
//    delete[] newStr;
//    return result;
//}


//size_t String::find_first_of(String s1)
//{
//    for (size_t i{}; i < static_cast<size_t>(this->stringSize); ++i)
//    {
//        for (size_t j{}; j < static_cast<size_t>(s1.stringSize); ++j)
//        {
//            if (this->str[i] == s1.str[j])
//            {
//                return i;
//            }
//        }
//    }
//    return npos;
//}


//size_t String::find_last_of(String s1)
//{
//    for (int32_t i{ this->stringSize - 1 }; i >= 0; --i)
//    {
//        for (size_t j{}; j < static_cast<size_t>(s1.stringSize); ++j)
//        {
//            if (this->str[i] == s1.str[j])
//            {
//                return static_cast<size_t>(i);
//            }
//        }
//    }
//    return npos;
//}