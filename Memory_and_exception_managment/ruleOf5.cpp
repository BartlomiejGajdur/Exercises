#include <iostream>


template<typename T>
class X{
    private:
        T* ptr_ = nullptr;
    
    public:
        X(T* p) : ptr_(p) {}
        ~X(){
            delete ptr_;
        }
        X(const X& other) {
            if (other.ptr_ == nullptr){
                ptr_ = nullptr;
            }else{
               ptr_ = new T{*other.ptr_}; //Głęboka kopia
            }
        } 

        X& operator=(const X& other)
        {   
            if (&other != this && other.ptr_ != nullptr)
            {
                delete ptr_;
                ptr_ = new T{*other.ptr_};
                return *this;
            }else if (&other != this && other.ptr_ == nullptr)
            {
                delete ptr_;
                ptr_ = nullptr;
                return *this;
            }
            return *this;
        }

        X(X&& other){
            ptr_ = other.ptr_;
            other.ptr_ = nullptr;
        }

        X& operator=(X && other){
            if (this != &other)
            {
                delete ptr_;
                ptr_ = other.ptr_;
                other.ptr_ = nullptr;
            }

            return *this;        
        }

        T& get(){
            return *ptr_;
        }



};


int main(){
    X<int> x{new int{42}};
    X<int> x2{new int{42}};
    X<int> x3 = x;
    x2 = x;
    //x2 = x2;

    //X<int> x4{std::move(x2)};
    //x3 = std::move(x);

    // auto & a = x.get();
    // a++;
    //std::cout<<x4.get()<<std::endl;
    //std::cout<<x2.get()<<std::endl;
    // std::cout<<x.get()<<std::endl;
    std::cout<<x2.get()<<std::endl;
    std::cout<<x3.get()<<std::endl;

}