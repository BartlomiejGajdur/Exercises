/*
Zadanie

    Znajdź dokumentację std::list na cppreference.com
    Stwórz nowy plik i napisz funkcję main()
    Stwórz listę zawierającą elementy od 0 do 5
    Wyświetl listę
    Usuń trzeci element z listy
    Dodaj na początek i koniec listy wartość 10
    Wyświetl listę
    Dodaj na czwartej pozycji liczbę 20
    Przepisz listę do std::array
    Wyświetl std::array
*/

#include <iostream>
#include <list>
#include <array>

void printList(const std::list<int>& );

int main(){

    std::list<int> zadanie1 {1,2,3,4,5};
    printList(zadanie1);
    
    zadanie1.remove(3);
    printList(zadanie1);

    zadanie1.push_back(10);
    zadanie1.push_front(10);
    printList(zadanie1);

    auto it = zadanie1.begin();
    std::advance(it,3);
    zadanie1.insert(it,20);
    printList(zadanie1);

    std::array<int,7> arr;
    size_t i = 0;

    for (auto & ele:zadanie1)
    {
        arr[i]=ele;
        ++i;
    }

     for (auto & ele:arr)
    {
        std::cout<<ele<<" ";
    }


    return 0;
}

void printList(const std::list<int>& list)
{
    for(auto &element : list)
    {
        std::cout<<element<<" ";
    }
    std::cout<<std::endl;
}