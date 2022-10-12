#pragma once
#include <list>

class Observer{
    public:
    virtual void nextDay() = 0;
    virtual ~Observer(){};
};

class Time{
    public:
    Time();
    Time(int gameDays): gameDays_(gameDays) {}

    void addObserver(Observer* obs);
    void removeObserver(Observer* obs);

    Time& operator++();

    private:
    int gameDays_;
    std::list<Observer*> observers_;

};