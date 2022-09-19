#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <algorithm> 
#include <functional>

// struct SortTestUnderTestFixture : public ::testing::Test{
//     std::vector<int> v1{1,2,3,4,5}; //sorted
//     std::vector<int> v2{5,4,3,2,1}; //unsorted
//     std::vector<int> v3{1,2,3,3,4}; //sorted with the same values
//     std::vector<int> v4{3,5}; //the whole vector contains te same values
//     std::vector<int> v5{}; //Empty
//     std::string text{"text"};
// };


using StringPair = std::pair<std::string,std::string>;

struct SortStringTextFixture : public ::testing::TestWithParam<StringPair>
{};

TEST_P(SortStringTextFixture, SortString_text__xtte)
{
    //Given
    auto [input, expected] = GetParam();
    
    //When
    std::sort(input.begin(),input.end());

    //THEN
    ASSERT_EQ(input,expected);

}

INSTANTIATE_TEST_SUITE_P(PermutationsOfString,
                        SortStringTextFixture,
                        testing::Values(StringPair{{"text"},{"ettx"}},
                                        StringPair{{"ettx"},{"ettx"}},
                                        StringPair{{"tExTtextTEXT"},{"EETTTXetttxx"}}
                                        ));


using Comparator = std::function<bool(const int&a, const int&b)>;
using VectorsPair = std::tuple<std::vector<int>,std::vector<int>, Comparator>;

struct SortTestFixture : public ::testing::TestWithParam<VectorsPair>{
    // std::vector<int> v{ 3,2,1};
    // std::vector<int> expected {1,2,3};

    // template<typename Type>
    // void sortAndCheck(Type & input,
    //                   const Type & expected){
    //      //When  
    //     std::sort(input.begin(),input.end());

    //     //Then
    //     ASSERT_EQ(input,expected);
    //  }

    // template<typename Type>
    // void sortDescendingAndCheck(Type & input,
    //                   const Type & expected){
    //      //When  
    //     std::sort(input.begin(),input.end(), std::greater<int>{});

    //     //Then
    //     ASSERT_EQ(input,expected);
    //  }

};

TEST_P(SortTestFixture, GivenPermutedVector){
    
    
    auto [input, expected, comparator] = GetParam(); //C++17 is equal to:
    /*
    auto pair = GetParam();
    auto v = pair.first;
    auto expected = pair.second;
    first and second are member objects.
    */

    //When  
     std::sort(input.begin(),input.end(),comparator);

    //Then
     ASSERT_EQ(input,expected);
}

INSTANTIATE_TEST_SUITE_P(PermutationsOf123Vector,
                        SortTestFixture,
                        testing::Values(VectorsPair{{3,2,1},{1,2,3}, std::less<int>{}},
                                        VectorsPair{{1,2,3},{1,2,3}, std::less<int>{}},
                                        VectorsPair{{2,1,3},{1,2,3}, std::less<int>{}},
                                        VectorsPair{{3,1,2},{1,2,3}, std::less<int>{}},
                                        VectorsPair{{},{}, std::less<int>{}},
                                        VectorsPair{{1},{1}, std::less<int>{}},
                                        VectorsPair{{5,4,3,2,1},{1,2,3,4,5}, std::less<int>{}},
                                        VectorsPair{{1,2,3},{3,2,1}, std::greater<int>{}},
                                        VectorsPair{{1,2,3,4,5},{5,4,3,2,1}, std::greater<int>{}}
                                        ));
