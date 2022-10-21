#include <iostream>
#include <string>

class MyString : public std::string
{
private:

public:
    MyString(const char* str = "MyString") : std::string(str)
    {
        std::cout << "MyString constructor called" << std::endl;
    }
    ~MyString()
    {
        std::cout << "MyString destructor called" << std::endl;
    }

    //const char* GetValue() const { return _str; }
};

std::ostream& operator<<(std::ostream& out, const MyString& rhs)
{
    out << "MyString:" << rhs.data() << std::endl;
    return out;
}

int main()
{
    MyString str1 = "Hello World!";
    MyString str2("Important Info");

    std::cout << str1 << std::endl;
    std::cout << str2 << std::endl;

    
    return 0;
}
