#pragma once
#include "PetrolEngine.hpp"
#include "Car.hpp"
class PetrolCar : public virtual Car
{
public:
    PetrolCar(PetrolEngine* engine);
    ~PetrolCar();

    void refill() override;
    void changeEngine(PetrolEngine* ee);
private:
    void refuel();
    PetrolEngine* engine_;
};

