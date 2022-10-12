#include "Store.hpp"
#include "Item.hpp"
#include "Fruit.hpp"
#include "Alcohol.hpp"

#include <algorithm>


Store::Response Store::buy(std::shared_ptr<Cargo> cargo, size_t amount, std::unique_ptr<Player> &player)
    { 
        
         int totalPrice = cargo->getPrice() * amount; 
    if(findMatchCargo(cargo)!=nullptr){
        auto nowy = findMatchCargo(cargo)->clone();
        if(totalPrice>player->getMoney()){
            std::cout<<"lack_of_money";
            return Response::lack_of_money;

        }
        if(amount>player->getShip()->getAvailableSpace()){
            std::cout<<"lack_of_space";
            return Response::lack_of_space;

        }
        if(amount>findMatchCargo(cargo)->getAmount()){
            std::cout<<"lack_of_cargoAmount";
            return Response::lack_of_cargo;

        }
        
        if(amount==findMatchCargo(cargo)->getAmount()){
            player->getShip()->load(findMatchCargo(cargo));
            player->substractMoney(totalPrice);
             std::cout<<"Zakup done\n";
            storeCargo_.erase(std::remove_if(storeCargo_.begin(), storeCargo_.end(), [&cargo](auto &x){return *cargo==*x;}), storeCargo_.end());
            return Response::done;

        }else if (amount<findMatchCargo(cargo)->getAmount()){ 
            int temp = nowy->getAmount();  
            temp-=amount;                     
            *nowy-=temp;
            player->load(nowy);
            player->substractMoney(totalPrice);
            *findMatchCargo(cargo)-=amount;
            std::cout<<"Zakup done\n";
            return Response::done;

         }
    
        std::cout<<"Incorrect\n";
        return Response::lack_of_cargo;
    }
    std::cout<<"No such cargo in vector Store::Cargo";
    return Response::lack_of_cargo;
}

Store::Response Store::sell(std::shared_ptr<Cargo> cargo, size_t amount, std::unique_ptr<Player> &player){
    
    int totalPrice = cargo->getPrice() * amount;

    // przeszukanie vectora cargo w ship i sprawdzenie czy ejst to samo z CArog
    for (auto &v: player->getShip()->getAllCargo())
    {
        if(*v == *cargo && amount<=v->getAmount())
        {
            player->addMoney(totalPrice); // dodajemy monety
            if(amount<v->getAmount())
            {
                *v-=amount;
            }else if( amount==v->getAmount())
            {
                player->unload(cargo); // Tutaj musi byc jakis inny erase bo sie amount nie zgadza xD w funkcji unload
            }
            std::cout<<"\nDone\n";
            return Response::done;
        }
       
    }
    return Response::lack_of_cargo;
}


int Store::generateRandomNumber(const int& first, const int& second){

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> Random(first, second);

    return Random(gen);
}

 void Store::printCargo() const {
        for (auto &v: storeCargo_){
            std::cout<<*v<<std::endl;
            }
 }  

 void Store::GenerateFruit() {
        
        std::array<std::string,3> name{"Jablko","Gruszka","Banan"};
        int generatedAmount = generateRandomNumber(10,10);
        int generatedBasePrice = generateRandomNumber(10,10);
        storeCargo_.push_back(std::make_shared<Fruit>(name[generateRandomNumber(0,2)],generatedAmount,generatedBasePrice));

    }

void Store::GenerateAlcohol(){
     std::array<std::string,3> name{"Wodka","Bimber","Spirytus"};
     std::array<int,3> percentage{40,60,96};
     int generatedAmount = generateRandomNumber(1,10);
     int generatedNumber = generateRandomNumber(0,2);
     storeCargo_.push_back(std::make_shared<Alcohol>(name[generatedNumber],generatedAmount,10,percentage[generatedNumber]));

}

void Store::GenerateItem(){
     std::array<Item::Rarity,5>rarity   {Item::Rarity::Common,
                                         Item::Rarity::Rare,
                                         Item::Rarity::Epic,
                                         Item::Rarity::Legendary,
                                         Item::Rarity::Mythic};
     std::array<std::string,5>name      {"Common Item","Rare Item","Epic Item","Legendary Item","Mythic Item"};
     int generatedNumber = generateRandomNumber(0,4);
     storeCargo_.push_back(std::make_shared<Item>(name[generatedNumber],
                                                    1,1,rarity[generatedNumber]));
    
}

std::shared_ptr<Cargo> Store::findMatchCargo(std::shared_ptr<Cargo> Cargo){

    for(auto &v : storeCargo_)
    {
        if(*v==*Cargo){
            return v;
        }
    }
    return nullptr;
}

void Store::GenerateCargoForStore(){

        for(int i = 0 ; i<3 ; i++)
        {
            Store::GenerateFruit();
            Store::GenerateAlcohol();
        }
             Store::GenerateItem();
}


void Store::nextDay(){
    storeCargo_.clear();
    GenerateCargoForStore();
}