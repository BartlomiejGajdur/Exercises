#include "Cargo.cpp"
#include <iostream> 

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
    ~Item() = default;
    Item() = default;

    std::string getName()   const override {return name_;}
    size_t getAmount()      const override {return amount_;}
    double getBasePrice()   const override {return basePrice_;}
    std::string getRarity() const;
    double getPrice() const override {return basePrice_*static_cast<int>(rarity_);}

    void print(std::ostream& os) const override{
        os<<"Cargo: "<<name_<<" | "
        <<"Amount: " <<amount_<<" | "
        <<"Base Price: "<<basePrice_<<" | "
        <<"Rarity: "<<getRarity();
    }
    friend std::ostream& operator<<(std::ostream &os, const Item& Item);
    private:
    Rarity rarity_{Rarity::Common};

    

};

std::ostream& operator<<(std::ostream &os, const Item& Item)
    {   
        Item.print(os);
        return os;
    }


std::string Item::getRarity() const
{
    switch(rarity_)
{
case Rarity::Common:
    return "Common";
    break;
   
case Rarity::Rare:
    return "Rare";
    break;
   
case Rarity::Epic:
    return "Epic";
    break;

case Rarity::Legendary:
    return "Legendary";
    break;

case Rarity::Mythic:
    return "Mythic";
    break;
   
default:
    return "Error Fail";
    break;
}
}