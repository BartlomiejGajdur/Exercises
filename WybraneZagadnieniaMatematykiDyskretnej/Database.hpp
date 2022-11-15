#include <string>
#include <iomanip>
#include <ostream>

class IDnauczyciela{
    private:
        std::string IDnauczyciela_, NazwiskoNauczyciela_;
    
    public:
        IDnauczyciela(): IDnauczyciela_("0000"), NazwiskoNauczyciela_("NONE") {};
        IDnauczyciela(std::string IDnauczyciela, std::string NazwiskoNauczyciela) : 
            IDnauczyciela_(IDnauczyciela), NazwiskoNauczyciela_(NazwiskoNauczyciela){};

        std::string getIDnauczyciela()      const {return IDnauczyciela_;}
        std::string getNazwiskoNauczyciela()const {return NazwiskoNauczyciela_;}

        friend std::ostream& operator<<(std::ostream& os, const IDnauczyciela& IDnauczyciela){
           os<<std::setw(20)<<std::left;
           os<< IDnauczyciela.getIDnauczyciela();
           os<<std::setw(20)<<std::left;
           os<< IDnauczyciela.getNazwiskoNauczyciela()<<"\n";
           return os;}

        bool operator==(const IDnauczyciela& other){
            return this->getNazwiskoNauczyciela() == other.getNazwiskoNauczyciela();
        }
};

class IDprzedmiotu{
    private:
        std::string IDprzedmiotu_, NazwaPrzedmiotu_;
    
    public:
         IDprzedmiotu(): IDprzedmiotu_("0000"), NazwaPrzedmiotu_("NONE") {};
         IDprzedmiotu(std::string IDprzedmiotu, std::string NazwaPrzedmiotu) : 
            IDprzedmiotu_(IDprzedmiotu), NazwaPrzedmiotu_(NazwaPrzedmiotu){};

        std::string getIDprzedmiotu()      const {return IDprzedmiotu_;}
        std::string getNazwaPrzedmiotu()   const {return NazwaPrzedmiotu_;}

        friend std::ostream& operator<<(std::ostream& os, const IDprzedmiotu& IDprzedmiotu){
           os<<std::setw(20)<<std::left;
           os<< IDprzedmiotu.getIDprzedmiotu();
           os<<std::setw(20)<<std::left;
           os<< IDprzedmiotu.getNazwaPrzedmiotu()<<"\n";
           return os;}

        bool operator==(const IDprzedmiotu& other){
            return this->getNazwaPrzedmiotu() == other.getNazwaPrzedmiotu();
        }
        
};

class IDucznia{
    private:
        std::string IDucznia_, NazwiskoUcznia_, ImieUcznia_, Grupa_;
        int Rok_;
    
    public:
         IDucznia(): IDucznia_("0000"), NazwiskoUcznia_("NONE"),ImieUcznia_("NONE"), Rok_(0),Grupa_("0X") {};
         IDucznia(std::string IDucznia, std::string NazwiskoUcznia,std::string ImieUcznia,int Rok, std::string Grupa) : 
            IDucznia_(IDucznia), NazwiskoUcznia_(NazwiskoUcznia), ImieUcznia_(ImieUcznia),Rok_(Rok), Grupa_(Grupa) {};

        std::string getIDucznia()       const {return IDucznia_;}
        std::string getNazwiskoUcznia() const {return NazwiskoUcznia_;}
        std::string getImieUcznia()     const {return ImieUcznia_;}
        int getRok()                    const {return Rok_;}
        std::string getGrupa()          const {return Grupa_;} 

        friend std::ostream& operator<<(std::ostream& os, const IDucznia& IDucznia){
           os<<std::setw(20)<<std::left;
           os<< IDucznia.getIDucznia();
           os<<std::setw(20)<<std::left;
           os<< IDucznia.getNazwiskoUcznia();
           os<<std::setw(20)<<std::left;
           os<< IDucznia.getImieUcznia();
           os<<std::setw(20)<<std::left;
           os<< IDucznia.getRok();
           os<<std::setw(20)<<std::left;
           os<< IDucznia.getGrupa()<<"\n";     
           return os;}   
};

class Database : public IDnauczyciela,
                 public IDprzedmiotu,
                 public IDucznia
{
private:
    IDnauczyciela IDnauczyciela_;
    IDprzedmiotu IDprzedmiotu_;
    IDucznia IDucznia_;
    std::string Data_;
    double Ocena_;
public:
    Database(IDucznia IDucznia, IDprzedmiotu IDprzedmiotu, IDnauczyciela IDnauczyciela ,std::string Data, double Ocena) : 
            IDucznia_ (IDucznia), IDprzedmiotu_(IDprzedmiotu), IDnauczyciela_(IDnauczyciela), Data_(Data), Ocena_(Ocena) {};
    
        IDnauczyciela getIDnauczyciela()const {return IDnauczyciela_;}
        IDprzedmiotu getIDprzedmiotu()  const {return IDprzedmiotu_;}
        IDucznia getIDucznia()          const {return IDucznia_;}
        double getOcena()               const {return Ocena_;}
        std::string getData()           const {return Data_;} 

    friend std::ostream& operator<<(std::ostream& os, const Database& database){
           os<<std::setw(20)<<std::left;
           os<< database.IDucznia_.getIDucznia();
           os<<std::setw(20)<<std::left;
           os<< database.IDprzedmiotu_.getIDprzedmiotu();
           os<<std::setw(20)<<std::left;
           os<< database.IDnauczyciela_.getIDnauczyciela();
           os<<std::setw(20)<<std::left;
           os<< database.Data_;
           os<<std::setw(20)<<std::left;
           os<< database.Ocena_<<"\n";
           return os;}
};


