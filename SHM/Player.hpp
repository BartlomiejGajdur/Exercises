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
    

    private:
    std::shared_ptr<Ship> ship_;
    double money_;
    int availableSpace_;
};