#include <gtest/gtest.h>
#include "..\Ship.hpp"
#include <string>
#include <iostream>


TEST(Classs,Callme)
{
    // GIVEN
    Ship statek{1,"css",1,2,3};
    auto expected = 3;
    // WHEN
    auto result = statek.getCapacity();
    // THEN
    ASSERT_EQ(result, expected);

}