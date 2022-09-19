#pragma once
#include "Coordinates.hpp"
#include <random>

class Island{
    public:
        Island(Coordinates position) : position_(position) {}
        Island(){
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> distrib(1, 100);
            position_.setPositionX(distrib(gen));
            position_.setPositionY(distrib(gen));
        }

    //GETTERS
    Coordinates getPosition() {return position_;}

    //SETTERS


    //OPERATORS
    friend std::ostream& operator<<(std::ostream &os, Island& island);

    private:
        Coordinates position_;


};


std::ostream& operator<<(std::ostream &os, Island& island)
    {       
        os<<island.getPosition();
        return os;
    }