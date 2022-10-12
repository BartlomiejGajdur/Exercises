#pragma once 

#include <random>

#include "Cargo.hpp"
#include "Player.hpp"
#include "Time.hpp"


class Store : public Observer{
    public:
    enum class Response{done = 1, lack_of_money, lack_of_cargo, lack_of_space};

    Store(std::vector<std::shared_ptr<Cargo>> storeCargo): storeCargo_(storeCargo) {}
    Store(){
        GenerateCargoForStore();
    }
    ~Store() {};
    

    Response buy(std::shared_ptr<Cargo> cargo, size_t amount, std::unique_ptr<Player> &player);
    Response sell(std::shared_ptr<Cargo> cargo, size_t amount, std::unique_ptr<Player> &player);

   
    void GenerateFruit();
    void GenerateAlcohol();
    void GenerateItem();
    void GenerateCargoForStore();

    void printCargo() const;

    void nextDay() override;
    
    private:
    std::vector<std::shared_ptr<Cargo>> storeCargo_;
    int generateRandomNumber(const int&, const int&);
    std::shared_ptr<Cargo> findMatchCargo(std::shared_ptr<Cargo>);

};