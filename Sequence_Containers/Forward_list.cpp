/*Zadanie

    Znajdź dokumentację std::forward_list na cppreference.com
    Skorzystaj z kodu z zadania z std::list
    Stwórz listę jednokierunkową zawierającą elementy od 0 do 5
    Wyświetl listę
    Usuń 3 element z listy
    Dodaj na początek i koniec listy wartość 10
    Wyświetl listę
    Dodaj na czwartej pozycji liczbę 20
    Wyświetl listę
*/

#include <iostream>
#include <forward_list>

void printForwardList(const std::forward_list<int>&);

int main(){

    std::forward_list<int> zadanie {1,2,3,4,5};
    printForwardList(zadanie);

    auto it1 = zadanie.begin();
    std::advance(it1,1);
    auto it2 = zadanie.begin();
    std::advance(it2,3);

    zadanie.erase_after(it1,it2);
    printForwardList(zadanie);


    
    zadanie.insert_after(zadanie.before_begin(),10);
    printForwardList(zadanie);

    auto it3= zadanie.before_begin();
    std::advance(it3,5);


    zadanie.insert_after(it3,10);
    printForwardList(zadanie);

auto it4= zadanie.before_begin();
    std::advance(it4,3);   

 zadanie.insert_after(it4,20);
 printForwardList(zadanie);

    return 0;
}

void printForwardList(const std::forward_list<int>& list)
{
    for (auto & ele : list)
    {
        std::cout<<ele<<" ";
    }
    std::cout<<std::endl;
}