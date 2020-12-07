#pragma once
//_Pragma("once")

//#ifndef CIRCLE_H_
//#define CIRCLE_H_

class Circle {
    double radius;
public:
    Circle();
    Circle(double radius);
    double getArea() const;
    double getRadius() const;
    Circle& setRadius(double radius);
};

Circle::Circle() {
    radius = 1.0;
}

Circle::Circle(double radius_) {
    radius = radius_;
}

double Circle::getArea() const{
    return (3.14 * radius * radius);
}

double Circle::getRadius() const{
    return radius;
}

Circle& Circle::setRadius(double radius){
    this->radius = radius;
    return (*this);
    //return (*this)
}




//#endif // !CIRCLE_H_
