cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE BOOL "Enable/Disable output of compile commands during generation.")

#set(CMAKE_C_COMPILER   "c:/Program Files/LLVM/bin/clang.exe" CACHE STRING "C compiler" FORCE)
#set(CMAKE_CXX_COMPILER "c:/Program Files/LLVM/bin/clang++.exe" CACHE STRING "C++ compiler" FORCE)

project(SHM)

file(GLOB SOURCES *.cpp)


add_executable(${PROJECT_NAME} ./Ship.cpp)
target_compile_options(${PROJECT_NAME} PUBLIC -Wall -Werror -Wpedantic -Wextra)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_SOURCE_DIR})

