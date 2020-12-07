#include<iostream>
#include"Circle.h"
using std::cout;
using std::endl;

int main(){
    Circle c{1.0};

    cout << c.setRadius(2.0).setRadius(3.0).getArea() << endl;
    return (0);
}