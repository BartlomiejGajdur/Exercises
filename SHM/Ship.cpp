#include "Ship.hpp"
#include "Cargo.hpp"
#include "Coordinates.hpp"
#include "Island.hpp"
#include "Map.hpp"
#include <string>
#include <iostream>
#include <ostream>

int main(){

    Coordinates pierwsze{1,5};
    std::cout<<pierwsze<<std::endl;

    Island wyspa[5]{};
    std::cout<<wyspa[0].getPosition()<<std::endl;
    std::cout<<wyspa[1].getPosition()<<std::endl;
    std::cout<<wyspa[2].getPosition()<<std::endl;
    std::cout<<wyspa[3].getPosition()<<std::endl;
    std::cout<<wyspa[4].getPosition()<<std::endl;

    std::cout<<std::endl<<std::endl;

    Map mapa;
    mapa.getAllIslands();
    for(auto v :mapa.getAllIslands() )
    {
        std::cout<<v<<std::endl;
    }
    



    return 0;
}
