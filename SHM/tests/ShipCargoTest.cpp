#include <gtest/gtest.h>
#include "..\Ship.hpp"
#include "..\Ship.cpp"
#include "..\Cargo.hpp"
#include "..\Cargo.cpp"
#include "..\Coordinates.hpp"
#include "..\Coordinates.cpp"
#include "..\Map.hpp"
#include "..\Map.cpp"
#include "..\Island.hpp"
#include "..\Island.cpp"
#include "..\Player.hpp"
#include "..\Player.cpp"
#include <string>
#include <iostream>
#include <vector>
#include <memory>


// TEST(GetAvaliableSpace, Function_GetAvailableSpace_ShouldReturnCorrectValueOfAvaliableSpace)
// {   
//     std::shared_ptr<Ship> statek = std::make_shared<Ship>(1,"statek",10,10,100);
//     std::vector<std::shared_ptr<Cargo>> vecCarg = statek->getAllCargo();
//     statek->addCargo(std::make_shared<Cargo>("1",25,32));
//     statek->addCargo(std::make_shared<Cargo>("2",25,32));
//     statek->addCargo(std::make_shared<Cargo>("3",25,32));
//     Player gracz{statek,10};


//     EXPECT_EQ(gracz.getAvailableSpace(),25);
// }

// TEST(ShipAddingCrew, AddingCrewOverMaxCrew)
// {
//      Ship statek{0,"",0,100,0};
//      statek.setCrew(90);
//      statek+=20;
   
//      EXPECT_EQ(statek.getCrew(), 90);

// }

// TEST(ShipAddingCrew,AddingCrewbelowMaxCrew)
// {
//      Ship statek{0,"",0,100,0};
//      statek.setCrew(90);
//         statek+=1;
   
//      EXPECT_EQ(statek.getCrew(), 91);

// }

// TEST(ShipDecreasingCrew, DecreasingCrewBelow0)
// {
//      Ship statek{0,"",0,100,0};
//      statek.setCrew(10);
//      statek-=20;
   
//      EXPECT_EQ(statek.getCrew(), 10);

// }

// TEST(ShipDecreasingCrew, DecreasingCrew)
// {
//      Ship statek{0,"",0,100,0};
//      statek.setCrew(90);
//         statek-=1;
   
//      EXPECT_EQ(statek.getCrew(), 89);

// }

// TEST(ComprasionTwoCargos, EqualCargoShouldReturnTrue)
// {
//     Cargo item1{"carrot",1,2};
//     Cargo item2{"carrot",1,2};
//     bool result = (item1 == item2);
    
//     EXPECT_TRUE(result);
// }

// TEST(ComprasionTwoCargos, DifferentCargoShouldReturnFalse)
// {
//     Cargo item1{"Apple",1,2};
//     Cargo item2{"carrot",1,2};
//     bool result = (item1 == item2);
    
//     EXPECT_FALSE(result);
// }

TEST(ComprasionTwoCoordinates, ExactCoordinatesShouldReturnTrue)
{
    Coordinates first{1,1};
    Coordinates second{1,1};
    bool result = (first == second);
    
    EXPECT_TRUE(result);
}

TEST(ComprasionTwoCoordinates, DifferentCoordinatesShouldReturnFalse)
{
    Coordinates first{1,1};
    Coordinates second{1,2};
    bool result = (first == second);
    
    EXPECT_FALSE(result);
}

TEST(validateGeneratedIslandsTest, DifferentIslandsShouldReturnFalse)
{       
    Map mapa;
    std::vector<std::shared_ptr<Island>> vec;
   
        
        do{
            mapa.generateIslandsOnMap(vec);
        }while(mapa.validateGeneratedIslands(vec));
        bool result = mapa.validateGeneratedIslands(vec);
    
    EXPECT_FALSE(result);
}

TEST(validateGeneratedIslandsTest, RecurringIslandsShouldReturnTrue)
{   
    Island wyspa1(1,2);
    Map mapa;
    std::vector<std::shared_ptr<Island>> vec;
    mapa.generateIslandsOnMap(vec);
    *vec[0] = wyspa1;
    *vec[5] = wyspa1;
   
    bool result = mapa.validateGeneratedIslands(vec);
    
    EXPECT_TRUE(result);
}

TEST(GetIsland, GetIslandByCoordinateNoExists)
{   
    std::shared_ptr<Island> searchIsland = std::make_shared<Island>();
    Map mapa;
    std::vector<std::shared_ptr<Island>> vec;
    mapa.generateIslandsOnMap(vec);
    
    searchIsland = mapa.getIsland({102,102});

    EXPECT_EQ(nullptr, searchIsland);
   
}


TEST(GetIsland, GetIslandByCoordinateExists)
{   
    Island wyspa1(1,2);
    std::shared_ptr<Island> searchIsland = std::make_shared<Island>();
    Map mapa;
    std::vector<std::shared_ptr<Island>> vec;
    mapa.generateIslandsOnMap(vec);
    *vec[8] = wyspa1;
    
    searchIsland = mapa.getIsland({1,2});
    
    

    bool result = (wyspa1==*searchIsland);
    
    EXPECT_TRUE(result);
}

