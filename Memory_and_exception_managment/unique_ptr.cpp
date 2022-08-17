/* Tworzenie własnego unique_ptr*/
#include <iostream>
namespace cs{
template <typename T>
class unique_ptr {
private:
    T* ptr_{nullptr}; //inicjalizacja nullptr aby zapobiec UB

public:
    unique_ptr(T* ptr = nullptr) : ptr_{ptr}{}
    ~unique_ptr(){
        delete ptr_;
    };

    T& operator*() const{
        return *ptr_;
    }

    T* get() const{
        return ptr_;
    }

    T* release(){
        T* temp_ptr = ptr_;
        ptr_ = nullptr;
        return temp_ptr;
    }

    void reset(T* ptr = nullptr){ //dodac nullptr
        delete ptr_;
        ptr_ = ptr;
    }

    void reset(){   // sprawdzic te funkcje 
        delete ptr_;
    }


};

}



int main(){

cs::unique_ptr ptr{new int{5}};
std::cout<< *ptr<<'\n';
std::cout<< ptr.get()<<'\n';
auto rawPtr =  ptr.release();
delete rawPtr;
// //cs::unique_ptr<int> ptr2 = ptr; //Zabronione
// cs::unique_ptr<int> ptr2 = std::move(ptr);

// ptr.reset(new int {10});
// ptr.reset();




    return 0;
}