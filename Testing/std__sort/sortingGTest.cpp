#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <algorithm> 

struct SortTestUnderTestFixture : public ::testing::Test{
    std::vector<int> v1{1,2,3,4,5}; //sorted
    std::vector<int> v2{5,4,3,2,1}; //unsorted
    std::vector<int> v3{1,2,3,3,4}; //sorted with the same values
    std::vector<int> v4{3,5}; //the whole vector contains te same values
    std::vector<int> v5{}; //Empty
    std::string text{"text"};
};


TEST_F(SortTestUnderTestFixture, SortString_text_ettx)
{
    //Given
    std::string expected{"ettx"};

    //When  
    std::sort(text.begin(),text.end());

    //Then
    ASSERT_EQ(text,expected);
}

TEST_F(SortTestUnderTestFixture, SortString_tExTtextTEXT_EETTTXetttxx)
{
    //Given
    std::string textw{"tExTtextTEXT"};
    std::string expected{"EETTTXetttxx"};

    //When  
    std::sort(textw.begin(),textw.end());

    //Then
    ASSERT_EQ(textw,expected);
}


