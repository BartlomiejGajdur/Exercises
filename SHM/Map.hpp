#pragma once
#include <memory>
#include <vector>
#include "Island.hpp"
#include <random>

class Map{
    public:
     Map(){
        do{
            generateIslandsOnMap(allIslands_);
        }while(validateGeneratedIslands(allIslands_));

        //wykonuj dopóki nie beda wszystkie inne
            
     }


    //GETTERS
   std::vector<std::shared_ptr<Island>> getAllIslands() const {return allIslands_;}

   //FUNCTIONS
   void generateIslandsOnMap ( std::vector<std::shared_ptr<Island>> &islands) // Map contains vector of shared_ptr<Island> with random generate Islands
   {
        for (int i = 0; i<10 ; i++) 
        {
            islands.push_back(std::make_shared<Island>());
        }
   }

   bool validateGeneratedIslands(std::vector<std::shared_ptr<Island>> &allIslands_) //Check if every island is unique
    {

        for(int i = 0; i < 10; i++)
        {
            for(int j = 0; j < i; j++)
                {
                    if(*allIslands_[j] == *allIslands_[i])
                    {   
                        allIslands_.clear();
                        return true;
                        break;  
                    }
                }
        }
        return false;

    }

    std::shared_ptr<Island> getIsland(const Coordinates& coordinate){ //Function returns nullptr while no Island were found
       
       std::shared_ptr<Island> islandSearch = std::make_shared<Island>(coordinate.getPositionX(),coordinate.getPositionY());
        for(auto v: allIslands_)
        {
            if(*v == *islandSearch){
                return v;
            }
        }
        return std::shared_ptr<Island>(nullptr);
    }
    private:
    std::vector<std::shared_ptr<Island>> allIslands_;
    std::shared_ptr<Island> currentPosition_; //Should have been unique_ptr ?

};
