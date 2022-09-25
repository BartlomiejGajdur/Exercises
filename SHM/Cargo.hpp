#pragma once
#include <string>
#include <ostream>

class Cargo{
    public:
    Cargo(const std::string& name,
                     size_t amount, 
                     double basePrice):  
                                        name_(name),
                                        amount_(amount),
                                        basePrice_(basePrice) {}
    Cargo() = default; 
    virtual ~Cargo() = default;

//GETTERS

    virtual std::string getName() const = 0;
    virtual size_t getAmount()    const = 0;
    virtual double getBasePrice() const = 0;
    virtual double getPrice()     const = 0;
//SETTERS
    

//OPERATORS
    // Cargo& operator+=(const size_t amount);                                                      
    // Cargo& operator-=(const size_t amount);
    //virtual bool operator==(const Cargo& other);
    virtual void print(std::ostream& os) const = 0;

   friend std::ostream& operator<<(std::ostream &os, const Cargo& cargo);
   
    protected:
    std::string name_;
    size_t amount_;
    double basePrice_;

};

std::ostream& operator<<(std::ostream &os, const Cargo& cargo)
    {   
        cargo.print(os);
        return os;
    }