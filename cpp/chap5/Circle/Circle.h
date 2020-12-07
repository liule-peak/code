#pragma once
//_Pragma("once")

//#ifndef CIRCLE_H_
//#define CIRCLE_H_

class Circle {
    double radius;
public:
    Circle();
    Circle(double radius);
    double getArea();
};

Circle::Circle() {
    radius = 1.0;
}

Circle::Circle(double radius_) {
    radius = radius_;
}

double Circle::getArea() {
    return (3.14 * radius * radius);
}




//#endif // !CIRCLE_H_
