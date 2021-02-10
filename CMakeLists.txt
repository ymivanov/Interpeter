cmake_minimum_required(VERSION 3.18.2)

project(ThisFunc)

set(EXEC ThisFunc)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCES src/*.cpp src/tests/*.cpp)

add_executable(${EXEC} ${SOURCES})

# Prepare doctest for other targets to use
find_package(doctest REQUIRED)

# Make test executable
#add_executable(tests src/tests/test.cpp ${SOURCES})
target_compile_features(ThisFunc PRIVATE cxx_std_17)
target_link_libraries(ThisFunc PRIVATE doctest::doctest)