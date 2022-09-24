#include "Cargo.hpp"
#include "Cargo.cpp"
#include <cmath>
#include <iomanip>

const size_t maxPercentage_{96};

class Alcohol : public Cargo{
    public:
    Alcohol(const std::string& name, 
                       size_t amount, 
                       double basePrice):                                    
                                        Cargo(name,amount,basePrice){}

    Alcohol(const std::string& name, 
                       size_t amount, 
                       double basePrice,
                       size_t percentage):
                                        Cargo(name,amount,basePrice),
                                             percentage_(percentage){}
    ~Alcohol() = default;
    Alcohol() = default;

    std::string getName()   const override {return name_;}
    size_t getAmount()      const override {return amount_;}
    double getBasePrice()   const override {return basePrice_;}

    size_t getPercentage()  const {return percentage_;}



    double getPrice() const override {return (basePrice_*(static_cast<double>(percentage_)/maxPercentage_));}


    private:
    const size_t percentage_{40};


};