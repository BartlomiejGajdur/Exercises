#pragma once
#include <string>
#include <iostream>

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
    int getId()             const { return id_;}
    std::string getName()   const { return name_;}
    size_t getSpeed()       const { return speed_;}
    size_t getMaxCrew()     const { return maxCrew_;}
    size_t getCapacity()    const { return capacity_;}
    size_t getCrew()        const { return crew_;}
    
    //Setters
    void setName(const std::string &name) {name_ = name;}
    void setCrew(const int &crew)         {crew_= crew;}
    
    //Operators
    Ship& operator+=(const int num)
    {
        if(crew_+num>maxCrew_)
            {
                std::cerr<<"Too many papays!";
                return *this;
            }else{
                crew_+=num;
                return *this;
            }
    }

     Ship& operator-=(const size_t num)
    {
        if(num>crew_)
            {
                std::cerr<<"Number of papays is lower than 0\n";
                return *this;
            }else{
                crew_-=num;
                return *this;
            }
    }


    private:
    int id_;
    std::string name_;
    size_t speed_;
    size_t maxCrew_;
    size_t capacity_;
    size_t crew_;

};

