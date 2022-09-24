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

void Fruit::print(std::ostream& os) const {
        os<<"Cargo: "<<name_<<" | "
        <<"Amount: " <<amount_<<" | "
        <<"Base Price: "<<basePrice_<<" | "
        <<"Time to spoil: "<<timeToSpoil_<<" days";
    }

std::ostream& operator<<(std::ostream &os, const Fruit& fruit)
    {   
        fruit.print(os);
        return os;
    }