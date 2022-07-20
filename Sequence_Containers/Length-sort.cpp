#include <iostream>
#include<forward_list>
#include<deque>
#include<string>

std::deque<std::string> lengthSort(std::forward_list<std::string>&);
void print(const std::forward_list<std::string>&);
void print(const std::deque<std::string>&);

int main(){

    std::forward_list<std::string> list{"Three", "One", "Four", "Two"};
    std::deque<std::string> deq;

    //list.sort();
    print(list);
    deq = lengthSort(list);
    print(deq);



    return 0;
}

std::deque<std::string> lengthSort(std::forward_list<std::string> &list0)
{
    std::deque<std::string> deq;

    for(auto &ele : list0)
    {
        
    }
    return deq;
}

void print(const std::forward_list<std::string>& l)
{
    for(auto& ele : l )
    {
        std::cout<<ele<<" ";
    }
    std::cout<<std::endl;
}
void print(const std::deque<std::string>& l)
{
    for(auto& ele : l )
    {
        std::cout<<ele<<" ";
    }
    std::cout<<std::endl;
}