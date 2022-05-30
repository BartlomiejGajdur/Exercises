#pragma once
#include "PetrolEngine.hpp"
#include "Car.hpp"
class PetrolCar : public Car
{
public:
    PetrolCar(PetrolEngine* engine);
    ~PetrolCar();

private:
    void refuel();
    PetrolEngine* engine_;
};

