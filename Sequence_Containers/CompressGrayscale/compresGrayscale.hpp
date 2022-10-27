#include <random>
#include <fstream>
#include <array>
#include <vector>   

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
//Problem jest kiedy w kolejnych wierszach jest ta sama awartosc
std::vector<std::pair<int,int>> compressGrayscale(std::array<std::array<int, width>, height> &bitmapa){

    std::vector<std::pair<int,int>> compressedBitmap{};
    std::pair<int,int> para{-1,1};
    
    // for(auto& outer : bitmapa)
    // {
    //     for(auto& inner: outer)
    //     {
    //         para.first = inner; 
            
    //         if(inner == *(&inner + 1)){
    //             ++para.second;
    //             if()
    //         }else{
    //             compressedBitmap.push_back(para);
    //             para.second = 1;
    //         }
     
    //     }
    //     compressedBitmap.push_back(para);
    //     para = {-1,1};
    // }

  

    for(size_t i = 0 ; i <height ; i++){
        for(size_t j = 0 ;j<width ; j++){


             para.first = bitmapa[i][j];

             if(bitmapa[i][j] == bitmapa[i][j+1]){
                ++para.second;
                if(j== width-1 && bitmapa[i][width-1] == bitmapa[i+1][0]){
                    --para.second;
                }
            }else{
                compressedBitmap.push_back(para);
                para.second = 1;   
            }
        }
         
         compressedBitmap.push_back(para);  
         para = {-1,1}; 
    }


    return compressedBitmap;
}

void printVectorOfPair(const std::vector<std::pair<int,int>>& vec){
    for(const auto &el: vec){
        std::cout<<"{"<<el.first<<", "<<el.second<<"} ";
    }
}