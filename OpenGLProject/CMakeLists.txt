cmake_minimum_required(VERSION 3.10)
project(OpenGLProject)
set(glfw3_DIR "C:/Users/veltr/Desktop/Exercises/OpenGLProject/build/Release/generators")
set(opengl_system_DIR "C:/Users/veltr/Desktop/Exercises/OpenGLProject/build/Release/generators")

set(GLEW_ROOT "C:/glew-2.1.0-win32/glew-2.1.0")
set(CMAKE_PREFIX_PATH "${GLEW_ROOT};${CMAKE_PREFIX_PATH}")

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)
find_package(GLEW REQUIRED)

add_executable(${PROJECT_NAME} Application.cpp)

target_link_libraries(${PROJECT_NAME} glfw)
target_link_libraries(${PROJECT_NAME} OpenGL::GL)
target_link_libraries(${PROJECT_NAME} GLEW::GLEW)

#cmake -G "Unix Makefiles" -DCMAKE_TOOLCHAIN_FILE=conan_toolchain.cmake -DCMAKE_BUILD_TYPE=Release ..
#cmake -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Release ..