cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


project(SHM)

file(GLOB SOURCES *.cpp)


include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()
include(GoogleTest)

add_executable(${PROJECT_NAME}-ut ./tests/ShipCargoTest.cpp)
add_executable(${PROJECT_NAME} ./Ship.cpp)
target_compile_options(${PROJECT_NAME}-ut PRIVATE -Wall -Wextra -Werror)
target_link_libraries(${PROJECT_NAME}-ut gtest gtest_main)
add_test(NAME tests COMMAND ${PROJECT_NAME}-ut)

