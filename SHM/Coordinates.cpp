#include "Coordinates.hpp"

bool Coordinates::operator==(const Coordinates &other)
    {
        return this->positionX_ == other.positionX_ &&
                this->positionY_ == other.positionY_;
    }

std::ostream& operator<<(std::ostream &os, const Coordinates& position)
    {   
        os<<"X["<<position.getPositionX()<<"] Y["<<position.getPositionY()<<"]";
        return os;
    }

size_t Coordinates::distance(const Coordinates& lhs, const Coordinates& rhs){
    return sqrt(pow(lhs.getPositionX()-rhs.getPositionX(),2) +pow(lhs.getPositionY()-rhs.getPositionY(),2));
}