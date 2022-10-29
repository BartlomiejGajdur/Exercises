#include <random>
#include <fstream>
#include <array>
#include <vector>   
#include <windows.h>

constexpr int width = 10;
constexpr int height = 3;
constexpr int maxValue = 255;

// Generating random number from two given
int generateRandomNumber(const int& first, const int& second){

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> Random(first, second);

    return Random(gen);
}

//Opens the file with the given name and checks that the file has been opened correctly
std::fstream openFile(const std::string& fileName)
{

    std::fstream plik;
    plik.open( fileName, std::ios::in | std::ios::out | std::ios::trunc);
    if( plik.good() == true )
    {
           std::cout << "Uzyskano dostep do pliku!" << std::endl;
    } else std::cout << "Dostep do pliku zostal zabroniony!" << std::endl;

    return plik;
}

//Generates file from previous declarated width and height
void generateHeader(std::fstream& objectFile){
    objectFile<<"P2\n";
    objectFile<<width<<" "<<height<<"\n";
    objectFile<<maxValue<<"\n"; 

    std::cout<<"P2\n";
    std::cout<<width<<" "<<height<<"\n";
    std::cout<<maxValue<<"\n"; 
}

//Generates random array specifying the distribution of shades of gray in a 2D image
std::array<std::array<int, width>, height> generateImageData(std::fstream& objectFile){
    std::array<int, 5> values = {0, 32, 64, 128, 255};
    std::array<std::array<int, width>, height> bitmap_;
    

    for(size_t i = 0 ; i <height ; i++){
        for(size_t j = 0 ;j<width ; j++){

            short randomNumber = generateRandomNumber(0,4);
            objectFile<<values[randomNumber]<<" ";
            bitmap_[i][j] = values[randomNumber];
            std::cout << bitmap_[i][j] <<" ";
        }
        objectFile<<"\n";
        std::cout<<"\n";
    }

   return bitmap_;
}

//Function shall return std::vector<std::pait<int,int>> of compressed Grayscale
std::vector<std::pair<int,int>> compressGrayscale(std::array<std::array<int, width>, height> &bitmapa){

    std::vector<std::pair<int,int>> compressedBitmap{};
    std::pair<int,int> para{-1,1};

  
    for(size_t i = 0 ; i <height ; i++){
        for(size_t j = 0 ;j<width ; j++){


             para.first = bitmapa[i][j];

             if(bitmapa[i][j] == bitmapa[i][j+1]){
                ++para.second;
                if(j == width-1 && bitmapa[i][width-1] == bitmapa[i+1][0]){
                    --para.second;
                    compressedBitmap.push_back(para);
                }
            }else{
                compressedBitmap.push_back(para);
                para.second = 1;   
            }
        }
         para = {-1,1}; 
    }


    return compressedBitmap;
}
//Function shall return std::array<std::array<int, width>, height> of decompressed Grayscale
 std::array<std::array<int, width>, height> decompressGrayscale(std::vector<std::pair<int,int>> &compressedVec){

    int licznik{0};
    std::array<std::array<int, width>, height> bitmap;

        for (auto v : compressedVec){
            int current = v.second;
            licznik+=v.second;

                for(int i = licznik - current;i<licznik; i++)
                {   
                        bitmap[0][i] = v.first;    
                }
            }

        return bitmap;
 }


//Function shall print vector of pairs
void printVectorOfPair(const std::vector<std::pair<int,int>>& vec){
    std::cout<<std::endl;
    for(const auto &el: vec){
        std::cout<<"{"<<el.first<<", "<<el.second<<"} ";
    }
    std::cout<<std::endl;
}

//Function shall print array
void printArray(const  std::array<std::array<int, width>, height>& array){
    std::cout<<std::endl;
    for(const auto &outer: array){
        for(const auto & inner : outer){
            std::cout<<inner<<" ";
        }
        std::cout<<std::endl;
    }
}

//Function shall returns number if the memory value has changed
void howMuchCompressed(const std::array<std::array<int, width>, height> &bitmapa ,const std::vector<std::pair<int,int>>& vec){

    HANDLE hOut;
    hOut = GetStdHandle( STD_OUTPUT_HANDLE );
    
    std::cout<<"\nSizeof Bitmap [Bytes]: "<<sizeof(bitmapa)<<"\n";
    std::cout<<"Sizeof Compressed Bitmap [Bytes]: "<<vec.size()*8<<"\n";
    if(sizeof(bitmapa)>vec.size()*8)
    {
        SetConsoleTextAttribute( hOut, FOREGROUND_GREEN );
        std::cout<<"Gained "<<100-(double((vec.size()*8*100))/sizeof(bitmapa))<<"% memory! :) [Bytes]\n";
        SetConsoleTextAttribute( hOut, 15 );
    }else if (sizeof(bitmapa)<vec.size()*8){
        SetConsoleTextAttribute( hOut, FOREGROUND_RED );
        std::cout<<"Your compressed file is not even lighter "<<100-(double((vec.size()*8*100))/sizeof(bitmapa))<<"% memory! ;/ [Bytes]\n";
        std::cout<<"This file compression method does workonly with real data. Random generated data is hard to compress.";
        SetConsoleTextAttribute( hOut, 15 );
    }else{
        std::cout<<"Gained "<<100-((vec.size()*8*100)/sizeof(bitmapa))<<"% memory! [Bytes]\n";
    }

}

//Function shall check if decompressed method works fine
void isDecompressedCorrect (const std::array<std::array<int, width>, height>& first , const std::array<std::array<int, width>, height>& second)
{
if(first == second){
      SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), FOREGROUND_GREEN );
      std::cout<<"Decompression completed and is correct!";
      SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 15 );
   }else{
        SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), FOREGROUND_RED );
      std::cout<<"Opps, Decompression went wrong! ;/";
      SetConsoleTextAttribute( GetStdHandle( STD_OUTPUT_HANDLE ), 15 );
   }
}
