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
#include "Alcohol.hpp"
#include <cmath>
#include <iomanip>


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
    std::cout<<"\n\n\n";

    double baseprice = 40;
    size_t percentage = 96; // base price dla 96 percentage to jest 40. /40
    std::cout << "exp(1) = e¹ = "  <<std::setprecision(2)<< static_cast<double>(std::exp(percentage/baseprice)) << '\n';
    percentage=86;
    std::cout << "exp(1) = e¹ = "  <<std::setprecision(2)<< static_cast<double>( std::exp(percentage/baseprice) )<< '\n';
     percentage=76;
    std::cout << "exp(1) = e¹ = " << std::exp(percentage/baseprice) << '\n';
     percentage=66;
    std::cout << "exp(1) = e¹ = "  << std::exp(percentage/baseprice) << '\n';
    percentage=56;
    std::cout << "exp(1) = e¹ = "  << std::exp(percentage/baseprice) << '\n';

    std::cout<<"\n\n\n";
    Alcohol spirol{"SpirytusSalicynowy",10,40,96};
    std::cout<<spirol.getName()<<": "<<spirol.getPrice()<<"\n";
    Alcohol Piwo{"Harnas",10,40,10};
    std::cout<<Piwo.getName()<<": "<<Piwo.getPrice()<<"\n";
    Alcohol spirol1{"Spiryynowy",10,40,40};
    std::cout<<spirol1.getName()<<": "<<spirol1.getPrice()<<"\n";
    Alcohol spirol2{"Spiryy123nowy",10,40,70};
    std::cout<<spirol2.getName()<<": "<<spirol2.getPrice()<<"\n";


    return 0;
}
