#pragma once
#include "Cargo.hpp"
#include "Cargo.cpp"
#include <iostream>

class Fruit : public Cargo{
    public:
    Fruit(const std::string& name, size_t amount, double basePrice): 
                                                                    Cargo(name,amount,basePrice) {}

    Fruit(const std::string& name,size_t amount , double basePrice, size_t expiry_date, size_t time_elapsed):  
                                                                                                            Cargo(name,amount,basePrice), 
                                                                                                            expire_date_(expiry_date),
                                                                                                            timeToSpoil_(time_elapsed) {};
    Fruit() = default;
    ~Fruit() override = default;
    
    std::string getName() const override{return name_;}
    size_t getAmount()    const override{return amount_;}
    double getBasePrice() const override{return basePrice_;}
    size_t getTimeToSpoil() const {return timeToSpoil_;}
    double getPrice()     const override;
    void print(std::ostream& os) const override;

    //Operator
    Fruit& operator--();
    bool operator==(const Cargo& other)    override;
    Fruit& operator+=(const size_t amount) override;                                                      
    Fruit& operator-=(const size_t amount) override;
    friend std::ostream& operator<<(std::ostream &os, const Fruit& fruit);

    // Cargo& operator=(const Cargo& other) override{
    //     name_     = other.getName();
    //     amount_   = other.getAmount();
    //     basePrice_= other.getBasePrice();
    //     return *this;
    // }

    Fruit(const Fruit& other){
        name_     = other.getName();
        amount_   = other.getAmount();
        basePrice_= other.getBasePrice();
    }


     private:
     double timeToSpoil_{10};
     const double expire_date_{10};

};

