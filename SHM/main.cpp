
#include "Alcohol.cpp"
#include "Cargo.cpp"
#include "Coordinates.cpp"
#include "Fruit.cpp"
#include "Island.cpp"
#include "Item.cpp"
#include "Map.cpp"
#include "Player.cpp"
#include "Ship.cpp"
#include "Store.cpp"


int main(){

    Fruit P1{"Jablko",20,10};
    Fruit P2{"Jablko",20,10};
    Fruit P3{"Gruszka",35,5};
    Fruit P4{"Banan",15,15};
    Fruit P5{"Banan",10,15};

    auto Statek = std::make_shared<Ship>(1,"StatekBartek",100,100,100); 

    //auto nowy = std::make_shared<Fruit>(P4);

    std::unique_ptr<Player> player_;
    player_ = std::make_unique<Player>(Statek,1000);

    Store sklep{};
    std::cout<<"CargoSHOP ----------------------------\n";
    sklep.printCargo();
    std::cout<<"\n\n\n";

    
    Statek->load(std::make_shared<Fruit>(P1));
    player_->load(std::make_shared<Fruit>(P3));
   
    std::cout<<"PlayerCargo ----------------------------\n";
    player_->printCargo();
    std::cout<<"\n\n\n";
    std::cout<<"Transaction:";
    sklep.buy(std::make_shared<Fruit>("Gruszka",1,10),5,player_);

    std::cout<<"\nPlayerCargo ----------------------------\n";
    player_->printCargo();
    std::cout<<"\n\n\n";

     std::cout<<"CargoSHOP ----------------------------\n";
    sklep.printCargo();
    std::cout<<"\n\n\n";

    return 0;
}
