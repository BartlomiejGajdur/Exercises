#include <string>
#include <list>
#include <deque>
#include <vector>

std::string convertCharIntoString(char zn);
std::vector<std::string> formatDequeAmount(const std::deque<std::pair<size_t, char>>& amount);

bool AppendNewRecipe(std::vector<std::string> steps,
                          const std::list<std::string>& ingredients,
                          const std::deque<std::pair<size_t, char>>& amount);

std::vector<std::string> FormatIngredients(const std::list<std::string>& ingredients,
                                          const std::deque<std::pair<size_t, char>>& amount);

std::stringstream FormatRecipit(std::vector<std::string> steps,
                                const std::list<std::string>& ingredients,
                                const std::deque<std::pair<size_t, char>>& amount);