#pragma once

#include <cmath>
#include <ostream>


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
    bool operator==(const Coordinates &other);
    friend std::ostream& operator<<(std::ostream &os, const Coordinates& position);
    
    //FUNCTIONS
    static size_t distance(const Coordinates& lhs, const Coordinates& rhs); //przeciazanie dla wyso dac
    
 
    private:
        int positionX_;
        int positionY_;

};

