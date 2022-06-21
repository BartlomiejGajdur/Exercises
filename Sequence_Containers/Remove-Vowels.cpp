#include <iostream>
#include <vector>
#include <string>
#include<algorithm>
std::vector<std::string> removeVowels(std::vector<std::string>&);
void printVector(const std::vector<std::string>&);

int main()
{
    std::vector<std::string> vector1 {"abcde", "aabbbccabc", "qwerty","a","e"};
    printVector(vector1);

    removeVowels(vector1);
    printVector(vector1);


    return 0;
}

std::vector<std::string> removeVowels(std::vector<std::string>& vec)
{
    std::vector<char> Vovels {'a','e','i','o','u','y','A','E','I','O','U','Y'};
  
       for (auto& str : vec){
        for (auto sign : Vovels){
            str.erase(std::remove(str.begin(), str.end(), sign), str.end());
        }
    }
    return vec;
}

void printVector(const std::vector<std::string>& vec)
{
    for(auto& ele : vec)
    {
        std::cout<<ele<<" ";
    }
    std::cout<<std::endl;
}