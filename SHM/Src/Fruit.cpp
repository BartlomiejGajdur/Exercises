#include "../Include/Fruit.hpp"

double Fruit::getPrice() const{
     return basePrice_* (timeToSpoil_ /expire_date_);
}

Fruit& Fruit::operator--()
{
    if(timeToSpoil_>0){
        --timeToSpoil_;
        return *this;
    }else{
        std::cout<<"Rotten!";
        return *this;
    }

}

void Fruit::print(std::ostream& os) const {
        os<<"Cargo: "<<name_<<" | "
        <<"Amount: " <<amount_<<" | "
        <<"Base Price: "<<basePrice_<<" | "
        <<"Time to spoil: "<<timeToSpoil_<<" days\n";
    }



bool Fruit::operator==(const Cargo& otherFruit){
        return  this->name_ == otherFruit.getName()&&
            this->basePrice_== otherFruit.getBasePrice();
    
}

Fruit& Fruit::operator+=(const size_t amount)
    {      
        amount_+=amount;
        return *this;
    }     

Fruit& Fruit::operator-=(const size_t amount)
    {
        if (amount_-amount>0)
        {
            amount_-=amount;
        }
            return *this;
        
    }   

void Fruit::nextDay(){
    operator--();
}