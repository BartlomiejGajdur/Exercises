#pragma once
#include "Time.hpp"

void Time::addObserver(Observer* obs){
    observers_.push_back(obs);
}

void Time::removeObserver(Observer* obs){
    observers_.remove(obs);
}
 
Time& Time::operator++(){
    gameDays_--;
    auto it = observers_.begin();

    while(it!=observers_.end()){
        (*it)->nextDay();
        ++it;
    }
    return *this;
}