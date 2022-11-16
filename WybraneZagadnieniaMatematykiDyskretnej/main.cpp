#include <algorithm>
#include <iostream>
#include <iomanip>
#include "Database.hpp"
#include <vector>

void printTabelaDATABASE(const std::vector<Database>& database);
void printTabelaIDUCZNIA(const std::vector<IDucznia>& uczniowie);
void printTabelaIDPRZEDMIOTU(const std::vector<IDprzedmiotu>& przedmioty);
void printTabelaIDNAUCZYCIELA(const std::vector<IDnauczyciela>& nauczyciele);

//Wypisz nazwiska uczniów grupy 11i / nauczycieli / nazwy przedmiotow | z których są oceny 2 lub 5 u nauczycieli Suchenia lub Bak. grupa 11i
void Exercise1(const std::vector<Database>& database){
    std::cout<<"\n\n\n---------EXERCISE1---------\n";
    std::vector<Database> FinalRecords;
    auto lambda = [&](const Database& record)
                    { 
                        if((record.getOcena() == 2 || record.getOcena() == 5) 
                            &&(record.getIDnauczyciela().getNazwiskoNauczyciela() == "Suchenia" || record.getIDnauczyciela().getNazwiskoNauczyciela() == "Bak") 
                            && record.getIDucznia().getGrupa()=="11i")
                            FinalRecords.push_back(record);         
                    };
    
    std::for_each(database.begin(),database.end(),lambda);

    //FinalRecords.erase(std::unique(FinalRecords.begin(),FinalRecords.end()),FinalRecords.end());
    std::for_each(FinalRecords.begin(),FinalRecords.end(),[](const Database& recordy)
                { 
                    std::cout<<recordy.getIDucznia().getNazwiskoUcznia()<<" | "
                    <<recordy.getIDnauczyciela().getNazwiskoNauczyciela()<<" | "
                    <<recordy.getIDprzedmiotu().getNazwaPrzedmiotu()<<" | ";
                });
}

//Wypisz przedmioty, z których w dniach 17.01.19 lub 25.01.19 byly wpisane oceny powyżej 3.5
void Exercise2(const std::vector<Database>& database){
    std::cout<<"\n\n\n---------EXERCISE2---------\n";
    std::vector<IDprzedmiotu> przedmioty;
    auto lambda = [&](const Database& record)
                    { 
                        if((record.getData() == "17.01.19" || record.getData() == "25.01.19") && record.getOcena()>=3.5)
                            przedmioty.push_back(record.getIDprzedmiotu());         
                    };
    
    std::for_each(database.begin(),database.end(),lambda);

    przedmioty.erase(std::unique(przedmioty.begin(),przedmioty.end()),przedmioty.end());
    std::for_each(przedmioty.begin(),przedmioty.end(),[](const IDprzedmiotu& przedmiot){ std::cout<<przedmiot.getNazwaPrzedmiotu()<<"\n";});
}

//Wypisz Id / nazwisko ucznia i nauczyciela, który jeden wpisał drugiemu ocene powyzej 3.5 z przedmiotow ASD lub UML w dniu 17.01.19
void Exercise3(const std::vector<Database>& database){
    std::cout<<"\n\n\n---------EXERCISE3---------\n";
    std::vector<Database> FinalRecords;
    auto lambda = [&](const Database& record)
                    { 
                        if((record.getIDprzedmiotu().getNazwaPrzedmiotu() == "ASD" || record.getIDprzedmiotu().getNazwaPrzedmiotu() == "UML") 
                            && record.getData()=="17.01.19" && record.getOcena()>=3.5)
                            FinalRecords.push_back(record);       
                    };
    
    std::for_each(database.begin(),database.end(),lambda);

    std::for_each(FinalRecords.begin(),FinalRecords.end(),[](const Database& record){   std::cout<<record.getIDucznia().getIDucznia()<<" "<<
                                                                                        record.getIDucznia().getNazwiskoUcznia()<<" | "<< 
                                                                                        record.getIDnauczyciela().getIDnauczyciela()<<" "<<
                                                                                        record.getIDnauczyciela().getNazwiskoNauczyciela()<<"\n";});
}


//Wypisz Id i nazwisko nauczycieli, ktorzy wpisali w dniu 17.01.19 lub 25.01.19 ocene od 3.5 do 4.5
void Exercise4(const std::vector<Database>& database){
    std::cout<<"\n\n\n---------EXERCISE4---------\n";
    std::vector<IDnauczyciela> nauczyciele;
    auto lambda = [&](const Database& record)
                    { 
                        if((record.getData() == "17.01.19" || record.getData() == "25.01.19") && record.getOcena()>=3.5 && record.getOcena()<=4.5 )
                            nauczyciele.push_back(record.getIDnauczyciela());         
                    };
    
    std::for_each(database.begin(),database.end(),lambda);

    nauczyciele.erase(std::unique(nauczyciele.begin(),nauczyciele.end()),nauczyciele.end());
    std::for_each(nauczyciele.begin(),nauczyciele.end(),[](const IDnauczyciela& przedmiot){ std::cout<<przedmiot;});
}

