#include "PetrolEngine.hpp"
#include "ElectricEngine.hpp"

class Engine
{
private:
    PetrolEngine* Petrolengine_;
    ElectricEngine* Electricengine_;
public:
    
    Engine(PetrolEngine* petrolEng) : Petrolengine_(petrolEng) 
    {
    std::cout << __FUNCTION__ << std::endl;
}
    Engine(ElectricEngine* electricEng) : Electricengine_(electricEng)
    {
    std::cout << __FUNCTION__ << std::endl;
}

    
};
