#include <algorithm>
#include <iostream>
#include <vector>
#include <utility>
#include <type_traits>

class K{
    K(int k){};
    K(){};
};

template <typename Key, typename Value>
class VectorMap{  
public:
    static_assert(std::is_default_constructible_v<Value>); // Zapewnia ze ten typ ktory podajemy na domyslny constructor


    void insert(Key&& key, Value&& value){
        keys_.emplace_back(std::forward<Key>(key));
        values_.emplace_back(std::forward<Value>(value));
    }

    Value& operator[](Key&& key){
        auto find = std::find(keys_.begin(),keys_.end(),key);
            if(find==keys_.end()){ //Jesli nie znajdzie wstaw nowy element
                keys_.emplace_back(std::forward<Key>(key));
                values_.emplace_back(Value{}); //Domyślny konstruktor 
                return values_.back();
            }
        auto dist = std::distance(keys_.begin(),find);
        return values_[dist];
    }

    Value& at(Key key){
        auto find = std::find(keys_.begin(),keys_.end(),key);

            if(find==keys_.end()){ //Jesli nie znajdzie wstaw nowy element
                throw std::out_of_range("No such element");
            }

        auto dist = std::distance(keys_.begin(),find);
        return values_[dist];
    }

private:
    std::vector<Key> keys_;
    std::vector<Value> values_;
};
 

int main(){
    VectorMap<int, char> map;
    map.insert(1, 'c');
    map[1] = 'e';  // replaces value under 1
    std::cout << map[1];  // prints 'e'
   // map.at(2); // throw std::out_of_range

    VectorMap<int, K> map2;
    return 0;
}
