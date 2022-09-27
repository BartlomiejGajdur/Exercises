#include "Store.hpp"

// Store::Response Store::buy(std::shared_ptr<Cargo> cargo, size_t amount, std::shared_ptr<Player> player)
// {   
//     int totalPrice = cargo->getPrice() * amount; // Mam cene tego co chce kupic.
//     std::cout<<totalPrice<<"\n\n\n\n";
//     //Powinno byc wsprawdzenie czy wgl ten towar jest w vectorze storeCargo, czaisz ?
//     //Jesli jest to sprawdza te wszystkie rzeczy jak jest done to usuwa ten towar z vectora shared_ptr.
//     if(totalPrice>player->getMoney()){
//         return Response::lack_of_money;
//     }
//     if(amount>player->getShip()->getAvailableSpace()){
//         return Response::lack_of_space;
//     }
//     if(amount>cargo->getAmount()){
//         return Response::lack_of_cargo;
//     }

//     player->getShip()->load(cargo);
//     player->substractMoney(totalPrice); //tutaj ograc to dobrze.
//     std::cout<<"Zakup done\n";
//     return Response::done;
// }
/*
Jeśli w vectorze Cargo, który mamy w Store jest dany towar który podajemy w:
buy(jakies cargo(czyli np cargo o nazwie "Jablko" i cenie bazowej 20), ilosc tego Cargo,Nie wiem czy tu potrzebny jest player)
*/