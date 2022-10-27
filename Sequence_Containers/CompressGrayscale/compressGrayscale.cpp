#include <iostream>
#include "compresGrayscale.hpp"


int main(){

   std::fstream plik = openFile("obrazek.pgm");
   generateHeader(plik);

   std::array<std::array<int, width>, height> bitmap = generateImageData(plik);

   std::vector<std::pair<int,int>> compressedGrayscale;

   compressedGrayscale = compressGrayscale(bitmap);
   
   printVectorOfPair(compressedGrayscale);

   std::cout<<"\n\n";

   std::cout<<"Size of bitmap [Bytes]: "<<sizeof(bitmap)<<"\n";
   std::cout<<"Size of compressed bitmap [Bytes]: "<<compressedGrayscale.size()*8;


   std::cout<<"\n\n";
   std::array<std::array<int, 10>, 3> bitmap2 {{{0,0,0,1,1,2,3,0,0,0},{0,0,4,4,4,1,1,1,1,1},{2,2,2,2,2,1,2,2,2,2}}};
   compressedGrayscale = compressGrayscale(bitmap2);
   printVectorOfPair(compressedGrayscale);
   std::cout<<"Size of bitmap [Bytes]: "<<sizeof(bitmap)<<"\n";
   std::cout<<"Size of compressed bitmap [Bytes]: "<<compressedGrayscale.size()*8;
   return 0;
}