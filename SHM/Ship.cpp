#include "Ship.hpp"
#include <numeric>

Ship& Ship::operator+=(const int num)
    {
        if(crew_+num>maxCrew_)
            {
                std::cerr<<"Too many papays!";
                return *this;
            }else{
                crew_+=num;
                return *this;
            }
    }

Ship& Ship::operator-=(const size_t num)
    {
        if(num>crew_)
            {
                std::cerr<<"Number of papays is lower than 0\n";
                return *this;
            }else{
                crew_-=num;
                return *this;
            }
    }

size_t Ship::getAvailableSpace() { //returns Available space 
    size_t amountOfWholeCargos = 0;
        for (auto &v : getAllCargo())
    {
        amountOfWholeCargos+=v->getAmount();
    }

    return getCapacity() - amountOfWholeCargos;
    
}

void Ship::load(const std::shared_ptr<Cargo> &cargo)
{
    //Sprawdzenie czy towar ktory ma byc dodany nie bedzie zajmowal wicej niż dostępne miejsce na statku 
    if (getAvailableSpace()>=cargo->getAmount()) {
        //Przeszukanie czy na statku jest już taki sam towar
        for (auto &v : getAllCargo())
        {
            if(*cargo == *v){
                *v+=cargo->getAmount();
                return;
            }  
        }
        cargo_.push_back(cargo);
        
    }else{
        std::cout<<"No available space for: "<<cargo->getName()<<" | Amount: "<<cargo->getAmount();
    } 
    
    
}

void Ship::printCargo() const{
    for (auto &v: getAllCargo()){
        std::cout<<*v<<std::endl;
     }
}