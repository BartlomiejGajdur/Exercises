#pragma once
#include "ElectricEngine.hpp"
#include "Car.hpp"
class ElectricCar : virtual public Car
{
public:
    ElectricCar(ElectricEngine* engine);
    ~ElectricCar();
    
    void refill() override;
    //void changeEngine(ElectricEngine* ee);

private:
    void charge();
    ElectricEngine* engine_;
};