int main(){

    std::vector<IDprzedmiotu> przedmioty {{"0101","UML"},
                                          {"0102","Techniki internetowe"},
                                          {"0103","ASD"},
                                          {"0104","KWD"}};
    
    std::vector<IDnauczyciela> nauczyciele{{"0061","Czarnecki"},
                                           {"0062","Bak"},
                                           {"0063","Suchenia"},
                                           {"0064","Kielkowicz"}};

    std::vector<IDucznia> uczniowie{{"0011","Worwa","Andrzej",2001,"11i"},
                                    {"0012","Pepera","Marzena",2002,"11i"},
                                    {"0013","Zamojski","Piotr",2003,"12i"},
                                    {"0014","Kielkowicz","Joanna",2002,"13i"},
                                    {"0015","Bjaly","Ewa",2001,"13i"},
                                    {"0016","Zielonka","Dariusz",2003,"11i"},};


    std::vector<Database> database{{uczniowie[0],przedmioty[1],nauczyciele[0],"13.01.19",4},
                                   {uczniowie[0],przedmioty[2],nauczyciele[1],"17.01.19",5},
                                   {uczniowie[1],przedmioty[1],nauczyciele[0],"13.01.19",5},
                                   {uczniowie[1],przedmioty[2],nauczyciele[1],"17.01.19",4},
                                   {uczniowie[2],przedmioty[3],nauczyciele[2],"25.01.19",3.5},
                                   {uczniowie[2],przedmioty[2],nauczyciele[1],"18.01.19",4.5},
                                   {uczniowie[0],przedmioty[3],nauczyciele[2],"25.01.19",3},
                                   {uczniowie[1],przedmioty[3],nauczyciele[2],"28.01.19",5},};
                                   
    printTabelaDATABASE(database);
    printTabelaIDNAUCZYCIELA(nauczyciele);
    printTabelaIDPRZEDMIOTU(przedmioty);
    printTabelaIDUCZNIA(uczniowie);

    Exercise1(database);
    Exercise2(database);
    Exercise3(database);
    Exercise4(database);
    
    
   
    return 0;
}



void printTabelaDATABASE(const std::vector<Database>& database)
{

    std::cout<<"\n-----------------------------------------------------------------------------------------\n";
    std::cout<<std::setw(20)<<std::left;
    std::cout<<"|ID ucznia|";
    std::cout<<std::setw(20)<<std::left;
    std::cout<<"|ID przedmiotu|";
    std::cout<<std::setw(20)<<std::left;
    std::cout<<"|ID nauczyciela|";
    std::cout<<std::setw(20)<<std::left;
    std::cout<<"|Data|";
    std::cout<<std::setw(20)<<std::left;
    std::cout<<"|Ocena|";
    std::cout<<"\n-----------------------------------------------------------------------------------------\n";
    std::for_each(database.begin(),database.end(),[](const Database& record){std::cout<<record;});
}

void printTabelaIDUCZNIA(const std::vector<IDucznia>& uczniowie)
{

    std::cout<<"\n-----------------------------------------------------------------------------------------\n";
    std::cout<<std::setw(20)<<std::left;
    std::cout<<"|ID ucznia|";
    std::cout<<std::setw(20)<<std::left;
    std::cout<<"|Nazwisko ucznia|";
    std::cout<<std::setw(20)<<std::left;
    std::cout<<"|Imie Ucznia|";
    std::cout<<std::setw(20)<<std::left;
    std::cout<<"|Rok|";
    std::cout<<std::setw(20)<<std::left;
    std::cout<<"|Grupa|";
    std::cout<<"\n-----------------------------------------------------------------------------------------\n";
    std::for_each(uczniowie.begin(),uczniowie.end(),[](const IDucznia& record){std::cout<<record;});
}

void printTabelaIDPRZEDMIOTU(const std::vector<IDprzedmiotu>& przedmioty)
{
    std::cout<<"\n-----------------------------------------------------------------------------------------\n";
    std::cout<<std::setw(20)<<std::left;
    std::cout<<"|ID przedmiotu|";
    std::cout<<std::setw(20)<<std::left;
    std::cout<<"|Nazwa Przedmiotu|";
    std::cout<<"\n-----------------------------------------------------------------------------------------\n";
    std::for_each(przedmioty.begin(),przedmioty.end(),[](const IDprzedmiotu& record){std::cout<<record;});
}

void printTabelaIDNAUCZYCIELA(const std::vector<IDnauczyciela>& nauczyciele)
{
    std::cout<<"\n-----------------------------------------------------------------------------------------\n";
    std::cout<<std::setw(20)<<std::left;
    std::cout<<"|ID nauczyciela|";
    std::cout<<std::setw(20)<<std::left;
    std::cout<<"|Nazwisko nauczyciela|";
    std::cout<<"\n-----------------------------------------------------------------------------------------\n";
    std::for_each(nauczyciele.begin(),nauczyciele.end(),[](const IDnauczyciela& record){std::cout<<record;});
}