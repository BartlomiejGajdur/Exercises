#include "Ship.hpp"
#include "Cargo.hpp"
#include <string>
#include <iostream>

int main(){

    Ship statek{1,"css",1,2,3};
    Ship statek2{2,10,100};
    Ship statek1;
    std::cout<<statek1.getId()<<std::endl;  
    std::cout<<statek1.getCrew()<<std::endl;
    std::cout<<statek.getName();
    std::cout<<statek2.getId()<<std::endl;  
    std::cout<<statek2.getCrew()<<std::endl;


    return 0;
}
