#include "PetrolEngine.hpp"
#include "Cars.hpp"
class PetrolCar : public Cars
{
public:
    PetrolCar(PetrolEngine* engine);
    ~PetrolCar();

private:
    void refuel();
    PetrolEngine* engine_;
};

