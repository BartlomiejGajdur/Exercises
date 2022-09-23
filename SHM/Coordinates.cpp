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