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

void printDeque(const std::deque<int>&);

int main(){

    std::deque<int> zadanie{1,2,3,4,5};

    printDeque(zadanie);

    zadanie.erase(zadanie.begin()+1,zadanie.begin()+2);
    zadanie.erase(zadanie.begin()+2,zadanie.begin()+3);
    printDeque(zadanie);

    zadanie.push_back(30);
    zadanie.push_front(30);
    printDeque(zadanie);

    zadanie.insert(zadanie.begin()+3,20);
    printDeque(zadanie);

    std::cout<<zadanie.size();
    zadanie.shrink_to_fit();
    
    return 0;
}

void printDeque(const std::deque<int>& deque)
{
    for (const auto& ele : deque)
    {
        std::cout<<ele<<" ";
    }
    std::cout<<std::endl;
}
