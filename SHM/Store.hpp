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

    Response buy(std::shared_ptr<Cargo> cargo, size_t amount, std::unique_ptr<Player> &player)
    {
         int totalPrice = cargo->getPrice() * amount; // Mam cene tego co chce kupic.
        std::cout<<totalPrice<<"\n\n\n\n";
    //Powinno byc wsprawdzenie czy wgl ten towar jest w vectorze storeCargo, czaisz ?
    //Jesli jest to sprawdza te wszystkie rzeczy jak jest done to usuwa ten towar z vectora shared_ptr.
    if(totalPrice>player->getMoney()){
        return Response::lack_of_money;
    }
    if(amount>player->getShip()->getAvailableSpace()){
        return Response::lack_of_space;
    }
    if(amount>cargo->getAmount()){
        return Response::lack_of_cargo;
    }

    player->getShip()->load(cargo);
    player->substractMoney(totalPrice); //tutaj ograc to dobrze.
    std::cout<<"Zakup done\n";
    return Response::done;
}
    
    Response sell(std::shared_ptr<Cargo> cargo, size_t amount, std::shared_ptr<Player>& player);

    private:
    std::vector<std::shared_ptr<Cargo>> storeCargo_;

};