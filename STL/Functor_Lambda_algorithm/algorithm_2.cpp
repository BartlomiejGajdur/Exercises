#include <iostream>
#include <algorithm>
#include <numeric>
#include <math.h>
#include <functional>

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

zadanie4
Napisz funckje która zwróci vector z wartościami od 10 do 10+n inkrementujac je co 1
Napisz funkcje ktora zwroci wartosc rowna iloczynowi kazdego elementu vectora.

zadanie5
Napisz program, który obliczy średnią artymetyczną dwóch vectorow

zadanie6
Program który obliczy średnią euklidesowa
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

std::vector<int> GetVec(size_t count){

    std::vector<int> vec(count);
    std::iota(vec.begin(),vec.end(),10);

    return vec;
}

int multiply(std::vector<int> vec){
    return std::accumulate(vec.begin(),vec.end(),1,std::multiplies<int>());
}

// Inner product(zakres1_poczatek,zakres1_koniec,zakres2_poczatek,wartosc_inicjujaca, juz po kolei co ma robic jak juz mamy teoretycznie jeden zakres,Po jednej wartosci z kazdego zakresu i co z nimi robimy )
double sredniaArtymetyczna(const std::vector<int>& vec1, const std::vector<int>& vec2){
   
    double suma = std::inner_product(vec1.begin(),vec1.end(),vec2.begin(),0,std::plus<int>(), [](int a, int b){
        std::cout<<"a"<<a<<"  b"<<b<<std::endl;
        return a+b;});
    std::cout<<suma<<std::endl;
    return suma/(vec1.size()*2);
}

double euklides(const std::vector<int>& vec1, const std::vector<int>& vec2 ){
    double suma = std::inner_product(vec1.begin(),vec1.end(),vec2.begin(),0,std::plus<int>(), [](int a, int b){
        std::cout<<"a"<<a<<"  b"<<b<<std::endl;
        return std::pow(b-a,2);});
        
    std::cout<<suma<<std::endl;
    return std::sqrt(suma);
}

int main(){

    std::vector<int> vec{1,2,3,4,5,6,7,8,9,10};
    std::cout<<"-----STD::ROTATE-----\n";
    printVec(vec);
    changePos1(vec,2,8);
    printVec(vec);
    changePos1(vec,2,2);
    printVec(vec);

    std::vector<int> values{1,5,9,6};
    std::cout<<"\n\n-----STD::STABLE_PARTITION-----\n";
    printVec(vec);
    changePos2(vec,values,5);
    printVec(vec);

    std::vector<int> vec2{1,2,3,4,5,6,7,8,9,10};
    std::cout<<"\n\n-----STD::STABLE_PARTITION-----\n";
    printVec(vec2);
    changePos3(vec2,values,6);
    printVec(vec2);

    std::cout<<"\n\n-----GATHER*-----\n";
    std::vector<char> vec3{',','*','d','.','/','/','*','!','*','*'};
    printVec(vec3);
    Gather(vec3);
    printVec(vec3);

    std::cout<<"\n\n-----Exercise4-----\n";
    vec2.clear();
    vec2 = GetVec(7);
    printVec(vec2);
    std::cout<<multiply(vec2)<<std::endl;

    std::cout<<"\n\n-----SredniaArtymetyczna-----\n";
    std::vector<int> vec5{1,2,3,4};
    std::vector<int> vec6{1,2,3,4};
    std::cout<<sredniaArtymetyczna(vec5,vec6)<<std::endl;

    std::cout<<"\n\n-----Euklides-----\n";
    std::vector<int> vec7{7,4,3};
    std::vector<int> vec8{17,6,2};
    std::cout<<euklides(vec7,vec8)<<std::endl;
    
    return 0;
}
>>>>>>> 2b0af77d7a0923f0061efc383b79ef53420c7f62
