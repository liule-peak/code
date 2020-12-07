#include<iostream>
#include<cmath>
using namespace std;

class Complex
{
private:
    double real;
    double image; /* data */
public:
    Complex(double r,double i):real(r),image(i){};
    void operator-=(Complex &x);
    void display(string);
    ~Complex();
};

void Complex::operator-=(Complex &a/* args */)
{
    real = this->real - a.real;
    image = this->image - a.image;
}

void Complex::display(string str)
{
    cout << str << "(" << real << "," << image << ")" << endl;
}

Complex::~Complex()
{
}

int main()
{
    Complex c1{10, 20}, c2{15, 30};
    c1.display("c1");
    c2.display("c2");
    c2 -= c1;
    cout << "c2-=c1" << endl;
    c1.display("c1");
    c2.display("c2");
    return (0);
}