#include <iostream>
#include <forward_list>
#include <vector>
#include <iterator>
#include <list>

/*
Zadanie
Napisz funkcję middle, która może być wywoływana na różnych kontenerach.

Funkcja ta powinna zwracać środkowy element w kolekcji.

Napisz ją w konwencji algorytmów z biblioteki STL, czyli jako argumenty chcemy podać 2 iteratory:

auto middle(Iter first, Iter last);
Za Iter musisz podstawić właściwe typy parametrów i napisać kilka przeciążeń tej funkcji.
*/

template <typename itr>
auto middle(itr begin,itr last){ 

    auto size = std::distance(begin,last);
    std::cout<<"size: "<<size<<" | ";
    return std::next(begin, size/2);
}

/*
auto middle(std::list<int>::iterator begin,std::list<int>::iterator last){ 

    auto size = std::distance(begin,last);
    std::cout<<"size: "<<size<<" | ";
    return std::next(begin, size/2);
}

auto middle(std::vector<int>::iterator begin,std::vector<int>::iterator last){ 

    auto size = std::distance(begin,last);
    std::cout<<"size: "<<size<<" | ";
    return std::next(begin, size/2);
}

auto middle(std::forward_list<int>::iterator begin,std::forward_list<int>::iterator last){ 

    auto size = std::distance(begin,last);
    std::cout<<"size: "<<size<<" | ";
    return std::next(begin, size/2);
}
*/

int main(){

    std::vector<int> vk{ 3, 1, 4 };
 
    auto it = vk.end();
    auto pv = std::prev(it,2);
    std::cout << *pv << '\n';
 
    it = vk.begin();
    pv = std::prev(it, -2);
    std::cout << *pv << '\n';

    std::list<int> lista                {1,2,3,4,5,6,7,8,9,10,11};
    std::vector<int> vector             {1,2,3,4,5,6,7,8,9,10,11};
    std::forward_list<int> forwardLista {1,2,3,4,5,6,7,8,9,10,11};

    auto mid = middle(lista.begin(),lista.end());
    std::cout<<*mid<<" \n";

    auto mid1 = middle(vector.begin(),vector.end());
    std::cout<<*mid1<<" \n";

    auto mid2 = middle(forwardLista.begin(),forwardLista.end());
    std::cout<<*mid2<<" \n";

    return 0;
}