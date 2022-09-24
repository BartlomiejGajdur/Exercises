#pragma once
#include "Cargo.hpp"
#include "Cargo.cpp"

class Fruit : public Cargo{
    public:
    Fruit(const std::string& name, size_t amount, double basePrice): 
                                                                    Cargo(name,amount,basePrice) {}

    Fruit(const std::string& name,size_t amount , double basePrice, size_t expiry_date, size_t time_elapsed):  
                                                                                                            Cargo(name,amount,basePrice), 
                                                                                                            expire_date_(expiry_date),
                                                                                                            timeToSpoil_(time_elapsed) {};
    //~Fruit() override;
    
    std::string getName() const override{return name_;}
    size_t getAmount()    const override{return amount_;}
    double getBasePrice() const override{return basePrice_;}
    double getPrice()     const override;
    size_t getTimeToSpoil() const {return timeToSpoil_;}

    //Operator
    Fruit& operator--();

     private:
     double timeToSpoil_{10};
     const double expire_date_{10};

};