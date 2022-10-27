//Utworzenie randomowego pliku z randomowych danych 


#include <iostream>

#include "compresGrayscale.hpp"



int main(){

   std::fstream plik = openFile("obrazek.pgm");
   generateHeader(plik);

   std::array<std::array<int, width>, height> bitmap = generateImageData(plik);

   

   return 0;
}