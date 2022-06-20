/*Zadanie 1

    Otwórz dokumentację wektora na cppreference.com
    Stwórz nowy plik i napisz funkcję main()
    Stwórz wektor o wartościach {1, 2, 4, 5, 6}
    Usuń pierwszą wartość
    Dodaj wartość 5 na końcu wektora
    Dodaj wartość 12 na początku wektora metodą emplace
    Wypisz rozmiar wektora i maksymalny możliwy rozmiar
    Wypisz zawartość wektora
    Wyczyść wektor
    Wypisz rozmiar wektora

Zadanie 2

    Otwórz dokumentację wektora na cppreference.com
    Stwórz nowy plik i napisz funkcję main()
    Stwórz pusty wektor
    Wypisz rozmiar i pojemność wektora
    Zmień rozmiar wektora na 10 i wypełnij go wartościami 5
    Wypisz rozmiar i pojemność wektora
    Zarezerwuj pamięć na 20 elementów
    Wypisz rozmiar i pojemność wektora
    Zredukuj pojemność wektora metodą shrink_to_fit()
    Wypisz rozmiar i pojemność wektora*/

#include <iostream>
#include <vector>

void wypiszVector(const std::vector<int>&);
void paramVector(const std::vector<int>&);

int main()
{
    //Zadanie 1: 

    std::vector<int> zadanie1 {1,2,4,5,6};
    zadanie1.erase(zadanie1.begin());
    wypiszVector(zadanie1);
    
    zadanie1.push_back(5);
    wypiszVector(zadanie1);

    zadanie1.emplace(zadanie1.begin(),12);
    wypiszVector(zadanie1);

    paramVector(zadanie1);
  
    zadanie1.clear();
    wypiszVector(zadanie1);

    paramVector(zadanie1);


    //Zadanie 2:
    std::cout<<"\n\nZadanie - 2\n\n";
    
    std::vector<int> zadanie2;

    paramVector(zadanie2);

    zadanie2.reserve(10);
    paramVector(zadanie2);

    zadanie2.insert(zadanie2.begin(),10,5);
    wypiszVector(zadanie2);
    paramVector(zadanie2);
    
    zadanie2.reserve(20);
    paramVector(zadanie2);

    zadanie2.shrink_to_fit();
    paramVector(zadanie2);

    return 0;
}

void wypiszVector(const std::vector<int>& vec)
{
    for(auto & element : vec)
    {
        std::cout<<element<<" ";
    }
    std::cout<<std::endl;
}

void paramVector(const std::vector<int>& vec)
{
    std::cout<<"Size: " << vec.size()<<"  Capacity: "<< vec.capacity()<<std::endl;
}