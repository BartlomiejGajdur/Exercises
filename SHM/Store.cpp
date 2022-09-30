#pragma once
#include "Store.hpp"

// #include "Fruit.hpp"
// #include "Alcohol.hpp"
// #include "Item.hpp"

Store::Response Store::buy(std::shared_ptr<Cargo> cargo, size_t amount, std::unique_ptr<Player> &player)
    {
        // Nie wiem czy SHIP w plajerze musi byc uniqe ptr lub jakos musze przeanalizowac kiedy shared ptr robi kopie sobie obiektu swojego
         int totalPrice = cargo->getPrice() * amount; 
    
    if(findMatchCargo(cargo)!=nullptr){
        if(totalPrice>player->getMoney()){
            return Response::lack_of_money;
        }
        if(amount>player->getShip()->getAvailableSpace()){
            return Response::lack_of_space;
        }
        if(amount>cargo->getAmount()){
            return Response::lack_of_cargo;
        }
        player->getShip()->load(cargo);
        player->substractMoney(totalPrice); 
        std::cout<<"Zakup done\n";
        return Response::done;
    }
    std::cout<<"Nie ma takiego cargo w vectorze Store::Cargo";
    return Response::lack_of_cargo;
    
}

Store::Response Store::sell(std::shared_ptr<Cargo> cargo, size_t amount, std::unique_ptr<Player> &player){
    //Nie wiem czy by sie nie przydala jakas static zmienna do oznaczania towarow, moze wystarczy po prostu numer czy cos
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
/*
Jeśli w vectorze Cargo, który mamy w Store jest dany towar który podajemy w:
buy(jakies cargo(czyli np cargo o nazwie "Jablko" i cenie bazowej 20), ilosc tego Cargo,Nie wiem czy tu potrzebny jest player)
*/

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
        
        std::array<std::string,3> name{"Jablko","Banan","Gruszka"};
        int generatedAmount = generateRandomNumber(1,10);
        int generatedBasePrice = generateRandomNumber(5,10);
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
    //amount bedzie jeden -> mapa z Rarity i price -> i jakiegos if ze jezeli wygenerowany item 
    //np od 0-90 bedzie common 90-05 to zeby wzielo tamto itd itd... 
    //Ale to bedzie tylko w Sell chyba 
    //Mozna kupic skrzynke których bedzie np 5 w kazdym sklepie i funkcjonalnosc otwierania skrzynki 
    //z której wypada wlasnie jakis Losowy itemek i dodaje się do Ship. ( Przy otwieraniu trzeba miec wystarczajaca ilosc miejsca)
    //nr. 9 --> otworz skrzynek jeżeli jest to wysweitla ile masz skrzynek itd... 
    

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

//Znajdz Cargo z vectora shared ptr z STORECARGO 