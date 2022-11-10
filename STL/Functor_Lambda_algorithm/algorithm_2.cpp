#include <algorithm>
#include <iostream>
#include <vector> 

void printVector(const std::vector<int>& vec)
{
    std::for_each(vec.begin(),vec.end(),[](const int& a){std::cout<<a<<" ";});
    std::cout<<std::endl;
}

bool rotate(std::vector<int>& vec, int value, int new_pos){
    //Odnalezienie w vec -> value
    //Jeżeli znajdzie -> wstawić na pozycje new_pos -> return true
    //Nie uda sie zamienić -> return false
    auto it = std::find(vec.begin(),vec.end(),value);
    
    if(it == vec.end() || vec.size() < new_pos)
    {
        std::cout<<"false\n";
        return false;
    }
    
    auto distance = std::distance(vec.begin(),it);
    
    if(distance < new_pos){
        std::rotate(vec.begin()+distance,vec.begin()+distance+1,vec.begin()+new_pos);
    }else{
        std::rotate(vec.begin()+new_pos,vec.begin()+distance+1,vec.begin()+distance);
    }
    
    return true;
}

int main()
{
    
    std::vector<int> v{1,2,3,4,5};
    printVector(v);
    rotate(v,4,2);
    printVector(v);
    return 0;
}
