#include "DryFruit.hpp"
DryFruit::DryFruit(const std::string& name, size_t amount, double basePrice): 
                                                                    Fruit(name,amount,basePrice) {}

double DryFruit::getPrice() const {  
     return 3*basePrice_* (timeToSpoil_ /expire_date_);
}

DryFruit& DryFruit::operator--(){

    static size_t counter{4};
    --counter;
    if(counter<=0)
    {
        counter=0;
        if(timeToSpoil_>0){
        --timeToSpoil_;
        return *this;
    }else{
        std::cout<<"Rotten!";
        return *this;
        }
    }

    return *this;
}

void DryFruit::print(std::ostream& os) const {
        os<<"Cargo: "<<name_<<" | "
        <<"Amount: " <<amount_<<" | "
        <<"Base Price: "<<basePrice_<<" | "
        <<"Time to spoil: "<<timeToSpoil_<<" days\n";
    }



void DryFruit::nextDay(){
    operator--();
}