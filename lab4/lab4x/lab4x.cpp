#include <iostream>
#include<fstream>
template <typename T>
void solve_equation(T a, T b, T c)
{
    T delta = b * b - 4 * a * c;
    if (delta == 0)
    {
        std::cout << "x0=" << -b / 2*a << std::endl;
    }
    else if (delta < 0)
    {
        std::cout << "Brak rozwiazan rzeczywistych";
    }
    else
    {
        std::cout << "x1 = " << -b + (T)sqrt(delta) / 2 * a << std::endl;
        std::cout << "x2 = " << -b - (T)sqrt(delta) / 2 * a << std::endl;
    }
}

template<typename T> class ValueContainer
{
private:
    T a;
public:
    ValueContainer(T value = 0) : a(value){}

    ValueContainer& operator++ ()
    {
        ++a;
        return *this;
    }

    T get_a() const { return a; }
    void set_a(T new_a) { a = new_a; }

};

template<typename T>
std::ostream& operator<< (std::ostream& out, const ValueContainer<T>& rhs)
{
    out << rhs.get_a();
    return out;
}

template<> class ValueContainer<char>
{
private:
    char a;
public:
    ValueContainer(char value = 0) : a(value) {}
    ValueContainer& operator++ ()
    {
        a = std::toupper(a);
        return *this;
    }

    char get_a() const { return a; }
    void set_a(char new_a) { a = new_a; }


};

template<typename T=float, int p=3>
T PowIt(T x)
{
    T tmp = x;
    for (size_t i = 1; i < p; i++)
    {
        tmp *= x;
    }
    return tmp;
}

void zad1()
{
    std::cout << "** ZADANIE 1 **\n" << std::endl;
    int a;
    int b;
    int c;

    std::cout << "Wprowadz a" << std::endl;
    std::cin >> a;


    std::cout << "Wprowadz b" << std::endl;
    std::cin >> b;

    std::cout << "Wprowadz c" << std::endl;
    std::cin >> c;

    solve_equation(a, b, c);
}

void zad23()
{
    std::cout << "** ZADANIE 23 **\n" << std::endl;
    int a;
    std::cout << "Podaj a:" << std::endl;
    std::cin >> a;

    ValueContainer<int> test(a);
    std::cout << ++test << std::endl;

    char b;
    std::cout << "Podaj b:" << std::endl;
    std::cin >> b;
    ValueContainer<char> test2(b);
    std::cout << ++test2<< std::endl;
}

void zad4()
{
    std::cout << "** ZADANIE 4 **\n" << std::endl;
    float a = 2.5;
    int b = 3;
    std::cout << PowIt<float>(a) << std::endl;
    std::cout << PowIt<int>(b) << std::endl;

}


int main()
{
    zad1();
    zad23();
    zad4();
}

