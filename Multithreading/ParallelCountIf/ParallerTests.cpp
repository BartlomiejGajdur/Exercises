#include <chrono>
#include <gtest/gtest.h>
#include <iostream>
#include <numeric>
#include <vector>
#include <execution>
#include "lib.hpp"

std::vector<int> v(1'000'000);

auto lambda = [](auto el){ return el>1000 && el<=120000 && el%4==1;};

TEST(ParallerTests, ExecutingTime) {

    std::iota(v.begin(), v.end(), 1);

    auto start = std::chrono::high_resolution_clock::now();
    parallel_count_if(v.begin(), v.end(), lambda);
    auto stop = std::chrono::high_resolution_clock::now();
    
    std::chrono::duration<float> duration = stop - start;

    start = std::chrono::high_resolution_clock::now();
    std::count_if(v.begin(), v.end(), lambda);
    stop = std::chrono::high_resolution_clock::now();

    std::chrono::duration<float> duration2 = stop - start;
    std::cout<<"Duration Parallel: "<<duration.count()<<"\n";
    std::cout<<"Duration STL: "<<duration2.count()<<"\n";
    EXPECT_LT(duration,duration2);
}

TEST(ParallerTests, ExecutingTime2) {

    std::iota(v.begin(), v.end(), 1);

    auto start = std::chrono::high_resolution_clock::now();
    parallel_count_if(v.begin(), v.end(), lambda);
    auto stop = std::chrono::high_resolution_clock::now();
    
    std::chrono::duration<float> duration = stop - start;

    start = std::chrono::high_resolution_clock::now();
    std::count_if(std::execution::par ,v.begin(), v.end(), lambda);
    stop = std::chrono::high_resolution_clock::now();

    std::chrono::duration<float> duration2 = stop - start;

    start = std::chrono::high_resolution_clock::now();
    std::count_if(v.begin(), v.end(), lambda);
    stop = std::chrono::high_resolution_clock::now();

    std::chrono::duration<float> duration3 = stop - start;



    std::cout<<"Duration Parallel (MyImplementation): "<<duration.count()<<"\n";
    std::cout<<"Duration Parallel (STLImplementation): "<<duration2.count()<<"\n";
    std::cout<<"Duration STL: "<<duration3.count()<<"\n";

    EXPECT_LT(duration,duration2);
}

TEST(ParallerTests, Correctness) {
    
    std::iota(v.begin(), v.end(), 1);

    auto sum = std::count_if(v.begin(), v.end(),lambda);
    auto sum2 = parallel_count_if(v.begin(), v.end(),lambda);
    EXPECT_EQ(sum,sum2);
}

TEST(ParallerTests, Correctness2) {
    
    std::iota(v.begin(), v.end(), 1);
    auto lambda = [](auto el){ return el%2;};

    auto sum = std::count_if(v.begin(), v.end(),lambda);
    auto sum2 = parallel_count_if(v.begin(), v.end(),lambda);
    EXPECT_EQ(sum,sum2);
}

TEST(ParallerTests, Correctness3) {
    
    std::vector<int> vec;
    auto lambda = [](auto el){ return el%2;};

    auto sum = std::count_if(v.begin(), v.end(),lambda);
    auto sum2 = parallel_count_if(v.begin(), v.end(),lambda);
    EXPECT_EQ(sum,sum2);
}

// Test that checks if the algorithm works correctly for an empty range
TEST(ParallerTests, EmptyRange) {
    std::vector<int> emptyVec;
    auto sum = std::count_if(emptyVec.begin(), emptyVec.end(), lambda);
    auto sum2 = parallel_count_if(emptyVec.begin(), emptyVec.end(), lambda);
    EXPECT_EQ(sum, sum2);
}

// Test that checks if the algorithm works correctly for a small range
TEST(ParallerTests, SmallRange) {
    std::vector<int> smallVec = {5, 10, 15};
    auto lambda = [](auto el){ return el==5;};
    auto sum = std::count_if(smallVec.begin(), smallVec.end(), lambda);
    auto sum2 = parallel_count_if(smallVec.begin(), smallVec.end(), lambda);
    EXPECT_EQ(sum, sum2);
}

// Test that checks if the algorithm works correctly for a large range
TEST(ParallerTests, LargeRange) {
    std::vector<int> largeVec(1'000'000);
    std::iota(largeVec.begin(), largeVec.end(), 1);
    auto sum = std::count_if(largeVec.begin(), largeVec.end(), lambda);
    auto sum2 = parallel_count_if(largeVec.begin(), largeVec.end(), lambda);
    EXPECT_EQ(sum, sum2);
}

// Test that checks if the algorithm works correctly for all elements meeting the condition
TEST(ParallerTests, AllElementsMeetCondition) {
    std::vector<int> allTrueVec(1'000'000, 2000);
    auto lambda = [](auto el){ return el/el == 1;};
    auto sum = std::count_if(allTrueVec.begin(), allTrueVec.end(), lambda);
    auto sum2 = parallel_count_if(allTrueVec.begin(), allTrueVec.end(), lambda);
    EXPECT_EQ(sum, sum2);
}

// Test that checks if the algorithm works correctly for no elements meeting the condition
TEST(ParallerTests, NoElementMeetsCondition) {
    std::vector<int> noneTrueVec(1'000'000, 500);
    auto lambda = [](auto el){ return el == -1;};
    auto sum = std::count_if(noneTrueVec.begin(), noneTrueVec.end(), lambda);
    auto sum2 = parallel_count_if(noneTrueVec.begin(), noneTrueVec.end(), lambda);
    EXPECT_EQ(sum, sum2);
}

