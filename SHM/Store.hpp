#pragma once 
#include "Cargo.hpp"
#include "Player.hpp"

#include <random>


class Store{
    public:
    enum class Response{done = 1, lack_of_money, lack_of_cargo, lack_of_space};

    Store(std::vector<std::shared_ptr<Cargo>> storeCargo): storeCargo_(storeCargo) {}
    Store(){
        for(int i = 0 ; i<3 ; i++)
        {
            GenerateFruit();
            GenerateAlcohol();
        }
        storeCargo_.push_back(std::make_shared<Fruit>("Banan",27,11));

        //Tutaj musze zrobic jakies akumulowanie tych samych rzeczy.
    }

    Response buy(std::shared_ptr<Cargo> cargo, size_t amount, std::unique_ptr<Player> &player);
    Response sell(std::shared_ptr<Cargo> cargo, size_t amount, std::unique_ptr<Player> &player);

   
    void GenerateFruit();
    void GenerateAlcohol();
    void GenerateItem();

    void printCargo() const;
    
    private:
    std::vector<std::shared_ptr<Cargo>> storeCargo_;
    int generateRandomNumber(const int&, const int&);
    std::shared_ptr<Cargo> findMatchCargo(std::shared_ptr<Cargo>);

};