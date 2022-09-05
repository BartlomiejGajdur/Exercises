/* Tworzenie własnego unique_ptr*/
// = delete nie mozna uzyc funkcji 
// = default domyslna implementacja (Tylko dla 6 )
#include <iostream>
namespace cs{
template <typename T>
class unique_ptr {
private:
    T* ptr_{nullptr}; //inicjalizacja nullptr aby zapobiec UB

public:
    unique_ptr(T* ptr = nullptr) : ptr_{ptr}{}
    unique_ptr(const unique_ptr<T>&) =delete; //Konstruktor kopiujący jako delete (zakazany)                         (1)
    unique_ptr<T>& operator=(const unique_ptr<T>&) = delete; // Operator przypisania kopiujący jako delete (zakazany) (2)

    unique_ptr(unique_ptr<T>&& otherPtr) : ptr_{otherPtr.release()} {}
    unique_ptr<T>& operator=(unique_ptr<T>&& otherPtr){
        if(this != &otherPtr)  // this i otherPtr nie wskazuja na ten sam adres
        {
            delete ptr_;
            ptr_= otherPtr.get();
            otherPtr.ptr_ = nullptr;
        }
        return *this;
    }
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

    void reset(T* ptr){ 
        delete ptr_;
        ptr_ = ptr;
    }

    void reset(){   
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

//cs::unique_ptr<int> ptr2 = ptr;          // (1)
//cs::unique_ptr<int> ptr3{new int {5}};
//ptr3 = ptr;                              // (2)


cs::unique_ptr<int> ptr2{new int{2}};
ptr2 = std::move(ptr);

 ptr.reset(new int {10});
 std::cout<< *ptr<<std::endl;

 ptr.reset();
 std::cout<< *ptr;


    return 0;
}