#pragma once 
#include "Cargo.hpp"
#include "Player.hpp"


class Store{
    public:
    enum class Response{done = 1, lack_of_money, lack_of_cargo, lack_of_space};

    Store(std::vector<std::shared_ptr<Cargo>> storeCargo): storeCargo_(storeCargo) {}
    Store(){
        //Tu bedzie kontruktor który randomowo tworzy np 10 randomowych towarów do kupienia
        //np 6 random owocow 3 alcohole i itemek jakis losowy
    }

    Response buy(std::shared_ptr<Cargo> cargo, size_t amount, std::shared_ptr<Player> player);
    Response sell(std::shared_ptr<Cargo> cargo, size_t amount, std::shared_ptr<Player> player);

    private:
    std::vector<std::shared_ptr<Cargo>> storeCargo_;

};