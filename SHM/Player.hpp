#pragma once
#include <memory>
#include "Ship.hpp"


class Player{
    public:



    private:
    std::shared_ptr<Ship> ship_;
    double money_;
    int availableSpace_;
};