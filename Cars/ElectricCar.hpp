#include "ElectricEngine.hpp"
#include "Cars.hpp"
class ElectricCar : public Cars
{
public:
    ElectricCar(ElectricEngine* engine);
    ~ElectricCar();
    
    void charge();

    ElectricEngine* engine_;
};

