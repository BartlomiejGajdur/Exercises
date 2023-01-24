#pragma once

enum class Color : unsigned char { RED = 0x01, BLUE, GREEN, BLACK };

class Shape
{
public:
    explicit Shape(Color);
    Shape() = default;
    virtual ~Shape() {}
    
    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual void print() const;

    protected:
    
    Color color_{Color::BLACK};
};
