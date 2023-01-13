#include <string>   
#include <iostream>

template<class... Types>
void variadic_foo(Types&&... args){
}

template<class... Types>
class variadic_class{
};

////@@@@@@@@@


template<typename T>
void printMany(T&& arg) {
    std::cout << arg << std::endl;
}


template<typename T, typename... Args>
void printMany(T&& arg, Args&&... args) {
    std::cout << arg << " ";
    printMany(args...);
}

template<typename... Args>
void print_all(Args&&... args){
    printMany(args...);
    //Expands to printMany(arg1,arg2, ..., argN);
}




int main(){

    //variadic_foo(1," ",2u);
    //variadic_class<float,int, std::string> v{};
    //variadic_class k{2.0,5,"Hello"}; //dedukcja typow C++17

    print_all("Hello","Bartlomiej","Bartlomiej");
    return 0;
}