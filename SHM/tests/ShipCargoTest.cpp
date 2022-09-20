#include <gtest/gtest.h>
#include "..\Ship.hpp"
#include "..\Cargo.hpp"
#include "..\Coordinates.hpp"
#include "..\Map.hpp"
#include "..\Island.hpp"
#include <string>
#include <iostream>
#include <vector>
#include <memory>




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
    Cargo item1{"carrot",1,2};
    Cargo item2{"carrot",1,2};
    bool result = (item1 == item2);
    
    EXPECT_TRUE(result);
}

TEST(ComprasionTwoCargos, DifferentCargoShouldReturnFalse)
{
    Cargo item1{"Apple",1,2};
    Cargo item2{"carrot",1,2};
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

TEST(GetIsland, GetIslandByCoordinate_NoExists)
{   
    std::shared_ptr<Island> searchIsland = std::make_shared<Island>();
    Map mapa;
    std::vector<std::shared_ptr<Island>> vec;
    mapa.generateIslandsOnMap(vec);
    
    searchIsland = mapa.getIsland({102,102});

    EXPECT_EQ(nullptr, searchIsland);
   
}


TEST(GetIsland, GetIslandByCoordinate_Exists)
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


