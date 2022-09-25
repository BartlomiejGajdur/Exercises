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

bool Alcohol::operator==(const Alcohol& other){
    return  this->name_ == other.name_ &&
            this->basePrice_== other.basePrice_;
}