cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


project(SHM)

add_executable(${PROJECT_NAME} ./main.cpp ./Alcohol.cpp ./Cargo.cpp ./Coordinates.cpp ./DryFruit.cpp ./Fruit.cpp ./Island.cpp ./Item.cpp ./Map.cpp ./Player.cpp ./Ship.cpp ./Store.cpp ./Time.cpp)
#target_compile_options(${PROJECT_NAME}-ut PRIVATE -Wall -Wextra -Werror)
#Alcohol / Cargo / DryFruit / Fruit  / Island / Item / Map / Player/ Ship /Store

