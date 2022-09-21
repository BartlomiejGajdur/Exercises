#pragma once
#include <memory>
#include <iostream>
#include "Ship.hpp"
#include "Cargo.hpp"


class Player{
    public:
    Player(std::shared_ptr<Ship> ship, double money): 
                                                    ship_(ship), 
                                                    money_(money) {}
    std::shared_ptr<Ship> getShip() const {return ship_;}
    double getMoney()               const {return money_;}
    //SETTERS


    //OPERATORS

    
    //Functions
    size_t getSpeed() const{
       return ship_->getSpeed();
    }
    
    // std::shared_ptr<Cargo> getCargo(size_t index) const{ //Function shall return Cargo searching by Idex? (Dont know what idex is? Name ?)
        
    // }

    size_t getAvailableSpace() const{ //Checking the whole vector Cargos from Ship. Add all values then substract with Capacity _return AvailableSpace_;
        size_t amountOfWholeCargos = 0;
        for (auto &v : ship_->getAllCargo())
        {
            amountOfWholeCargos+=v->getAmount();
        }
        return ship_->getCapacity()-amountOfWholeCargos;
    }
    
    private:
    std::shared_ptr<Ship> ship_;
    double money_;
    int availableSpace_;
};