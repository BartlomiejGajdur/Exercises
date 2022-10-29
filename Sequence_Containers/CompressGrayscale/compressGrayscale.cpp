#include <iostream>
#include "compressGrayscale.hpp"


int main(){

   std::fstream plik = openFile("../obrazek.pgm");
   generateHeader(plik);

   std::array<std::array<int, width>, height> bitmap = generateImageData(plik);
   std::vector<std::pair<int,int>> compressedGrayscale = compressGrayscale(bitmap);

   printVectorOfPair(compressedGrayscale);

   howMuchCompressed(bitmap,compressedGrayscale);

   std::cout<<"\n\n\n";
   std::array<std::array<int, width>, height> bitmap2 = decompressGrayscale(compressedGrayscale);
   printArray(bitmap2);
   
   isDecompressedCorrect(bitmap2,bitmap);

 

   return 0;
}