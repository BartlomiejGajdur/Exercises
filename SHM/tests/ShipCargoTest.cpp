#include <gtest/gtest.h>
// #include "..\Cargo.hpp"
// #include "..\Coordinates.hpp"
// #include "..\Island.hpp"
// #include "..\Item.hpp"
// #include "..\Map.hpp"
// #include "..\Player.hpp"
// #include "..\Ship.hpp"
// #include "..\Store.hpp"
// #include "..\Time.hpp"

#include "..\Alcohol.cpp"
#include "..\Coordinates.cpp"
#include "..\DryFruit.cpp"
#include "..\Fruit.cpp"
#include "..\Island.cpp"
#include "..\Item.cpp"
#include "..\Map.cpp"
#include "..\Player.cpp"
#include "..\Ship.cpp"
#include "..\Store.cpp"
#include "..\Time.cpp"

#include <string>
#include <iostream>
#include <vector>
#include <memory>

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}
TEST(GetAvaliableSpace, Function_GetAvailableSpace_ShouldReturnCorrectValueOfAvaliableSpace)
{   
    std::shared_ptr<Ship> statek = std::make_shared<Ship>(1,"statek",10,10,100);
    std::vector<std::shared_ptr<Cargo>> vecCarg = statek->getAllCargo();
    statek->load(std::make_shared<Fruit>("1",25,32));
    statek->load(std::make_shared<Item>("2",25,32));
    statek->load(std::make_shared<Alcohol>("3",25,32));
    Player gracz{statek,10};


    EXPECT_EQ(gracz.getAvailableSpace(),25);
}

TEST(ShipAddingCrew, AddingCrewOverMaxCrew)
{
     Ship statek{0,"",0,100,0};
     statek.setCrew(90);
     statek+=20;
   
     EXPECT_EQ(statek.getCrew(), 90);

}

TEST(ShipAddingCrew,AddingCrewbelowMaxCrew)
{
     Ship statek{0,"",0,100,0};
     statek.setCrew(90);
        statek+=1;
   
     EXPECT_EQ(statek.getCrew(), 91);

}

TEST(ShipDecreasingCrew, DecreasingCrewBelow0)
{
     Ship statek{0,"",0,100,0};
     statek.setCrew(10);
     statek-=20;
   
     EXPECT_EQ(statek.getCrew(), 10);

}

TEST(ShipDecreasingCrew, DecreasingCrew)
{
     Ship statek{0,"",0,100,0};
     statek.setCrew(90);
        statek-=1;
   
     EXPECT_EQ(statek.getCrew(), 89);

}

TEST(ComprasionTwoCargos, EqualCargoShouldReturnTrue)
{
    Fruit item1{"carrot",1,2};
    Fruit item2{"carrot",1,2};
    bool result = (item1 == item2);
    
    EXPECT_TRUE(result);
}

TEST(ComprasionTwoCargos, DifferentCargoShouldReturnFalse)
{
    Fruit item1{"Apple",1,2};
    Fruit item2{"carrot",1,2};
    bool result = (item1 == item2);
    
    EXPECT_FALSE(result);
}

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

