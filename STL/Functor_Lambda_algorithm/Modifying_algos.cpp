#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>
#include <random>
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
*/
template<typename T>
    void printVector(const std::vector<T>& v){
        std::for_each(v.begin(),v.end(),[](const auto a){std::cout<<a<<" ";});
        std::cout<<"\n";
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
    return 0;
}