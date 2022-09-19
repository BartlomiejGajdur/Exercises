#include <iostream>
#include <memory>

int main(){
    
   auto ptr1 = std::unique_ptr<int>(new int{5});
   auto ptr2 = std::make_unique<int>(5);   // equivalent to above

    std::cout<<*msg;
    std::cout<<*a;
    std::cout<<&msg;
    std::cout<<&a;
    return 0;
}