#include "ComplexNumber.h"

// KONSTRUKTORY
ComplexNumber::ComplexNumber(double real, double imag) : _real(real), _imag(imag) {};
ComplexNumber::ComplexNumber(const ComplexNumber& other) : _real(other._real), _imag(other._imag) {};

// GETTEWRY I SETTERY
double ComplexNumber::getImag() const { return _imag; }
double ComplexNumber::getReal() const { return _real; }
void ComplexNumber::setImag(double value) { _imag = value; }
void ComplexNumber::setReal(double value) { _real = value; }


// INNE FUNKCJE
ComplexNumber ComplexNumber::conjugate()
{
	return ComplexNumber(_real, -_imag);
}

ComplexNumber ComplexNumber::abs()
{
	double real = sqrt(_real * _real + _imag * _imag);
	return ComplexNumber(real, 0);
}


// OPERATORY
ComplexNumber operator+(const ComplexNumber& lhs, const ComplexNumber& rhs)
{
	return ComplexNumber(lhs.getReal() + rhs.getReal(), lhs.getImag() + rhs.getImag());
}

bool operator==(const ComplexNumber& lhs, const ComplexNumber& rhs)
{
	return((lhs.getReal() == rhs.getReal()) && (lhs.getImag() == rhs.getImag()));
}

std::ostream& operator<<(std::ostream& out, const ComplexNumber& rhs)
{
	out << rhs.getReal() << " + " << rhs.getImag() << "i";
	return out;
}
