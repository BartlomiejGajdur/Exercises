#include <iostream>

template<typename... Args>
void print(Args&&... args){
    (std::cout<< ...<< args)<<"\n";
}

template<typename... Args>
bool AllEven(Args&&... args){
    print(args...);
    return ((args % 2 == 0) && ...);
}

int main(){

    print(1.2, "Teks1",'c',5,500000);

    std::cout<<std::boolalpha<<AllEven(2,4,6,8);
    std::cout<<std::boolalpha<<AllEven(2,4,6,7);


    return 0;
}