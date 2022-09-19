#pragma once
#include <iostream>
#include <string>

class Coordinates{
    public:
        Coordinates(int positionX, int positionY) : 
                                                    positionX_(positionX), 
                                                    positionY_(positionY) {}
        Coordinates(){}                                            
    //GETTERS
    int getPositionX() const {return positionX_;}
    int getPositionY() const {return positionY_;}


    //SETTERS
    void setPositionX(const int positionX) {positionX_=positionX;}
    void setPositionY(const int positionY) {positionY_=positionY;}

    //OPERATORS
    bool operator==(const Coordinates &other)
    {
        return this->positionX_ == other.positionX_ &&
                this->positionY_ == other.positionY_;
    }

    friend std::ostream& operator<<(std::ostream &os, const Coordinates& position);

    
 
    private:
        int positionX_;
        int positionY_;

};

std::ostream& operator<<(std::ostream &os, const Coordinates& position)
    {   
        os<<"X["<<position.getPositionX()<<"] Y["<<position.getPositionY()<<"]";
        return os;
    }