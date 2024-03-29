cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


project(std__sort)

file(GLOB SOURCES *.cpp)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()
include(GoogleTest)

add_executable(SortTests ./sortingGTEST.cpp)
add_executable(${PROJECT_NAME} ./sorting.cpp)
target_compile_options(SortTests PRIVATE -Wall -Wextra -Werror)
target_link_libraries(SortTests gtest gtest_main)
add_test(NAME tests COMMAND SortTests)
