#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <string>
#include <cmath>
#include <ostream>
#include <functional>
#include <set>
#include <iomanip>


struct Point{
    int x_,y_;
    Point(){}
    Point(int x, int y) : x_(x), y_(y) {}
    friend std::ostream& operator<<(std::ostream& os, const Point& P){
        return os<<"{"<<P.x_<<","<<P.y_<<"}";
    } 


    bool operator==(const Point& other) const {
        return x_ == other.x_ && y_ == other.y_;
    }

<<<<<<< HEAD
     struct HashFunction{
        size_t operator()(const Point& pos) const
        {
        size_t xHash = std::hash<int>()(pos.x_);
        size_t yHash = std::hash<int>()(pos.y_) << 1;
        return xHash ^ yHash;
        }
=======
    bool operator< (const Point& lhs)const {
        return distance(*this)<distance(lhs);
    }
    bool operator> (const Point& lhs)const {
        return distance(*this)>distance(lhs);
    }

     struct HashFunction
  {
    size_t operator()(const Point& pos) const
    {
      size_t xHash = std::hash<int>()(pos.x);
      size_t yHash = std::hash<int>()(pos.y) << 1;
      return xHash ^ yHash;
    }
>>>>>>> c370bb77f9ac32dd0cc7506c89f07026b2e07e39
  };

  friend double distance(const Point& p);
};

//Shall return distance from {0,0} to Point p{x,y}
double distance(const Point& p){
    return std::sqrt(std::pow(p.x_,2)+std::pow(p.y_,2));
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

    std::cout<<"\n\n----------EXERCISE2-------------\n";

    std::unordered_map<Point, std::string, Point::HashFunction> Rmapa{
        {{17,51},"Wroclaw"},
        {{37,55}, "Moskwa"},
        {{-74,40},"NowyJork"},
        {{151,-33}, "Sydney"},
    };

    auto it3 = std::find_if(Rmapa.begin(),Rmapa.end(),
    [](const std::pair<Point , const std::string>& n)
    {
        return distance(n.first)<=70;
    });

    if(it3!=Rmapa.end()){
        std::cout<<"\n"<<it3->first<<" "<<it3->second<<"\n";
    }
    std::cout<<"-----------------------------\n";
    
    std::for_each(Rmapa.begin(),Rmapa.end(),
    [](const std::pair<Point , const std::string>& n)
    {
        if(distance(n.first)<=70){
            std::cout<<n.first<<" "<<n.second<<"\n";
        } 
    });

    std::cout<<"-----------------------------\n";
    std::for_each(Rmapa.begin(),Rmapa.end(),
    [](const std::pair<Point , const std::string>& n)
    {
        if(n.second=="Sydney"){
            std::cout<<n.first<<" "<<n.second<<"\n";
        } 
    });
    Point P1{1,2};
    Point P2{3,4};
    Point P3{3,7};

    std::set<Point,std::greater<Point>> puunkty{P1,P2,P3};

    std::cout<<std::setprecision(2)<<"DISTANCE:  P1: "<<distance(P1)<<"      P2: "<<distance(P2)<<"      P3: "<<distance(P3)<<"\n";

    std::for_each(puunkty.begin(),puunkty.end(),[](const Point& p){ std::cout<<p<<"  ";});

    std::cout<<(0b0000000010 >> 1);
    return 0;
}