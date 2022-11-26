#include "AppendNewRecipe.hpp"
#include <sstream> 

bool AppendNewRecipe(std::vector<std::string> steps,
                          const std::list<std::string>& ingredients,
                          const std::deque<std::pair<size_t, char>>& amount)
                          {
                            return true;
                          }

std::vector<std::string> FormatIngredients(const std::list<std::string>& ingredients,
                                          const std::deque<std::pair<size_t, char>>& amount)
                                          {
                                            std::vector<std::string> v{"ala","ma","kota"};
                                            return v;
                                          }
                            

std::stringstream FormatRecipit(std::vector<std::string> steps,
                                const std::list<std::string>& ingredients,
                                const std::deque<std::pair<size_t, char>>& amount)
                                {
                                    std::string ala{"ala"};
                                    std::stringstream s(ala);
                                    return s;
                                }
