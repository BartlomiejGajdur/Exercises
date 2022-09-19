#include <gtest/gtest.h>
#include "..\Ship.hpp"
#include "..\Cargo.hpp"
#include "..\Coordinates.hpp"
#include <string>
#include <iostream>

// struct ShipUnderTestFixture : public ::testing::Test{  
//      Ship statek{0,"",0,100,0};
//      statek.setCrew(90);
// };

// TEST_F(ShipUnderTestFixture, test)
// {   
//     statek+=20;
//     EXPECT_EQ(statek.getCrew(), 90);
// }

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