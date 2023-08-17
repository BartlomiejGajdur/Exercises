cmake_minimum_required(VERSION 3.0)


project(PARALLERCOUNTIF)


include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
FetchContent_MakeAvailable(googletest)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()
include(GoogleTest)

add_executable(TestsParaller ./ParallerTests.cpp)
add_executable(${PROJECT_NAME} ./main.cpp)
target_compile_options(TestsParaller PRIVATE -Wall -Wextra -Werror)
target_link_libraries(TestsParaller gtest gtest_main)
add_test(NAME tests COMMAND TestsParaller)
