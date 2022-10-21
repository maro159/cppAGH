#include <iostream>

using namespace std;

class Number
{
public:
	virtual void print(ostream& out) const {};
};

class Complex : public Number
{
private:
	double _a;
	double _b;

public:
	Complex(double a = 0.0, double b = 0.0) : _a(a), _b(b) {}
	
	double GetA() const { return _a; }
	double GetB() const { return _b; }
	void SetA(double value) { _a = value; }
	void SetB(double value) { _b = value; }

	void print(ostream& out) const
	{
		string sign;
		if (_b < 0)
		{
			sign = " ";
		}
		else
		{
			sign = " + ";
		}
		out << _a << sign << _b << "i";
	}
};

class Real : public Complex
{
public:
	Real(double x = 0) : Complex(x,0) {}

	void print(ostream& out)	const
	{
		out << GetA();
	}
};

class Rational : public Number
{
private :
	int _l;
	int _m;

public:
	Rational(int l, int m) : _l(l), _m(m) {}

	int GetL() const { return _l; }
	int GetM() const { return _m; }
	void SetL(int value) { _l = value; }
	void SetM(int value) { _m = value; }

	void print(ostream& out) const
	{
		out << _l << " / " << _m;
	}

};


ostream& operator<<(std::ostream& out, const Number& rhs)
{
	rhs.print(out);
	return out;
}

int main()
{
	Number* x1 = new Complex(3, -2);
	Number* x2 = new Real(5);
	Number* x3 = new Rational(2,6);
	cout << *x1 << endl;
	cout << *x2 << endl;
	cout << *x3 << endl;
}
