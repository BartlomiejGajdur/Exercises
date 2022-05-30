#pragma once
#include "ElectricEngine.hpp"
#include "PetrolEngine.hpp"
#include "Car.hpp"
class HybridCar : public Car
{
public:
    HybridCar(PetrolEngine* petrolEng, ElectricEngine* electricEng);
    ~HybridCar();
    
    void charge();
    void refuel();

    PetrolEngine* petrolEngine_;
    ElectricEngine* electricEngine_;
};

