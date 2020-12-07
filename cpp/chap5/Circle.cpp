#include<iostream>

class Circle{
    public:
        double radius;
        Circle(){
            radius = 1.0;
        }
        Circle(double newRadius){
            radius = newRadius;
        }
        double getArea(){
            return (3.14 * radius * radius);
        }
};


int main(){
    Circle circle1;
    Circle circle2{2.0};

    std::cout << circle1.getArea() << std::endl;
    std::cout << circle2.getArea() << std::endl;

    return (0);
}