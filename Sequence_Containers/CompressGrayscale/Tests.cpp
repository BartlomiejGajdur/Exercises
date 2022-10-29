#include <gtest/gtest.h>

#include <iostream>
#include "compressGrayscale.hpp"
#include <vector>
#include <array>

struct CompressTESTS : public ::testing::Test{

    std::array<std::array<int, 10>, 3> bitmap2 {{{0,0,0,1,1,2,3,0,0,0},{0,0,4,4,4,1,1,1,1,1},{2,2,2,2,2,1,2,2,2,2}}};
    std::vector<std::pair<int,int>> expected {{{0, 3},{1,2},{2, 1},{3,1},{0,3},{0,2},{4,3},{1,5},{2,5},{1,1},{2,4}}};
};

TEST_F(CompressTESTS, compressGreayscaleShouldReturnCorrectResultInVectorOfPairs){

    std::vector<std::pair<int,int>> result = compressGrayscale(bitmap2);
    ASSERT_EQ(result, expected);
}
