#include "AppendNewRecipe.hpp"
#include <algorithm>
#include <sstream> 
#include <iterator>
#include <fstream>

//Function shall convert given char to properly string
std::string convertCharIntoString(char zn){
  
  switch (zn)
  {
  case 'g':
    return " gram";
    break;
  case 's':
    return " szklanka(i)";
    break;
  case 'm':
    return " mililitrow";
    break;
  
  default:
    return " Non-expected ingredient";
    break;
  }
  return " Error";
}

//Function shall return vector of strings from given deque of pair<size_t ,char>
std::vector<std::string> formatDequeAmount(const std::deque<std::pair<size_t, char>>& amount){
  std::vector<std::string> formattedDeque;

  std::for_each(amount.begin(),amount.end(),[&formattedDeque](const auto pair)
  {
    formattedDeque.push_back(std::to_string(pair.first)+convertCharIntoString(pair.second));
  });

  return formattedDeque;
}

std::vector<std::string> FormatIngredients(const std::list<std::string>& ingredients,
                                          const std::deque<std::pair<size_t, char>>& amount)
                                          {
                                            std::vector<std::string> FormatDeque = formatDequeAmount(amount);
                                            std::vector<std::string> FormatIngredients;

                                            std::transform(FormatDeque.begin(),FormatDeque.end(),ingredients.begin(),std::back_inserter(FormatIngredients),
                                            [](const std::string& lhs, const std::string& rhs)
                                            { 
                                              return lhs + " " + rhs;
                                            });
                                            
                                            return FormatIngredients;
                                          }
                            

std::stringstream FormatRecipit(std::vector<std::string> steps,
                                const std::list<std::string>& ingredients,
                                const std::deque<std::pair<size_t, char>>& amount)
                                {
                                    std::vector<std::string> formattedIngredients = FormatIngredients(ingredients, amount);
                                    std::stringstream stream;
                                    
                                    stream<<"Skladniki:\n";
                                    std::for_each(formattedIngredients.begin(),formattedIngredients.end(),
                                    [&stream](const std::string& line)
                                    {
                                      stream<<line+",\n";
                                    });

                                    stream<<"\nKroki:\n";
                                    std::for_each(steps.begin(),steps.end(),
                                    [&stream,i{0}] (const std::string& line) mutable
                                    {
                                      stream<<++i<<") "+line+".\n";
                                    });

                                    stream<<"___________________________________\n";
                                    return stream;
                                }


bool AppendNewRecipe(std::vector<std::string> steps,
                          const std::list<std::string>& ingredients,
                          const std::deque<std::pair<size_t, char>>& amount)
                          {
                            
                            std::stringstream stream = FormatRecipit (steps,ingredients,amount);
                            std::fstream recipes("recipes.txt", recipes.out | recipes.app);

                            if(recipes.is_open()){
                              recipes<<stream.str();
                              return true;
                            }
                              return false;
                          }