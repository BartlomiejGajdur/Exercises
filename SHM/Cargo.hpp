#pragma once
#include <string>
#include <iostream>

class Cargo{
    public:
    Cargo(std::string name, size_t amount, double basePrice) :  
                                                              name_(name),
                                                              amount_(amount),
                                                              basePrice_(basePrice) {} 


//GETTERS
    std::string getName() const {return name_;}
    size_t getAmount()    const {return amount_;}
    double getBasePrice() const {return basePrice_;}
//SETTERS
    

//OPERATORS
    Cargo& operator+=(const size_t amount)
    {      
        amount_+=amount;
        return *this;
    }                                                           

    Cargo& operator-=(const size_t amount)
    {
        amount_-=amount;
        return *this;
    }   

    bool operator==(const Cargo& other)
    {
        return  this->name_ == other.name_ &&
            this->basePrice_== other.basePrice_;
    }

    private:
    std::string name_;
    size_t amount_;
    double basePrice_;

};