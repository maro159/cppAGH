#include <iostream>
#include <limits>

class TQuadEq
{
private:
    double _a;
    double _b;
    double _c;

public:
    TQuadEq() : _a(0.0), _b(0.0), _c(0.0) {};
    TQuadEq(double a, double b, double c) : _a(a), _b(b), _c(c) {};


    double GetA() const { return _a; }
    double GetB() const { return _b; }
    double GetC() const { return _c; }

    void SetA(const double value) { _a = value; }
    void SetB(const double value) { _b = value; }
    void SetC(const double value) { _c = value; }

    double ComputeDelta() const
    {
        return _b * _b - 4 * _a * _c;
    }

    int GetNumRoots(const double delta)
    {
        if (delta < 0) { return 0; }
        else if (delta > 0) { return 2; }
        else { return 1; }
    }

    void GetRoots(double& root1, double& root2) const
    {
        root1 = (-_b + sqrt(ComputeDelta())) / (2 * _a);
        root2 = (-_b - sqrt(ComputeDelta())) / (2 * _a);
    }

};


int main()
{
    double a = std::numeric_limits<double>::signaling_NaN();
    double b = std::numeric_limits<double>::signaling_NaN();
    double c = std::numeric_limits<double>::signaling_NaN();
    double root1 = std::numeric_limits<double>::signaling_NaN();
    double root2 = std::numeric_limits<double>::signaling_NaN();

    std::cout << "Enter coefficients for a+b^2+c=0 quadratic equation" << std::endl;
    std::cout << "a:\t";
    std::cin >> a;
    std::cout << "b:\t";
    std::cin >> b;
    std::cout << "c:\t";
    std::cin >> c;
    
    TQuadEq sq1(a, b, c);
    int delta = sq1.ComputeDelta();
    int rootNum = sq1.GetNumRoots(delta);
    sq1.GetRoots(root1, root2);


    std::cout << "RESULTS:\n" << std::endl;
    std::cout << "delta = " << sq1.ComputeDelta() << std::endl;
    std::cout << "number of real roots = " << rootNum << std::endl;
    std::cout << "root1 = " << root1 << std::endl;
    std::cout << "root2 = " << root2 << std::endl;
    return 0;

}  