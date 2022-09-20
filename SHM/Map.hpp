#pragma once
#include <memory>
#include <vector>
#include "Island.hpp"
#include <random>

class Map{
    public:
     Map(){
        std::shared_ptr<Island> islands[10]{};
        for (int i =0 ; i<10; i++)
        {
            allIslands_.push_back(islands[i]);
        }
     }
    
    std::vector<std::shared_ptr<Island>> getAllIslands() const {return allIslands_;}

    private:
    std::vector<std::shared_ptr<Island>> allIslands_;
    std::shared_ptr<Island> currentPosition_; //Should have been unique_ptr ?

};
