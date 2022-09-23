#pragma once
#include <string>

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
    Cargo& operator+=(const size_t amount);                                                      
    Cargo& operator-=(const size_t amount);
    bool operator==(const Cargo& other);

    private:
    std::string name_;
    size_t amount_;
    double basePrice_;

};