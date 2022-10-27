/*Zadanie

    Znajdź dokumentację std::deque na cppreference.com
    Stwórz nowy plik i napisz funkcję main()
    Stwórz pusty deque
    Dodaj do niego 5 dowolnych wartości
    Wyświetl deque
    Usuń 2-gi i 4-ty element
    Dodaj na początek i koniec wartość 30
    Wyświetl deque
    Dodaj na 4 pozycji liczbę 20
    Wyświetl deque
*/

#include <iostream>
#include <deque>

void printDeque(const std::deque<int>& kolejka)
{
    for (const auto& ele: kolejka){
        std::cout<<ele<<" ";
    }
    std::cout<<std::endl;
}

int main(){

    std::deque<int> kolejka{1,2,3,4,5};
    printDeque(kolejka);

    kolejka.erase(std::next(kolejka.begin(),1));
    kolejka.erase(std::next(kolejka.begin(),3));
    printDeque(kolejka);

    kolejka.push_front(30);
    kolejka.push_back(30);
    printDeque(kolejka);
    




    return 0;
}