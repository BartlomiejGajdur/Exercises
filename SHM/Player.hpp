#pragma once
#include "Ship.hpp"
#include <iostream>
#include <memory>

class Player{
    public:
    Player(std::shared_ptr<Ship> ship, double money): 
                                                    ship_(ship), 
                                                    money_(money) {}
    std::shared_ptr<Ship> getShip() const {return ship_;}
    double getMoney()               const {return money_;}
    //SETTERS


    //OPERATORS

    
    //Functions
    size_t getSpeed() const {return ship_->getSpeed();}
    size_t getAvailableSpace() const; //Checking the whole vector Cargos from Ship. Add all values then substract with Capacity _return AvailableSpace_;
    void substractMoney(const double& moneyToSubstract);
    void addMoney(const double& moneyToAdd);
    void printCargo() const {ship_->printCargo();}
    void load(const std::shared_ptr<Cargo>& cargo) {ship_->load(cargo);}
    void unload(const std::shared_ptr<Cargo>& cargo) {ship_->unload(cargo);}
    
    private:
    

    std::shared_ptr<Ship> ship_;
    double money_;
    int availableSpace_;
};