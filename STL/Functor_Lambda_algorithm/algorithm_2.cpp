#include <iostream>
#include <algorithm>

/*
Zadanie1
Napisz funckje, który przyjmie vector, zmienna int value, zmienna int new_pos. 
Funkcja powinna znaleźć value w vectorze i jeśli ją znajdzie wstawi na nowe miejsce new_pos,
odpowiednio przesuwając reszte elementów

Zadanie2
Napisz funkcje, która przyjmie dwa std::vector<int> oraz zmienną int.
Pierwszy vector zaweira kontener na którym operujemy, drugei zawiera wartości jakie
chcemy przenieść, a wartość int to numer indexu, na który chcemy przenieść wartości

zadanie3
Napisz funkcję Gather, która przyjmie std::vector<char> oraz spowoduje,
że wszystkie wystąpienia * pojawią się w środku std::vector<char>
*/
template <typename T>
void printVec(const std::vector<T>& vec){
    std::for_each(vec.begin(),vec.end(),[](const T& a){ std::cout<<a<<" ";});
    std::cout<<"\n";
}
bool changePos1(std::vector<int>& vec, int value, int new_pos){


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

void changePos2(std::vector<int>& vec, const std::vector<int>& values, int new_pos ){
    auto pred {[&](auto &el)
        {return (std::find(values.begin(),values.end(),el) == values.end());}};

    auto middle = vec.begin()+new_pos+values.size()-2;

    std::stable_partition(vec.begin(),middle,pred);
    std::stable_partition(middle,vec.end(),[&](auto &el){return !pred(el);});

}

bool changePos3(std::vector<int>& vec, const std::vector<int>& values, int new_pos ){
    
    if(new_pos+values.size()-1>vec.size() || new_pos<=0)
    {
        std::cout<<"\nNew_pos error\n";
        return false;
    }

    auto pred {[&](auto &el)
        {return (std::find(values.begin(),values.end(),el) != values.end());}};

  
    std::stable_partition(vec.begin(),vec.end(),pred);
    std::rotate(vec.begin(),vec.begin()+values.size(),vec.begin()+values.size()+new_pos-1);
    return true;  
}

void Gather(std::vector<char>& vec){

    auto pred {[&vec](const char& a)
                {return a != '*'; }};

    auto middle = vec.begin() + vec.size()/2;


    std::stable_partition(vec.begin(),middle,pred);
    std::stable_partition(middle,vec.end(),[&vec,pred](const char& a){return !pred(a);});

}

int main(){

    std::vector<int> vec{1,2,3,4,5,6,7,8,9,10};
    std::cout<<"-----STD::ROTATE-----\n\n";
    printVec(vec);
    changePos1(vec,2,8);
    printVec(vec);
    changePos1(vec,2,2);
    printVec(vec);

    std::vector<int> values{1,5,9,6};
    std::cout<<"\n\n\n-----STD::STABLE_PARTITION-----\n";
    printVec(vec);
    changePos2(vec,values,5);
    printVec(vec);

    std::vector<int> vec2{1,2,3,4,5,6,7,8,9,10};
    std::cout<<"\n\n\n-----STD::STABLE_PARTITION-----\n";
    printVec(vec2);
    changePos3(vec2,values,6);
    printVec(vec2);

    std::cout<<"\n\n\n-----GATHER*-----\n";
    std::vector<char> vec3{',','*','d','.','/','/','*','!','*','*'};
    printVec(vec3);
    Gather(vec3);
    printVec(vec3);
    return 0;
}