#include <algorithm>
#include <iostream>
#include <vector>

/*
1. Utwórz poniższy wektor:

std::vector<std::pair<int, std::string>> v {
    {0, "Zero"}, {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"}
};
2. Utwórz wektor intów v2 i wypełnij go wszystkimi intami (pierwszymi elementami pary) z wektora v

3. Utwórz wektor stringów v3 i wypełnij go konkatenacją string + dwukropek + int ze wszystkich par z wektora v

4. Utwórz wektor charów v4 i wypełnij go co drugą literą alfabetu
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

    std::vector<int> v5; 
    std::generate_n(std::back_insert_iterator(v5),5,[i{5}]()mutable {return i++;});
    printVector(v5);
    return 0;
}