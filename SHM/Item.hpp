#pragma once

#include <iostream> 
#include <memory>

#include "Cargo.hpp"

class Item : public Cargo{
    public:
    enum class Rarity {Common=1, Rare =5, Epic = 20, Legendary = 100, Mythic = 500 };

    Item(const std::string& name, 
                       size_t amount, 
                       double basePrice):                                    
                                        Cargo(name,amount,basePrice){}

    Item(const std::string& name, 
                       size_t amount, 
                       double basePrice,
                       Rarity rarity):
                                        Cargo(name,amount,basePrice),
                                              rarity_(rarity){}
    Item(const Cargo& other){
        name_     = other.getName();
        amount_   = other.getAmount();
        basePrice_= other.getBasePrice();
    }
    ~Item() = default;
    Item() = default;
    //GETTERS
    std::string getName()   const override {return name_;}
    size_t getAmount()      const override {return amount_;}
    double getBasePrice()   const override {return basePrice_;}
    double getPrice() const override {return basePrice_*static_cast<int>(rarity_);}
    Item& operator--() override {return *this;}
    std::string getRarity() const;              //Returns string from enum
    void print(std::ostream& os) const override;
    std::shared_ptr<Cargo> clone() const override{
        return std::make_shared<Item>(*this);
    }


    //OPERATORS 
    friend std::ostream& operator<<(std::ostream &os, const Item& Item);
    bool operator==(const Cargo& otherItem) override;
    Item& operator+=(const size_t amount)   override;                                                      
    Item& operator-=(const size_t amount)   override;

  
    private:
    Rarity rarity_{Rarity::Common};

    

};


