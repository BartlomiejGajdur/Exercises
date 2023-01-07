/*
Write a template class which create an over-engineered std::map. 
It should hold 2 std::vectors inside with the same size, each with different types. Usage should look like this:

VectorMap<int, char> map;
map.insert(1, 'c');
map[1] = 'e';  // replaces value under 1
std::cout << map[1];  // prints 'e'
map.at(2); // throw std::out_of_range

First vector should hold keys, the other one values. 
Elements at the same position in both vectors should create a pair like 1 and 'c' above. 
Try to implement as much of std::map interface as possible, at least the mentioned above insert, operator[], at
*/
#include <iostream>
#include <vector>
#include <ostream>
#include <algorithm>

template<typename TypeA, typename TypeB>
class VectorMap{
    public:
    VectorMap(std::vector<TypeA> vectorInt, std::vector<TypeB> vectorChar) : vectorInt_(vectorInt), vectorChar_(vectorChar){};
    VectorMap(){};

     void insert(TypeA num, TypeB zn){
        vectorInt_.push_back(num);
        vectorChar_.push_back(zn);
    }

    TypeB& operator[](TypeA num){
        auto it = std::find(vectorInt_.begin(),vectorInt_.end(),num);
        auto dist = std::distance(vectorInt_.begin(),it);
        return vectorChar_[dist];
    }

    TypeB& at(int pos){
        if(pos<vectorInt_.size()){
            return vectorChar_[pos]; 
        }throw std::out_of_range("OutOfRange");
    }

    
    friend std::ostream& operator<<(std::ostream& os, const VectorMap<TypeA, TypeB>& vecMap){
        std::for_each(vecMap.vectorInt_.begin(),vecMap.vectorInt_.end(),[&vecMap,i{0},&os](TypeA num) mutable
                                                                                                 {
                                                                                                    os<<"Iteration "<<i+1<<" -> ["<<num<<","<<vecMap.vectorChar_[i]<<"]\n";
                                                                                                    ++i;
                                                                                                 });
        return os;
    }

    private:
    std::vector<TypeA> vectorInt_;
    std::vector<TypeB> vectorChar_;

   


};

int main(){

    std::vector<int> vecInt{1,2,3};
    std::vector<char> vecChar{'a','b','c'};

    VectorMap vecMap{vecInt,vecChar};
    std::cout << vecMap;
    std::cout<<std::endl;

    VectorMap<int, char> vecMap2;
    vecMap2.insert(2,'d');

    std::cout << vecMap2;
    std::cout<<std::endl;

    VectorMap<int, char> map;
    map.insert(1, 'c');
    map[1] = 'e';  // replaces value under 1
    std::cout << map[1]<<"\n";  // prints 'e'
    try{
        std::cout<<map.at(1); // throw std::out_of_range

    }catch (const std::out_of_range& ex){
        std::cout<<ex.what();
    }
    map.at(0) = 'j';
    std::cout<<map.at(0);
    return 0;
}
