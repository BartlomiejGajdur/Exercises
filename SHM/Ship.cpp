#include "Ship.hpp"
#include "Cargo.hpp"
#include <string>
#include <iostream>

int main(){

    Ship statek{1,"css",1,2,3};
    Ship statek1;
    std::cout<<statek1.getId();

    std::cout<<statek.getCapacity();


    return 0;
}
