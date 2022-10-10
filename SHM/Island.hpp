#pragma once
#include "Coordinates.hpp"
#include "Store.hpp"
#include "Cargo.hpp"
#include <random>

constexpr size_t kWidth = 100;
constexpr size_t kHeight = 100;

//Need to fix buying from Shop in Island. No removeing iteam from vector if amount == cargo amount.
class Island{
    public:
        Island(Coordinates position) : position_(position) {}
        Island(int positionX ,int positionY){
            position_.setPositionX(positionX);
            position_.setPositionY(positionY);
        }
        Island(){
            setRandomCoordinates(position_);     
        }
        ~Island(){}

    //GETTERS
    Coordinates getPosition() const   {return position_;}
    Store getStore() {return store_;}
    //SETTERS


    //Functions
    void setRandomCoordinates(Coordinates &pos); //Setting random Coordinates for Island
    void printCargo() const {store_.printCargo();}
    //OPERATORS
    bool operator==(const Island &other);
    friend std::ostream& operator<<(std::ostream &os, Island& island);
    
    private:
     Coordinates position_;
     Store store_;


};

