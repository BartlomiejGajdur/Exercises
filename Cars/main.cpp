#include "PetrolCar.hpp"
#include "ElectricCar.hpp"
#include "HybridCar.hpp"
#include <iostream>
#include "Car.hpp"

int main()
{
    std::cout << std::endl << "OPEL" << std::endl;

    PetrolCar opel(new PetrolEngine(120, 1800, 6));
    Car* car = &opel;    
    PetrolCar* petCar = dynamic_cast<PetrolCar*>(car);

    car->accelerate(50);
    car->brake();
    car->accelerate(-900);
    car->refill();
    petCar->changeEngine(new PetrolEngine(150, 700, 7));
    car->refill();
    
    std::cout << std::endl << "NISSAN" << std::endl;

    ElectricCar nissan(new ElectricEngine(130, 650));
    car = & nissan;
    ElectricCar* eleCar = dynamic_cast<ElectricCar*>(car);

    car->refill();
    car->accelerate(80);
    //nissan.engine_ = new ElectricEngine(150, 700);  // Changing an engine during driving is not safe
    eleCar->changeEngine(new ElectricEngine(150, 700));
    car->turnLeft();

    std::cout << std::endl << "TOYOTA" << std::endl;
    HybridCar toyota(new PetrolEngine(80, 1400, 5), new ElectricEngine(100, 540));
    car = &toyota;
    car->accelerate(100);
    car->brake();
    car->refill();


   
}
