#pragma once
#include <iostream>
#include "Engine.hpp"

class Car{
    public:
        void turnLeft() ;
        void turnRight();
        void brake() ;
        void accelerate(int speed);
        virtual void refill() = 0;
        void changeEngine(Engine* eng);
        virtual ~Car(){};
};