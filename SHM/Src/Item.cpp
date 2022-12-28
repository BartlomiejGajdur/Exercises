#include "../Include/Item.hpp"

void Item::print(std::ostream& os) const {
        os<<"Cargo: "<<name_<<" | "
        <<"Amount: " <<amount_<<" | "
        <<"Base Price: "<<basePrice_<<" | "
        <<"Rarity: "<<getRarity();
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

std::ostream& operator<<(std::ostream &os, const Item& Item)
    {   
        Item.print(os);
        return os;
    }

bool Item::operator==(const Cargo& otherItem)
    {
        return  this->name_ == otherItem.getName() &&
            this->basePrice_== otherItem.getBasePrice();
    }

Item& Item::operator+=(const size_t amount)
    {      
        amount_+=amount;
        return *this;
    }     

Item& Item::operator-=(const size_t amount)
    {
        if (amount_-amount>0)
        {
            amount_-=amount;
        }
        return *this;
    }   