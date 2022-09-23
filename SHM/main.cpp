#include "Fruit.hpp"
#include "Fruit.cpp"
#include "Ship.hpp"
#include "Ship.cpp"
#include "Cargo.hpp"
#include "Cargo.cpp"
#include "Coordinates.hpp"
#include "Coordinates.cpp"
#include "Map.hpp"
#include "Map.cpp"
#include "Island.hpp"
#include "Island.cpp"
#include "Player.hpp"
#include "Player.cpp"


int main(){

    Fruit owoc{"Jablko",10,5};


    
    std::cout<<"BasePrice: "<<owoc.getBasePrice()<<std::endl;

    std::cout<<"GetPrice: "<<owoc.getPrice()<<std::endl;
    std::cout<<owoc.getTimeToSpoil()<<std::endl;
    --owoc;
    std::cout<<"GetPrice: "<<owoc.getPrice()<<std::endl;
    std::cout<<owoc.getTimeToSpoil()<<std::endl;
    --owoc;
    std::cout<<"GetPrice: "<<owoc.getPrice()<<std::endl;
    std::cout<<owoc.getTimeToSpoil()<<std::endl;
    --owoc;
    std::cout<<"GetPrice: "<<owoc.getPrice()<<std::endl;
    std::cout<<owoc.getTimeToSpoil()<<std::endl;
    --owoc;
   std::cout<<"GetPrice: "<<owoc.getPrice()<<std::endl;
    std::cout<<owoc.getTimeToSpoil()<<std::endl;
    --owoc;
    std::cout<<"GetPrice: "<<owoc.getPrice()<<std::endl;
    std::cout<<owoc.getTimeToSpoil()<<std::endl;
    
    return 0;
}
