#include "PetrolCar.hpp"
#include "ElectricCar.hpp"
#include "HybridCar.hpp"
#include <iostream>
#include "Car.hpp"

int main()
{
    std::cout << std::endl << "OPEL" << std::endl;
    PetrolCar opel(new PetrolEngine(120, 1800, 6));
    opel.accelerate(50);
    opel.brake();
    opel.accelerate(-900);
    opel.refill();

    std::cout << std::endl << "NISSAN" << std::endl;
    ElectricCar nissan(new ElectricEngine(130, 650));
    nissan.refill();
    nissan.accelerate(80);
    //nissan.engine_ = new ElectricEngine(150, 700);  // Changing an engine during driving is not safe
    nissan.changeEngine(new ElectricEngine(150, 700));
    nissan.turnLeft();

    std::cout << std::endl << "TOYOTA" << std::endl;
    HybridCar toyota(new PetrolEngine(80, 1400, 5), new ElectricEngine(100, 540));
    toyota.accelerate(100);
    toyota.brake();
    toyota.refill();
   
}
