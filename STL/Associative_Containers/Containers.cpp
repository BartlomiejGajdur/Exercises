#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <set>

// #1
namespace std{

    std::ostream& operator<<(std::ostream& out, const std::pair<int, std::string>& pair)
    {
        return out<<"Key: "<<pair.first<<"      Value: "<<pair.second<<"\n";
    }
}

void PrintMap(const std::multimap<int,std::string> &map){

    std::for_each(map.begin(),map.end(),[](auto pair){ 
        if(pair.second.size() >= 3)
            std::cout<<pair.second<<"\n";                   
    });
}

void PrintMap2(const std::multimap<int,std::string> &map){

    std::copy_if(begin(map),end(map),std::ostream_iterator<std::pair<int,std::string>>(std::cout , "\n"),[](auto pair){ 
        return pair.second.size() >= 3;});
}


void printMAP(const std::unordered_map<int,std::string>& mapa){
    for(auto[key,value] : mapa){
        std::cout<<"Key: "<<key<<"      Value: "<<value<<"\n";
    }

    std::cout<<"---------------------------------------------------------------------\n";
}

void printMAP(const std::multiset<int>& mapa){
    for(auto a : mapa){
        std::cout<<a<<" ";
    }

    std::cout<<"\n---------------------------------------------------------------------\n";
}


int main(){

    std::multimap<int,std::string> map;

    map.insert({5,"Ala"});
    map.insert({5,"Ma"});
    map.insert({5,"Kota"});
    map.insert({5,"A"});
    map.insert({5,"Kot"});
    map.insert({5,"Ma"});
    map.insert({5,"Ale"});

    PrintMap(map);
    std::cout<<"\n";
    PrintMap2(map);

    //

    std::unordered_map<int, std::string> uMAP = {
        {1,"Ala"},
        {2,"ma"},
        {3,"kota"}
    };

    printMAP(uMAP);

    uMAP.emplace(std::make_pair(4,"Dodatkowy ELement"));
    printMAP(uMAP);

    uMAP.erase(3);
    printMAP(uMAP);

    auto it = uMAP.begin();
    std::advance(it,2);
    uMAP.erase(it);
    printMAP(uMAP);

    uMAP.emplace(std::make_pair(4,"Dodatkowy ELement4"));
    uMAP.emplace(std::make_pair(5,"Dodatkowy ELemen5"));
    uMAP.emplace(std::make_pair(8,"Dodatkowy ELeme6666nt"));
    uMAP.emplace(std::make_pair(7,"Dodatkowy ELeme777777nt"));
    printMAP(uMAP);

    std::copy_if(begin(uMAP),end(uMAP),std::ostream_iterator<std::pair<const int, std::string>>(std::cout),[](const auto pair)
    {
        return pair.first % 2 == 0;
    });



    //

     std::multiset<int> mMAP = {
        1,3,4,5,2,1,5,2,3,5
    };

    printMAP(mMAP);

    mMAP.emplace(10);
    printMAP(mMAP);

    mMAP.erase(mMAP.find(4), mMAP.end());
    printMAP(mMAP);

    std::copy_if(begin(mMAP),end(mMAP),std::ostream_iterator<int>(std::cout, " "),[](const auto pair)
    {
        return pair % 2 == 0;
    });

    


    return 0;
}