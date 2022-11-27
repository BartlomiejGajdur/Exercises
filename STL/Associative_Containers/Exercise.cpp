#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <string>
#include <cmath>
#include <ostream>

struct Point{
    int x,y;
    friend std::ostream& operator<<(std::ostream& os, const Point& P){
        return os<<"{"<<P.x<<","<<P.y<<"}";
    }
};

//Shall return distance from {0,0} to Point p{x,y}
double distance(const Point& p){
    return std::sqrt(std::pow(p.x,2)+std::pow(p.y,2));
}


int main(){

    std::unordered_map<std::string, Point> mapa{
        {"Wroclaw",{17,51}},
        {"Moskwa",{37,55}},
        {"NowyJork",{-74,40}},
        {"Sydney",{151,-33}},
    };

    auto it = std::find_if(mapa.begin(),mapa.end(),
    [](const std::pair<const std::string, Point>& n)
    {
        return distance(n.second)<=70;
    });

    if(it!=mapa.end()){
        std::cout<<"\n"<<it->first<<" "<<it->second<<"\n";
    }
    std::cout<<"-----------------------------\n";

    std::for_each(mapa.begin(),mapa.end(),
    [](const std::pair<const std::string, Point>& n)
    {
        if(distance(n.second)<=70){
            std::cout<<n.first<<" "<<n.second<<"\n";
        } 
    });

    std::cout<<"-----------------------------\n";
    auto it2 = mapa.find("Sydney");

    if(it2!=mapa.end()){
        std::cout<<it2->first<<" "<<it2->second<<"\n";
    }
    


    return 0;
}