  #include "Island.hpp"
  
void Island::setRandomCoordinates(Coordinates &pos) //Setting random Coordinates for Island
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> widthGen(1, kWidth);
        std::uniform_int_distribution<> heightGen(1, kHeight);
        pos.setPositionX(widthGen(gen));
        pos.setPositionY(heightGen(gen));
    }

bool Island::operator==(const Island &other)
    {
        return this->position_.getPositionX() == other.position_.getPositionX() &&
                this->position_.getPositionY() == other.position_.getPositionY();
    }


std::ostream& operator<<(std::ostream &os, Island& island)
    {       
        os<<island.getPosition();
        return os;
    }

size_t Island::distance(const Island& lhs, const Island& rhs){
    return sqrt(pow(lhs.getPosition().getPositionX()-rhs.getPosition().getPositionX(),2) 
               +pow(lhs.getPosition().getPositionY()-rhs.getPosition().getPositionY(),2));
}