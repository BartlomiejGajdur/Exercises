#pragma once
#include <memory>
#include <vector>
#include "Island.hpp"
#include <random>

class Map{
    public:
     Map(){
        Island islands[10]{};
        for (int i =0 ; i<10; i++)
        {
            allIslands_.push_back(islands[i]);
        }
     }
    
    std::vector<Island> getAllIslands() const {return allIslands_;}

    private:
    std::vector<Island> allIslands_;
    std::shared_ptr<Island> currentPosition_; //Should have been unique_ptr ?

};
