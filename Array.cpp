/*Zadanie 1

    Pomyśl, kiedy empty() może zwrócić true dla std::array
    Znajdź dokumentację funkcji empty() dla std::array na cppreference.com
    Przejdź do sekcji Example i kliknij Run przy przykładzie z kodem
    Dopisz nową tablicę intów o rozmiarze 3 i nazwie other bez przypisywania jej elementów - std::array<int, 3> other;
    Dodaj kod odpowiedzialny za wyświetlenie informacji czy ta tablica jest pusta.
    Zweryfikuj to ze swoją intuicją z pierwszego punktu slightly_smiling_face
    Wypisz zawartość tablicy other
    Zmień kompilator np. na clang i zobacz czy zawartość jest ta sama

Zadanie 2

    Znajdź dokumentację std::array na cppreference.com
    Stwórz nowy plik i napisz funkcję main()
    Stwórz std::array przechowujący wartości całkowitoliczbowe o rozmiarze 10
    Wypełnij ją wartościami 5
    Do czwartego elementu przypisz wartość 3
    Stwórz inną tablicę o tym samym rozmiarze
    Podmień tablice
    Wypisz obie tablice, każdą w osobnej linii*/

#include <iostream>
#include <array>

int main(){

    //Zadanie 1 

    std::array<int,5> other;
    
    for (auto& arg : other)
    {
        std::cout<<arg<<" ";
    }
    std::cout<<std::endl;
    if(other.empty())
        std::cout<<"Empty";

    return 0;
}
