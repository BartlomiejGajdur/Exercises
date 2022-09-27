
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

    Ship Statek{1,"StatekBartek",100,100,100}; //Capacity ostatnie
    Player Bartek{std::make_shared<Ship>(Statek),100};
   

    std::unique_ptr<Player> player_;
    player_ = std::make_unique<Player>(std::make_shared<Ship>(Statek),100);
    Statek.load(std::make_shared<Fruit>(P1));
    Statek.load(std::make_shared<Fruit>(P2));
    //Statek.load(std::make_shared<Fruit>(P3));
    //Statek.load(std::make_shared<Fruit>(P4));
    //Statek.load(std::make_shared<Fruit>(P5));

    // std::cout<<Statek.getCapacity()<<"     "<<Statek.getAvailableSpace()<<std::endl;
    // Statek.printCargo();

    // std::cout<<"\n\n";
    // Fruit P6{"Banan",60,15};
    // Statek.load(std::make_shared<Fruit>(P6));
    // std::cout<<Statek.getCapacity()<<"     "<<Statek.getAvailableSpace()<<std::endl;
    // Statek.printCargo();

    // std::cout<<"\n\n";
    // Fruit P7{"Banan",20,15};
    // Statek.unload(std::make_shared<Fruit>(P7));
    // std::cout<<Statek.getCapacity()<<"     "<<Statek.getAvailableSpace()<<std::endl;
    // Statek.printCargo();

    // std::cout<<"\n\n";
    // Fruit P8{"Gruszka",45,5};
    // Statek.unload(std::make_shared<Fruit>(P8));
    // std::cout<<Statek.getCapacity()<<"     "<<Statek.getAvailableSpace()<<std::endl;
    // Statek.printCargo();

    std::vector<std::shared_ptr<Cargo>> vec_;

    vec_.push_back(std::make_shared<Fruit>(P1));
    vec_.push_back(std::make_shared<Fruit>(P2));
    vec_.push_back(std::make_shared<Fruit>(P3));

    Store sklep{vec_};

    player_->printCargo();
     std::cout<<"\n\nShipCargo\n";
     Statek.printCargo();
    std::cout<<"\n"<<player_->getMoney();

    sklep.buy(std::make_shared<Fruit>(P3),5,player_);

     player_->printCargo();
    std::cout<<"\n"<<player_->getMoney();


    return 0;
}
