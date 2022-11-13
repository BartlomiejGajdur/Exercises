#include <iostream>
#include <algorithm>

/*Napisz funckje, który przyjmie vector, zmienna int value, zmienna int new_pos. 
Funkcja powinna znaleźć value w vectorze i jeśli ją znajdzie wstawi na nowe miejsce new_pos,
odpowiednio przesuwając reszte elementów*/

bool changePos(std::vector<int>& vec, int value, int new_pos){


    if (new_pos <= 0 || new_pos>vec.size())
        return false;

    auto valuePostion = std::find(vec.begin(),vec.end(),value);

    auto valuePostionDistance = std::distance(vec.begin(),valuePostion);

    if(valuePostionDistance < new_pos){
        std::rotate(vec.begin()+valuePostionDistance,vec.begin()+valuePostionDistance+1, vec.begin()+new_pos);
    }else{
        std::rotate(vec.begin()+new_pos-1,vec.begin()+valuePostionDistance,vec.begin()+valuePostionDistance+1);
    }

    return true;
}

void printVec(const std::vector<int>& vec){
    std::for_each(vec.begin(),vec.end(),[](const int& a){ std::cout<<a<<" ";});
    std::cout<<"\n";
}

int main(){

    std::vector<int> vec{1,2,3,4,5,6,7,8,9,10};
    std::cout<<"-----STD::ROTATE-----\n\n";
    printVec(vec);
    changePos(vec,2,8);
    printVec(vec);
    changePos(vec,2,2);
    printVec(vec);
    std::cout<<"\n\n\n-----STD::STABLE_PARTITION-----\n";
    return 0;
}