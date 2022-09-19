#include <string>
#include <iostream>

class Cargo{
    public:
    Cargo(std::string name, size_t amount, double basePrice) :  
                                                              name_(name),
                                                              amount_(amount),
                                                              basePrice_(basePrice) {} 


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

    private:
    std::string name_;
    size_t amount_;
    double basePrice_;

};