#pragma once
#include <iostream>

class Car{
    public:
        void turnLeft() ;
        void turnRight();
        void brake() ;
        void accelerate(int speed);
        virtual void refill() = 0;
        ~Car(){};
};