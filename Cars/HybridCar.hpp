#include "ElectricEngine.hpp"
#include "PetrolEngine.hpp"
#include "Cars.hpp"
class HybridCar : public Cars
{
public:
    HybridCar(PetrolEngine* petrolEng, ElectricEngine* electricEng);
    ~HybridCar();
    
    void charge();
    void refuel();

    PetrolEngine* petrolEngine_;
    ElectricEngine* electricEngine_;
};

