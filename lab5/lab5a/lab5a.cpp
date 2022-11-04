#define _USE_MATH_DEFINES

#include <iostream>
#include<cmath>

using namespace std;

class Shape
{
protected:
    string m_color;
public:
    virtual float get_area() const = 0;
};

class IMovable
{
public:
    virtual void move(float dx, float dy) = 0;
    virtual void move_to_origin() = 0;
};

class IPrintable
{
public:
    virtual void print() const = 0;
};

class Circle : public Shape, public IMovable, public IPrintable
{
private:
    float m_x, m_y;
    float m_r;
public:
    Circle(float x, float y, float r, string color) : m_x(x), m_y(y), m_r(r) { m_color = color; }
    float get_x(void) const { return m_x; }
    float get_y(void) const { return m_y; }
    float get_r(void) const { return m_r; }
    string get_color(void) const { return m_color; }

    void set_x(float x) { m_x = x; }
    void set_y(float y) { m_y = y; }
    void set_r(float r) { m_r = r; }
    void set_color(string color) { m_color = color; }

    float get_area() const
    {
        return M_PI * m_r * m_r;
    }

    void move(float dx, float dy)
    {
        m_x += dx;
        m_y += dy;
    }
    void move_to_origin()
    {
        m_x = 0;
        m_y = 0;
    }
    void print() const
    {
        cout << "Type:\t" << typeid(this).name() << endl;
        cout << "Color:\t" << get_color() << endl;
        cout << "Position:\t" << get_x() << "," << m_y << endl;
        cout << "Radius:\t" << get_r() << endl;
        cout << "Area:\t" << get_area() << endl;
    }
};


class Rectangle : public Shape, public IMovable, public IPrintable
{
private:
    float m_x, m_y;
    float m_xsize, m_ysize;
public:
    Rectangle(float x, float y, float xsize, float ysize, string color) : m_x(x), m_y(y), m_xsize(xsize), m_ysize(ysize) { m_color = color; }
    float get_x(void) const { return m_x; }
    float get_y(void) const { return m_y; }
    float get_xsize(void) const { return m_xsize; }
    float get_ysize(void) const { return m_ysize; }
    string get_color(void) const { return m_color; }

    void set_x(float x) { m_x = x; }
    void set_y(float y) { m_y = y; }
    void set_xsize(float xsize) { m_xsize = xsize; }
    void set_ysize(float ysize) { m_ysize = ysize; }
    void set_color(string color) { m_color = color; }

    float get_area() const
    {
        return m_xsize * m_ysize;
    }

    void move(float dx, float dy)
    {
        m_x += dx;
        m_y += dy;
    }
    void move_to_origin()
    {
        m_x = 0;
        m_y = 0;
    }
    void print() const
    {
        cout << "Type:\t" << typeid(this).name() << endl;
        cout << "Color:\t" << get_color() << endl;
        cout << "Position:\t" << get_x() << "," << m_y << endl;
        cout << "Size:\t" << get_xsize() << "," << get_ysize() << endl;
        cout << "Area:\t" << get_area() << endl;
    }
};


int main()
{
    Circle test3(2, 2, 5, "black");
    Rectangle test4(2, 2, 4, 5, "black");

    test3.print();
    cout << endl;
    test4.print();
    cout << endl;
    cout << endl;
    test3.move(4, 3);
    test4.move_to_origin();
    test3.print();
    cout << endl;
    test4.print();
    cout << endl;

    //IPrintable* lista[] = { &test3, &test4 };
    //for (IPrintable* obj : lista) 
    //{
    //    obj->print();
    //}
}
