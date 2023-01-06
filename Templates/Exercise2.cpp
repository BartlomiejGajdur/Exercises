#include <iostream>
#include <vector>
#include <typeinfo>
using namespace std;


template <class T>
void doNothing()
{
	T value;
	std::cout << "Type: " << typeid(value).name() << std::endl;
}

//Class w/o C-tor needs to point the type SomeClass<CHAR>
template <typename T>
class SomeClass {
public:
    T getValue() { return value_; }
private:
    T value_{'c'};
};


//Class with C-tor doesnt need to point the type SomeClass2
template <typename T>
class SomeClass2 {
public:
    SomeClass2(T value) : value_(value) {};
    T getValue() { return value_; }
private:
    T value_;
};

int main() {
	doNothing<std::vector<char>>();

    SomeClass<char> sc;
    std::cout << sc.getValue() << std::endl;

    SomeClass2 sc2{12.2};
    std::cout << sc2.getValue() << std::endl;

	return 0;
}
