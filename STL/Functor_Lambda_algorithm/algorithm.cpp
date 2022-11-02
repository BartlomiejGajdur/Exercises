#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <list>
#include <numeric>


bool isPalindrome(const std::string& text){
    return std::equal(text.begin(),text.begin() + text.size()/2, text.rbegin(), text.rbegin()+text.size()/2);
}


void test(const std::string& wordToCheck){
    std::cout<<"\""<<wordToCheck<<"\" "
             <<(isPalindrome(wordToCheck)?"is":"is not")
             <<" a Palindorme\n";
}


void printVector(std::vector<int> vec){
    for(const auto& v :vec){
        std::cout<<v<<" ";
    }
    std::cout<<std::endl;
}

void printList(std::list<int> lista){
    for(const auto& v :lista){
        std::cout<<v<<" ";
    }
    std::cout<<std::endl;
}


int main(){

    std::vector<int> vecc {1,2,3,4,5,1,1,1,2,3,4};
    std::cout<<std::count(vecc.begin(),vecc.end(),1)<<std::endl;
    std::cout<<std::count_if(vecc.begin(),vecc.end(),[](const auto& a){ return a%2==1;});
    std::cout<<std::endl;

    test("kajak");
    test("slowo");



    std::string a = "abcde";
    std::string b = "nabcdefkyrkgfjm";

    bool wynik = std::equal(a.begin(),a.end(),
                            b.begin()+1);

    if(wynik){
        std::cout<<"prawda\n";
    }else{
        std::cout<<"false\n";
    }
    std::cout<<"\n------------------------------------------------------------------------------\n";

    std::vector<int> vector(8);

    std::generate(vector.begin(),vector.end(),[i = -1]() mutable 
                                              { return i+=2; });
    printVector(vector);

    std::vector<int> vector2{vector};
    std::transform(vector.rbegin(),vector.rend(),vector2.begin(),[](auto wartosc){return wartosc;});
    printVector(vector2);

    std::list<int> lista(8);

    std::copy(vector.begin(),vector.end(),lista.begin());
    printList(lista);

    std::generate(vector2.begin(),vector2.end(),[i = -2]() mutable 
                                              { return i+=2; });
    printVector(vector2);

    std::vector<int> vector3;

    std::transform(vector.begin(),vector.end(),vector2.begin(),vector2.begin(),[&vector3](int a, int b){ vector3.push_back(b);
                                                                                                         vector3.push_back(a);
                                                                                                         return 0;});
    printVector(vector3);
    std::cout<<"\n------------------------------------------------------------------------------\n";
    auto it = std::minmax_element(vector3.begin(),vector3.end());

    std::cout<<*it.first<<" "<<*it.second;
    std::cout<<"\n------------------------------------------------------------------------------\n";

    std::list<int> lis(10);
    std::vector<int> vec(6);

    std::generate(lis.begin(),lis.end(),[i{1}]() mutable {return i++;});
    std::generate(vec.begin(),vec.end(),[i{5}]() mutable {return i++;});
    printVector(vec);
    printList(lis);
    if(std::equal(vec.begin(),vec.end(),std::next(lis.begin(),4)))
        std::cout<<"Sa rowne\n";

    std::reverse(vec.begin(),vec.end());
    std::reverse(lis.begin(),lis.end());
    printVector(vec);
    printList(lis);
    auto itt=std::mismatch(vec.begin(),vec.end(),lis.begin());

    lis.erase(itt.second, lis.end());
    printList(lis);

    if(std::equal(vec.begin(),vec.end(),lis.begin(),lis.end()))
        std::cout<<"No i rowne";





    
    return 0;
}