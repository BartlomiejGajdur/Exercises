#pragma once
#include "Cargo.cpp"
#include <iostream>
#include <memory>
#include <string>
#include <vector>


class Ship{
    public:
    Ship(int id, 
         std::string name, 
         size_t speed, 
         size_t maxCrew,
         size_t capacity): id_(id), name_(name), speed_(speed), maxCrew_(maxCrew), capacity_(capacity), crew_(0) {}

    Ship() : id_(-1), crew_(0) {}

    Ship(int id, 
         size_t speed, 
         size_t maxCrew): Ship(id,"",speed,maxCrew,0) {}

    //Getters
    int         getId()          const { return id_;}
    std::string getName()        const { return name_;}
    size_t      getSpeed()       const { return speed_;}
    size_t      getMaxCrew()     const { return maxCrew_;}
    size_t      getCapacity()    const { return capacity_;}
    size_t      getCrew()        const { return crew_;}
    std::vector<std::shared_ptr<Cargo>> getAllCargo() const {return cargo_;}


    //Setters
    void setName(const std::string &name) {name_ = name;}
    void setCrew(const int &crew)         {crew_= crew;}
    void addCargo(const std::shared_ptr<Cargo> &cargo) {cargo_.push_back(cargo);} //Shall call function which check if added Cargo not overload Capacity of the Ship
    
    //Operators
    Ship& operator+=(const int num);
    Ship& operator-=(const size_t num);

    
    private:
    int id_;
    std::string name_;
    size_t speed_;
    size_t maxCrew_;
    size_t capacity_;
    size_t crew_;
    std::vector<std::shared_ptr<Cargo>> cargo_;
    

};

