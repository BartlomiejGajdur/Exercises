#include "Ship.hpp"
#include "Cargo.hpp"
#include "Coordinates.hpp"
#include "Island.hpp"
#include "Map.hpp"
#include <string>
#include <iostream>
#include <ostream>

int main(){

    // Coordinates pierwsze{1,5};
    // std::cout<<pierwsze<<std::endl;

    // //Island wyspa[5]{};
    // std::cout<<wyspa[0].getPosition()<<std::endl;
    // std::cout<<wyspa[1].getPosition()<<std::endl;
    // std::cout<<wyspa[2].getPosition()<<std::endl;
    // std::cout<<wyspa[3].getPosition()<<std::endl;
    // std::cout<<wyspa[4].getPosition()<<std::endl;

    // std::cout<<std::endl<<std::endl;

    Map mapa;
    mapa.getAllIslands();
    for(auto v :mapa.getAllIslands() )
    {
        std::cout<<v->getPosition()<<std::endl;
    }   

    // std::vector<std::shared_ptr<Island>> wszystkie;
    // wszystkie = mapa.getAllIslands();
    // *wszystkie[0] = Island({1,2});
    // *wszystkie[1] = Island({1,2});
    
    // std::cout<<"\n\n";
    // for(auto v :wszystkie)
    // {
    //     std::cout<<v->getPosition()<<std::endl;
    // }   

    // if(*wszystkie[0]==*wszystkie[1])
    // {
    //     std::cout<<"tak";
    // }else{
    //     std::cout<<"nie";
    // }


    



    return 0;
}
