cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


project(SHM)

include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG release-1.12.1
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(${PROJECT_NAME} ./Src/main.cpp ./Src/Alcohol.cpp ./Src/Coordinates.cpp ./Src/DryFruit.cpp ./Src/Fruit.cpp ./Src/Island.cpp ./Src/Item.cpp ./Src/Map.cpp ./Src/Player.cpp ./Src/Ship.cpp ./Src/Store.cpp ./Src/Time.cpp)

add_executable(${PROJECT_NAME}-ut ./tests/ShipCargoTest.cpp ./Src/Alcohol.cpp ./Src/Coordinates.cpp ./Src/DryFruit.cpp ./Src/Fruit.cpp ./Src/Island.cpp ./Src/Item.cpp ./Src/Map.cpp ./Src/Player.cpp ./Src/Ship.cpp ./Src/Store.cpp ./Src/Time.cpp)
target_compile_options(${PROJECT_NAME}-ut PRIVATE -Wall -Wextra -Werror)
target_link_libraries(${PROJECT_NAME}-ut gtest_main)


include(GoogleTest)
gtest_discover_tests(${PROJECT_NAME}-ut)