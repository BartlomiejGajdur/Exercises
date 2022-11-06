#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
#include <random>
#include<list>
#include <deque>
#include <map>
/*
1. Utwórz poniższy wektor:

std::vector<std::pair<int, std::string>> v {
    {0, "Zero"}, {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"}
};
2. Utwórz wektor intów v2 i wypełnij go wszystkimi intami (pierwszymi elementami pary) z wektora v

3. Utwórz wektor stringów v3 i wypełnij go konkatenacją string + dwukropek + int ze wszystkich par z wektora v

4. Utwórz wektor charów v4 i wypełnij go co drugą literą alfabetu.

5. Utwórz std::vector<int> v = {8, 2, 5, 3, 4, 4, 2, 7, 6, 6, 1, 8, 9};

6. Usuń wszystkie duplikaty z v

7. Wypisz wszystkie elementy używając std::copy i std::ostream_iterator

8. Pomieszaj losowo wszystkie elementy

9. Wypisz je raz jeszcze

---------------------------------------------------------

10.[insensitive-palindrom] Napisz program, który będzie sprawdzał, czy podany ciąg wyrazów jest palindromem. 
Program powinien ignorować znaki specjalne np. ,.?()[] (i nie tylko). 
Powinien również ignorować wielkość liter oraz białe znaki jak spacja czy znak nowej linii.

11. [transform-containers] Napisz funkcję, która:
 a) Przyjmie std::list<std::string> oraz std::deque<int>
 b) Usunie duplikaty z obu kontenerów
 c) Na koniec skonwertuje to na std::map<int, std::string> i ją zwróci. Użyj std::transform.
*/
template<typename T>
    void printVector(const std::vector<T>& v){
        std::for_each(v.begin(),v.end(),[](const auto a){std::cout<<a<<" ";});
        std::cout<<"\n";
    }

bool insensitivePalindrom(const std::string& text){
    std::string b = text;

    std::transform(b.begin(),b.end(),b.begin(),[](char& a){return tolower(a);});
    b.erase(std::remove_if(b.begin(),b.end(),[](const char a){return a<97 || a>122;}),b.end());

    return std::equal(b.begin(), b.begin() + b.size()/2,b.rbegin());
}

void testInsensitivePalindrom(const std::string& text)
{
    std::cout<<"Word: "<<"\""<<text<<"\""<<(insensitivePalindrom(text)?" is" : " is not")<<" a insensitive Palindrom :)\n";
}

std::map<int, std::string> converter(std::list<std::string> lista, std::deque<int> kolejka){

    std::map<int, std::string> mapa;

    lista.sort();
    lista.erase(std::unique(lista.begin(),lista.end()),lista.end());

    std::sort(kolejka.begin(),kolejka.end());
    kolejka.erase(std::unique(kolejka.begin(),kolejka.end()),kolejka.end());

    std::transform(lista.begin(),lista.end(),kolejka.begin(),std::inserter(mapa,mapa.end()),
    [&](auto a, auto b)
    {   
      return std::pair<int,std::string>(b,a);
      
    });

    return mapa;
}

template<typename T>
void erase(std::vector<T> &vec,const T& value){
    vec.erase(std::remove(vec.begin(),vec.end(),value),vec.end());
}

template<typename T>
void unique(std::vector<T> &vec){
    vec.erase(std::unique(vec.begin(),vec.end()), vec.end());
}

template<typename T>
void set_unique(std::vector<T> &vec){
    std::sort(vec.begin(),vec.end());
    vec.erase(std::unique(vec.begin(),vec.end()), vec.end());
}

int main(){
    // #1
    std::vector<std::pair<int, std::string>> v {
    {0, "Zero"}, {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"}};

    // #2
    std::vector<int> v2;
    std::transform(v.begin(),v.end(),std::back_insert_iterator(v2),[](const auto& a){return a.first;});
    printVector(v2);

    // #3
    std::vector<std::string> v3;
    std::transform(v.begin(),v.end(),std::back_insert_iterator(v3),[](const auto& a){return a.second + ":" + std::to_string(a.first);});
    printVector(v3);

    // #4
    std::vector<char> v4(('z'-95)/2); 
    std::generate(v4.begin(),v4.end(),[i{static_cast<char>(95)}]() mutable {return i+=2;}); 
    printVector(v4);
    //std::cout<<static_cast<int>('a')<<" "<<static_cast<int>('z');

    std::vector<int> vg; 
    std::generate_n(std::back_insert_iterator(vg),5,[i{5}]()mutable {return i++;});
    printVector(vg);

    std::cout<<"\n------------------------------------------------------------\n\n";

    // #5
    std::vector<int> v5 = {8, 2, 5, 3, 4, 4, 2, 7, 6, 6, 1, 8, 9};
    printVector(v5);

    // #6
    std::sort(v5.begin(),v5.end());
    printVector(v5);
    v5.erase(std::unique(v5.begin(),v5.end()),v5.end());
    
    // #7
    std::copy(v5.begin(),v5.end(),std::ostream_iterator<int>(std::cout, " "));
    std::cout<<"\n";
    
    // #8
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(v5.begin(), v5.end(), g);
    printVector(v5);
    std::cout<<"\n------------------------------------------------------------\n\n";
    
    // #10
    std::string a = "KAJ12312a.k";
    testInsensitivePalindrom(a);
    a = "Papir12 S";
    testInsensitivePalindrom(a);

    // #11

    std::list<std::string> lis {"Ala", "Kot", "Ma", "Rysia", "Ala",
        "Sierotka", "Kot", "Ma", "Ala"};
    std::deque<int> kolejka{
        1, 2, 3, 4, 5, 3, 1, 2, 3, 4,
        5, 2, 3, 1, 1, 2, 3, 2, 1, 4};

    std::map<int, std::string> mapa = converter(lis,kolejka);
    
    std::for_each(mapa.begin(),mapa.end(),[](auto a){std::cout<<a.first<<" "<<a.second<<"   ";});

    // #12 -> 105 STL algorithms in Less than an Hour

    std::vector<int> vectors{1,2,99,99,99,-1,-2,99,0,1};
    std::vector<int> vectors2{vectors};
    std::vector<int> vectors3{vectors};

    std::cout<<std::endl;
    erase(vectors,99);
    printVector(vectors);
    
    unique(vectors2);
    printVector(vectors2);

    set_unique(vectors3);
    printVector(vectors3);

    return 0;
}