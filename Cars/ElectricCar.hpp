#pragma once
#include "ElectricEngine.hpp"
#include "Car.hpp"
class ElectricCar : public Car
{
public:
    ElectricCar(ElectricEngine* engine);
    ~ElectricCar();
    
    void refill() override;

    private:
    void charge();
    ElectricEngine* engine_;
};

