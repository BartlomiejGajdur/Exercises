#include <iostream>
#include <vector>
#include <algorithm>

int main(){

    auto lambda = [](int liczba) -> bool {return liczba % 6 == 0;};
    if(lambda(24)){
        std::cout<<"Podzielna przez 6";
    }else{
        std::cout<<"Niepodzielna przez 6";
    }

    auto lambda_2 = [](int liczba1, int liczba2){return liczba1*liczba2;};
    std::cout<<"\n"<<lambda_2(10,2)<<"\n";

    auto lambda_3 = [](const std::string& text){ return "\"" + text + "\"";};
    std::cout<<lambda_3("Tekst")<<std::endl;

    int liczba = 1;
    auto lambda_4 = [&liczba]
                    (){for(int i = 0 ; i<liczba; i++ )
                    {
                        std::cout<<"*";
                    }
                    std::cout<<std::endl;
                    ++liczba;                
                    };

    lambda_4();
    lambda_4();
    lambda_4();
    lambda_4();
    lambda_4();
    lambda_4();


    std::vector<int> vec{1,2,3,4,5};

    auto lambda5 = [&vec](){ for(const auto& v: vec){
                                    std::cout<<v<<" ";
                                    }};

    auto lambda6 = [](const int& a){ std::cout<<a<<" ";};

    lambda5();
    std::cout<<"\n";
    std::for_each(vec.begin(),vec.end(), lambda6);
    
    std::cout<<"\n";
    auto lambda7 = [&vec, lambda6](){std::for_each(vec.begin(),vec.end(), lambda6);};
    lambda7();


    return 0;
}