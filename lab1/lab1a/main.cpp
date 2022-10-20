#include "ComplexNumber.h"
#include <iostream>

using namespace std;

void main()
{
	ComplexNumber c1(1, 2);
	ComplexNumber c2(2, 3);
	
	cout << "c1 = " << c1 << endl;
	cout << "c2 = " << c2 << endl;
	ComplexNumber c3 = c1 + c2;
	cout << "c3 = c1 + c2 = " << c3 << endl;
	cout << "if c3 == c2? " << (c3 == c2) << endl;
	
	cout << "conjugate of c3 = " << c3.conjugate() << endl;
	cout << "abs of c3 = " << c3.abs() << endl;


}