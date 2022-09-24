#pragma once
#include "Island.hpp"
#include <memory>
#include <random>
#include <vector>



constexpr size_t kIslandNum = 10;


class Map{
    public:
     Map(){
        do{
            generateIslandsOnMap(allIslands_);
        }while(validateGeneratedIslands(allIslands_));
            
     }


    //GETTERS
    std::vector<std::shared_ptr<Island>> getAllIslands() const {return allIslands_;}
    std::shared_ptr<Island> getCurrentPosition()         const {return currentPosition_;}

    
   //FUNCTIONS

    void generateIslandsOnMap ( std::vector<std::shared_ptr<Island>> &islands); // Map contains vector of shared_ptr<Island> with random generate Islands
    bool validateGeneratedIslands(std::vector<std::shared_ptr<Island>> &allIslands_); //Check if every island is unique
    std::shared_ptr<Island> getIsland(const Coordinates& coordinate); //Function returns nullptr while no Island were found
       
    private:
    std::vector<std::shared_ptr<Island>> allIslands_;
    std::shared_ptr<Island> currentPosition_; //Should have been unique_ptr ?

};
