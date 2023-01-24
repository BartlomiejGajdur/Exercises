#pragma once

#include "Shape.hpp"

class Rectangle : public Shape
{
public:
    using Shape::Shape;
    Rectangle(double x, double y);
    Rectangle(const Rectangle & other);

    double getArea() const;
    double getPerimeter() const;
    double getX() const;
    double getY() const;
    void print() const;

private:
    Rectangle();

    double x_{};
    double y_{};
};
