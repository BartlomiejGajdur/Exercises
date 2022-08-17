/* Tworzenie własnego unique_ptr*/

namespace cs{

class unique_ptr {


};

}



int main(){

cs::unique_ptr ptr{new int{5}};
std::cout<< *ptr<<'\n';
std::cout<< ptr.get()<<'\n';
std::cout<< ptr.release()<<'\n';

//cs::unique_ptr<int> ptr2 = ptr; //Zabronione
cs::unique_ptr<int> ptr2 = std::move(ptr);

ptr.reset(new int {10});
ptr.reset();




    return 0;
}