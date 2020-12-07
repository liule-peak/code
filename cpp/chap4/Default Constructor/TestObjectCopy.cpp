#include<iostream>

class Square
{
private:
    double side = 1.0; /* data */
public:
    Square() = default; 
    Square(double side/* args */)
    {
        this->side = side;
    }
    double getArea(){
        return (side * side);
    }
};

int main(){
    Square s1, s2{4.0};
    std::cout << s1.getArea() << std::endl;
    std::cout << s2.getArea() << std::endl;

    s1 = s2;

    std::cout << s1.getArea() << std::endl;
    std::cout << s2.getArea() << std::endl;
}
