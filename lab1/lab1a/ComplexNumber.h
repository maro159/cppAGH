#pragma once
#include <fstream>

class ComplexNumber
{
private:
	double _real;
	double _imag;

public:
	double getImag() const;
	double getReal() const;
	void setImag(double);
	void setReal(double);

	ComplexNumber conjugate();
	ComplexNumber abs();

	ComplexNumber(double real, double imag);
	ComplexNumber(const ComplexNumber&);
};

ComplexNumber operator+ (const ComplexNumber& lhs, const ComplexNumber& rhs);
bool operator== (const ComplexNumber& lhs, const ComplexNumber& rhs);
std::ostream& operator<< (std::ostream& out, const ComplexNumber& rhs);
