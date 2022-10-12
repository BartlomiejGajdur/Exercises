#include "Fruit.hpp"

class DryFruit : public Fruit{
    public:
    DryFruit(const std::string& name, size_t amount, double basePrice);
    virtual ~DryFruit() = default;
    DryFruit() = default;
    std::string getName() const override {return name_;}
    double getPrice()     const override;
    DryFruit& operator--() override;
    void print(std::ostream& os) const override;
    void nextDay() override;
    friend std::ostream& operator<<(std::ostream &os, const DryFruit& fruit) {   
        fruit.print(os);
        return os;
    }

    private:

};


   