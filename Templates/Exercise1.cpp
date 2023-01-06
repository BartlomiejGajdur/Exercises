#include <iostream>
#include <complex>

template <typename RealType, typename ImagType>
auto makeComplex(RealType real, ImagType imag){
    RealType Imag = imag;
    return std::complex<RealType>{real,Imag};
}

int main(){

    std::complex<int> a = makeComplex(4,5);
    std::complex<double> b = makeComplex(3.0 , 5.0);
    std::complex<int> c = makeComplex(4, 5.0);

    return 0;
}