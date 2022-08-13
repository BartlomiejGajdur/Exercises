#include <iostream>

int funkcja(){
    std::cout<<"Hejj"<<std::endl;
    return 10;
}

void funkcja2(int a)
{
    std::cout<<"Wynik dodawania 10+ 23 to:"<<std::endl;
    std::cout<<a+23;
}

int main(){

    funkcja2(funkcja());


    return 0;
}