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
    int a,b;
    std::cin>>a>>b;
    std::shared_ptr<Island> Znaleziona = std::make_shared<Island>();
    Znaleziona = mapa.getIsland({a,b});

    std::cout<<std::endl<<std::endl;

    std::cout<<*Znaleziona;

    std::cout<<std::endl<<std::endl;
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
