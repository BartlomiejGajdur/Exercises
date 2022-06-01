#pragma once
#include "Engine.hpp"
class ElectricEngine : public Engine
{
public:
    ElectricEngine(int power, int batteryCapacity);

    private:
    int power_;             // in HP 
    int batteryCapacity_;   // in Ah
};

