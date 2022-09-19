class Cargo{
    public:
    Cargo(std::string name, size_t amount, double basePrice) :  
                                                              name_(name),
                                                              amount_(amount),
                                                              basePrice_(basePrice) {} 


    Cargo& operator+=(const size_t num)
    {      
        amount_+=num;
        return *this;
    }                                                           

    Cargo& operator-=(const size_t num)
    {
        amount_-=num;
        return *this;
    }   

    private:
    std::string name_;
    size_t amount_;
    double basePrice_;

};