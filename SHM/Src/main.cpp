#include "../Include/Alcohol.hpp"
#include "../Include/Cargo.hpp"
#include "../Include/Coordinates.hpp"
#include "../Include/DryFruit.hpp"
#include "../Include/Fruit.hpp"
#include "../Include/Island.hpp"
#include "../Include/Item.hpp"
#include "../Include/Map.hpp"
#include "../Include/Player.hpp"
#include "../Include/Ship.hpp"
#include "../Include/Store.hpp"
#include "../Include/Time.hpp"



int main(){

    // Fruit P1{"Jablko",20,10};
    // Fruit P2{"Jablko",20,10};
    // Fruit P3{"Gruszka",35,5};
    // Fruit P4{"Banan",15,15};
    // Fruit P5{"Banan",10,15};
    // auto Banan = std::make_shared<Fruit>("Banan",10,10);
    // auto Statek = std::make_shared<Ship>(1,"StatekBartek",100,100,100); 

    // //auto nowy = std::make_shared<Fruit>(P4);

    // std::unique_ptr<Player> player_;
    // player_ = std::make_unique<Player>(Statek,1000);

    // Store sklep{};
    // std::cout<<"CargoSHOP ----------------------------\n";
    // sklep.printCargo();
    // std::cout<<"\n\n\n";

    
    // Statek->load(std::make_shared<Fruit>(P1));
    // player_->load(std::make_shared<Fruit>(P3));
   
    // std::cout<<"PlayerCargo ----------------------------\n";
    // player_->printCargo();
    // std::cout<<"\n\n\n";
    // std::cout<<"Transaction:";
    // sklep.buy(std::make_shared<Fruit>("Banan",1,10),10,player_);

    // std::cout<<"\nPlayerCargo ----------------------------\n";
    // player_->printCargo();
    // std::cout<<"\n\n\n";

    //  std::cout<<"CargoSHOP ----------------------------\n";
    // sklep.printCargo();
    // std::cout<<"\n\n\n";

    // Time czas{100};

    // czas.addObserver(player_.get());
    // czas.addObserver(Statek.get());
    // czas.addObserver(&sklep);
    // czas.addObserver(&P5);

    // std::cout<<"Player money: "<<player_->getMoney()<<"\n";
    // std::cout<<"OBSERVED P5: "<<P5.getTimeToSpoil()<<"\n";
    // std::cout<<"P4: "<<P4.getTimeToSpoil()<<"\n";
    // ++czas;
    // std::cout<<"Player money: "<<player_->getMoney()<<"\n";
    // std::cout<<"OBSERVED P5: "<<P5.getTimeToSpoil()<<"\n";
    // std::cout<<"P4: "<<P4.getTimeToSpoil()<<"\n";
    // std::cout<<"CargoSHOP ----------------------------\n";
    // sklep.printCargo();

    // std::cout<<"\n\n\n"<<"PLAYER CARGO\n";
    // player_->printCargo();
    // std::cout<<"\n\n";
    // Statek->nextDay();
    // std::cout<<"\n\n\n"<<"PLAYER CARGO AFTER NEXT DAY\n";
    // player_->printCargo();
    // std::cout<<"\n\n";

    // Island wyspa;

    // wyspa.printCargo();
    // wyspa.getStore().buy(Banan,8,player_);
    // std::cout<<"\n\n";
    // wyspa.printCargo();
    // std::cout<<"\n\n\n"<<"PLAYER CARGO\n";
    // player_->printCargo();

    // std::cout<<"\n\n\n"<<"LICZENIE DYSTANSU\n";
    // Map mapka;
    // std::cout<<*mapka.getAllIslands()[0]<<std::endl;
    // std::cout<<*mapka.getAllIslands()[1]<<std::endl;
    // std::cout<<Island::distance(*mapka.getAllIslands()[0],*mapka.getAllIslands()[1])<<std::endl;

    // std::cout<<Coordinates::distance({5,5},{1,2});

    DryFruit SuchyOwoc{"SuchyBanan",10,10};
    Fruit MokryOwoc{"Banan",10,10};

    std::vector<std::shared_ptr<Cargo>> vectorek;
    vectorek.push_back(std::make_shared<DryFruit>(SuchyOwoc));
    vectorek.push_back(std::make_shared<Fruit>(MokryOwoc));

    for(int i = 0 ; i<6; i++){
        std::cout<<"PRZEJSCIE --------------\n";
    for (auto vec: vectorek){
        std::cout<<*vec;
    }
    --*vectorek[0];
    --*vectorek[1];

    }
    
    return 0;
}


