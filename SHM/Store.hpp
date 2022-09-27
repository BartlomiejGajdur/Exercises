#pragma once 
#include "Cargo.hpp"
#include "Player.hpp"


class Store{
    public:

    enum class Response{done = 1, lack_of_money, lack_of_cargo, lack_of_space};

    Response buy(std::shared_ptr<Cargo> cargo, size_t amount, std::shared_ptr<Player> player);
    Response sell(std::shared_ptr<Cargo> cargo, size_t amount, std::shared_ptr<Player> player);

    private:

};