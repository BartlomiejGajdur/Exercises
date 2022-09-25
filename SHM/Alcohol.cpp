#include "Alcohol.hpp"

void Alcohol::print(std::ostream& os) const { 
        os<<"Cargo: "<<name_<<" | "
        <<"Amount: " <<amount_<<" | "
        <<"Base Price: "<<basePrice_<<" | "
        <<"Percentage: "<<percentage_<<" days";
    }

std::ostream& operator<<(std::ostream &os, const Alcohol& alcohol)
    {   
        alcohol.print(os);
        return os;
    }

bool Alcohol::operator==(const Cargo& otherAlcohol){
    return  this->name_ == otherAlcohol.getName() &&
            this->basePrice_== otherAlcohol.getBasePrice();
}

Alcohol& Alcohol::operator+=(const size_t amount)
    {      
        amount_+=amount;
        return *this;
    }     

Alcohol& Alcohol::operator-=(const size_t amount)
    {
        amount_-=amount;
        return *this;
    }   