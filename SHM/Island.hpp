#pragma once
#include "Coordinates.hpp"
#include <random>

constexpr size_t kWidth = 100;
constexpr size_t kHeight = 100;

class Island{
    public:
        Island(Coordinates position) : position_(position) {}
        Island(int positionX ,int positionY){
            position_.setPositionX(positionX);
            position_.setPositionY(positionY);
        }
        Island(){
            getRandomCoordinates(position_);
        }

    //GETTERS
    Coordinates getPosition() {return position_;}

    //SETTERS


    //Functions
    void getRandomCoordinates(Coordinates &pos) //Setting random Coordinates for Island
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> widthGen(1, kWidth);
        std::uniform_int_distribution<> heightGen(1, kHeight);
        pos.setPositionX(widthGen(gen));
        pos.setPositionY(heightGen(gen));
    }

    //OPERATORS
    friend std::ostream& operator<<(std::ostream &os, Island& island);

    bool operator==(const Island &other)
    {
        return this->position_.getPositionX() == other.position_.getPositionX() &&
                this->position_.getPositionY() == other.position_.getPositionY();
    }

     
    private:
     Coordinates position_;


};


std::ostream& operator<<(std::ostream &os, Island& island)
    {       
        os<<island.getPosition();
        return os;
    }