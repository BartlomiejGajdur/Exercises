#pragma once

#include <memory>
#include <iostream>

#include "Cargo.hpp"
#include "Time.hpp"

class Fruit : public Cargo, public Observer{
    public:
    Fruit(const std::string& name, size_t amount, double basePrice): 
                                                                    Cargo(name,amount,basePrice) {}

    Fruit(const std::string& name,size_t amount , double basePrice, size_t expiry_date, size_t time_elapsed):  
                                                                                                            Cargo(name,amount,basePrice), 
                                                                                                            expire_date_(expiry_date),
                                                                                                            timeToSpoil_(time_elapsed) {};
     Fruit(const Cargo& other){
        name_     = other.getName();
        amount_   = other.getAmount();
        basePrice_= other.getBasePrice();
    }
    Fruit() = default;
    virtual ~Fruit() override{};
    
    std::string getName() const override{return name_;}
    size_t getAmount()    const override{return amount_;}
    double getBasePrice() const override{return basePrice_;}
    size_t getTimeToSpoil() const {return timeToSpoil_;}
    double getPrice()     const override;

    void print(std::ostream& os) const override;
    std::shared_ptr<Cargo> clone() const override{
        return std::make_shared<Fruit>(*this);
    }


    //Operator
    Fruit& operator--() override;
    bool operator==(const Cargo& other)    override;
    Fruit& operator+=(const size_t amount) override;                                                      
    Fruit& operator-=(const size_t amount) override;
    friend std::ostream& operator<<(std::ostream &os, const Fruit& fruit){   
        fruit.print(os);
        return os;
    }

    void nextDay() override;

     protected:
     double timeToSpoil_{10};
     const double expire_date_{10};
};

