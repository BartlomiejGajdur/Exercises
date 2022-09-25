#include "Ship.hpp"

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


void Ship::load(const std::shared_ptr<Cargo> &cargo)
{
    size_t amountOfWholeCargos = 0;
        for (auto &v : getAllCargo())
    {
        amountOfWholeCargos+=v->getAmount();
    }

    if ((getCapacity()-amountOfWholeCargos)>=cargo->getAmount()) {
        cargo_.push_back(cargo);
    }else{
        std::cout<<"No available space!\n";
    } 
    
}

void Ship::printCargo() const{
    for (auto &v: getAllCargo()){
        std::cout<<*v<<std::endl;
     }
}