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
    void getRandomCoordinates(Coordinates &pos); //Setting random Coordinates for Island
 
    //OPERATORS
    bool operator==(const Island &other);
    friend std::ostream& operator<<(std::ostream &os, Island& island);
     
    private:
     Coordinates position_;


};

