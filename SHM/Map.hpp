#pragma once
#include <memory>
#include <vector>
#include "Island.hpp"

class Map{
    public:


    private:
    std::vector<std::shared_ptr<Island>> allIslands_;
    std::shared_ptr<Island> currentPosition_; //Should have been unique_ptr ?

};
