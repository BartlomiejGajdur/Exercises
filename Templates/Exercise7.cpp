#include <iostream>

template<typename... Args>
void print(Args&&... args){
    (std::cout<< ...<< args);
}

int main(){

    print(1.2, "Teks1",'c',5,500000);


    return 0;
}