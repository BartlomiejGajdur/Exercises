#include "Store.hpp"

Store::Response Store::buy(std::shared_ptr<Cargo> cargo, size_t amount, std::unique_ptr<Player> &player)
    {
        // Nie wiem czy SHIP w plajerze musi byc uniqe ptr lub jakos musze przeanalizowac kiedy shared ptr robi kopie sobie obiektu swojego
         int totalPrice = cargo->getPrice() * amount; 
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
/*
Jeśli w vectorze Cargo, który mamy w Store jest dany towar który podajemy w:
buy(jakies cargo(czyli np cargo o nazwie "Jablko" i cenie bazowej 20), ilosc tego Cargo,Nie wiem czy tu potrzebny jest player)
*/

int Store::generateRandomNumber(const int& first, const int& second){

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> Random(first, second);

    return Random(gen);
}

 void Store::printCargo() const {
        for (auto &v: storeCargo_){
            std::cout<<*v<<std::endl;
            }
 }  

 void Store::GenerateFruit() {
        
        std::array<std::string,3> name{"Jablko","Banan","Gruszka"};
        int generatedAmount = generateRandomNumber(1,10);
        int generatedBasePrice = generateRandomNumber(5,10);
        storeCargo_.push_back(std::make_shared<Fruit>(name[generateRandomNumber(0,2)],generatedAmount,generatedBasePrice));

    }