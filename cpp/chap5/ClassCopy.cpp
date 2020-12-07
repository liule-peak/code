 #include<iostream>
using namespace std;

class Circle
{
public:
    double radius;
    Circle()
    {
        radius = 1.0;
    }
    Circle(double newRadius)
    {
        radius = newRadius;
    }
    double getArea()
    {
        return (3.14 * radius * radius);
    }
};

int main(){
    Circle c1 = Circle{1.1};
    auto c2 = Circle{2.2};

    Circle c3{};
    c3 = Circle{3.3};

    cout << Circle{4.2}.getArea() << endl;
    cout << Circle().getArea() << endl;
    cout << Circle(5).getArea() << endl;
    return 0;
}