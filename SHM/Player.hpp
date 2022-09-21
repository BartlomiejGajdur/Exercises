#pragma once
#include <memory>
#include <iostream>
#include "Ship.hpp"


class Player{
    public:
    Player(std::shared_ptr<Ship> ship, double money, int availableSpace): 
                                                                    ship_(ship), 
                                                                    money_(money),
                                                                    availableSpace_(availableSpace) {}
    //GETTERS
    std::shared_ptr<Ship> getShip() const {return ship_;}
    double getMoney()               const {return money_;}
    int getAvailableSpace()         const {return availableSpace_;}
    //SETTERS


    //OPERATORS

    private:
    std::shared_ptr<Ship> ship_;
    double money_;
    int availableSpace_;
};