#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <algorithm>

namespace std{

    std::ostream& operator<<(std::ostream& out, const std::pair<int, std::string>& pair)
    {
        return out<<pair.second;
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
    

    return 0;
}