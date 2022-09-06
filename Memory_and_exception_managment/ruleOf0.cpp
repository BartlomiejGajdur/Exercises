#include <iostream>
#include <memory>

template<typename T>
class X
{
private:
    std::shared_ptr<T> ptr_{nullptr};

public:
    X(T* ptr) : ptr_(ptr) {} //Konstruktor z gołego wskaźnika;
    X(std::shared_ptr<T> ptr) : ptr_(ptr) {} //Konstruktor z innego shared_ptr;
    T& get(){
        return *ptr_;
    }
    
};


int main(){
    X<int> x{new int{42}};
    X<int> x2{new int{42}};
    X<int> x3 = x;
    x2 = x;
    std::shared_ptr<int> p3 = std::make_shared<int>(32);
    x = p3;
    //x2 = x2;

    //X<int> x4{std::move(x2)};
    //x3 = std::move(x);

    auto & a = x.get();
    a++;
    std::cout<<x3.get()<<std::endl;
    std::cout<<x2.get()<<std::endl;
    std::cout<<x.get()<<std::endl;
    return 0;
}
