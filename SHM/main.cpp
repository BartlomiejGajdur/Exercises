
#include "Alcohol.cpp"
#include "Cargo.cpp"
#include "Coordinates.cpp"
#include "Fruit.cpp"
#include "Island.cpp"
#include "Item.cpp"
#include "Map.cpp"
#include "Player.cpp"
#include "Ship.cpp"


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

   
    // std::cout<<P1.getName()<<": "<<P1.getRarity()<<": "<<P1.getPrice()<<"\n";
    // std::cout<<P2.getName()<<": "<<P2.getRarity()<<": "<<P2.getPrice()<<"\n";

    Alcohol wodka1{"wodka",10,20};
    Fruit owoc1{"jabko",10,10};
    Alcohol wodka12{"wod12ka",10,20};
    Fruit owoc12{"jab12ko",10,10};
    Fruit P1{"jab12ko",24,10};
    Fruit P2{"jab12ko",41,10};

    
    Ship shipp{1,"nazw",10,200,200};

    shipp.load(std::make_shared<Alcohol>(wodka1));
    shipp.load(std::make_shared<Fruit>(owoc1));
    shipp.load(std::make_shared<Alcohol>(wodka12));
    shipp.load(std::make_shared<Fruit>(owoc12));    
    shipp.load(std::make_shared<Fruit>(P1));
    shipp.load(std::make_shared<Fruit>(P2));

    Player gracz{std::make_shared<Ship>(shipp),100};
    std::cout<<"\n\n";

    shipp.printCargo();
    

    





    return 0;
}
