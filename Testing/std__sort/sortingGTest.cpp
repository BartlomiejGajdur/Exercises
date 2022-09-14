#include <gtest/gtest.h>

TEST(SortTests, SortString)
{
    //Given
    std::string text{"text"};
    std::string expected{"ettx"};

    //When  
    std::sort(text.begin(),text.end());


    //Then
    ASSERT_EQ(text,expected);
}