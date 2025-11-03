#include <iostream>

class Complex {
	int64_t re;
	int64_t im;



public:
	
	Complex();
	Complex(int64_t, int64_t);
	Complex(const Complex&);
	Complex(Complex&& other) noexcept;
	~Complex() = default;

	void setRe(const int64_t);
	void setIm(const int64_t);

	int64_t getRe() const;
	int64_t getIm() const;
	
	double arg() const;
	double abs() const;

	Complex pow(double) const;
	Complex root(int32_t n) const;
	
	

	Complex operator- (Complex&); //
	Complex operator+ (const Complex); //
	Complex operator* (const Complex); //

	Complex& operator+= (const Complex); //
	Complex& operator-= (const Complex); //
	Complex& operator*= (const Complex); //
	
	Complex operator- () const; //
	Complex operator~ (); //
	Complex operator/ (Complex&);
	Complex operator++(); //
	Complex operator++(int); //
	
	friend std::ostream& operator<<(std::ostream& os, const Complex& A);
};


int main() {
	Complex b{ 12, -32 };
	Complex a{ 12, 32 };
	std::cout<< a + b; // a.getIm()
	int ac{ 5 };
	int dc{ 4 };

	return 0;
}


Complex::Complex() {
	this->re = 0;
	this->im = 0;
}


Complex::Complex(int64_t re, int64_t im) {
	this->re = re;
	this->im = im;
}


Complex::Complex(const Complex& complexNum) {
	this->re = complexNum.re;
	this->im = complexNum.im;
}


Complex::Complex(Complex&& complexNum) noexcept {
	this->re = complexNum.re;
	this->im = complexNum.im;
	complexNum.re = 0;
	complexNum.im = 0;
}


Complex Complex::operator+(const Complex rhs) {
	return Complex(this->re + re, this->im + im);
}


Complex Complex::operator-() const{
	return Complex(-this->re, -this->im);
}


Complex Complex::operator-(Complex& rhs) {
	return (*this) + -rhs;
}


Complex Complex::operator* (const Complex rhs) {
	return Complex(this->re * rhs.re - this->im * rhs.im, this->re * rhs.im + this->im * rhs.re);
}


Complex& Complex::operator+= (const Complex rhs) {
	this->re += re;
	this->im += im;
	return *this;
}


Complex& Complex::operator-= (const Complex rhs) {
	return *this += -rhs;
}


Complex& Complex::operator*= (const Complex rhs) {
	this->re = this->re * rhs.re - this->im * rhs.im;
	this->im = this->re * rhs.im + this->im * rhs.re;
	return *this;
}


Complex Complex::operator~ () {
	return Complex(this->re, -this->im);
}


Complex Complex::operator/ (Complex& rhs) {
	return Complex(*(this) * (~rhs));
}


Complex Complex::operator++ () {
	return Complex(++this->re, this->im);
}


Complex Complex::operator++(int) {
	Complex temp = *this;
	++*this;
	return temp;
}


void Complex::setRe(const int64_t num) {
	this->re = num;
}


void Complex::setIm(const int64_t denum) {
	this->im = denum;
}


int64_t Complex::getRe() const {
	return this->re;
}


int64_t Complex::getIm() const {
	return this->im;
}


double Complex::arg() const {
	return std::atan2(im, re);
}

double Complex::abs() const {
	return std::sqrt(this->re * this->re + this->im * this->im);
}


Complex Complex::pow(double n) const {
	double mod = this->abs();
	double arg = this->arg();
	double new_mod = std::pow(mod, n);
	double new_arg = n * arg;
	return Complex(new_mod * std::cos(new_arg), new_mod * std::sin(new_arg));
}

Complex Complex::root(int32_t n) const {
	if (n == 0) {
		throw std::invalid_argument("Error root 0 dont exist");
	}
	double mod = this->abs();
	double arg = this->arg();
	double new_mod = std::pow(mod, 1.0 / n);
	double new_arg = arg / n;
	return Complex(new_mod * std::cos(new_arg), new_mod * std::sin(new_arg));
}


std::ostream& operator<<(std::ostream& os, const Complex& complexNum) {
	os << complexNum.re << complexNum.im;
	return os;
}