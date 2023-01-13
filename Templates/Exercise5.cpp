#include <iostream>

//Specjalization for single type
template <int num>
struct IsSmallPrime : std::false_type{};

template<>
struct IsSmallPrime<2> : std::true_type{};

template<>
struct IsSmallPrime<3> : std::true_type{};

template<>
struct IsSmallPrime<5> : std::true_type{};

template<>
struct IsSmallPrime<7> : std::true_type{};

//Specjalization for multi type
template<typename T1, typename T2>
struct X{};

template<typename T2>
struct X <int,T2> {};

template<>
struct X <int,double> {};

template<typename T1>
struct X <T1,int> {};

int main(){

        std::cout<<"0: "<<std::boolalpha<<IsSmallPrime<0>::value<<"\n";
        std::cout<<"1: "<<std::boolalpha<<IsSmallPrime<1>::value<<"\n";
        std::cout<<"2: "<<std::boolalpha<<IsSmallPrime<2>::value<<"\n";
        std::cout<<"3: "<<std::boolalpha<<IsSmallPrime<3>::value<<"\n";
        std::cout<<"4: "<<std::boolalpha<<IsSmallPrime<4>::value<<"\n";
        std::cout<<"5: "<<std::boolalpha<<IsSmallPrime<5>::value<<"\n";
        std::cout<<"6: "<<std::boolalpha<<IsSmallPrime<6>::value<<"\n";
        std::cout<<"7: "<<std::boolalpha<<IsSmallPrime<7>::value<<"\n";
        std::cout<<"8: "<<std::boolalpha<<IsSmallPrime<8>::value<<"\n";
        std::cout<<"9: "<<std::boolalpha<<IsSmallPrime<9>::value<<"\n";

    return 0;
}