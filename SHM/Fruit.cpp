#include "Fruit.hpp"

double Fruit::getPrice() const{
     return basePrice_* (timeToSpoil_ /expire_date_);
}

Fruit& Fruit::operator--()
{
    if(timeToSpoil_>0){
        --timeToSpoil_;
        return *this;
    }else{
        return *this;
    }

}