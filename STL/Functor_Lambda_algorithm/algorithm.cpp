#include <algorithm>
#include <vector>
#include <iostream>
#include <string>

//Algorytm przyjmuje zakres slowa czyli dla "KajaK" bedzie to od BEGIN do 

bool isPalindrome(const std::string& text){
    return std::equal(text.begin(),text.begin() + text.size()/2, text.rbegin(), text.rbegin()+text.size()/2);
}


void test(const std::string& wordToCheck){
    std::cout<<"\""<<wordToCheck<<"\" "
             <<(isPalindrome(wordToCheck)?"is":"is not")
             <<" a Palindorme\n";
}


int main(){

    std::vector<int> vec {1,2,3,4,5,1,1,1,2,3,4};
    std::cout<<std::count(vec.begin(),vec.end(),1)<<std::endl;
    std::cout<<std::count_if(vec.begin(),vec.end(),[](const auto& a){ return a%2==1;});
    std::cout<<std::endl;

    test("kajak");
    test("slowo");



    std::string a = "abcde";
    std::string b = "nabcdefkyrkgfjm";

    bool wynik = std::equal(a.begin(),a.end(),
                            b.begin()+1);

    if(wynik){
        std::cout<<"prawda";
    }else{
        std::cout<<"false";
    }

    return 0;
}