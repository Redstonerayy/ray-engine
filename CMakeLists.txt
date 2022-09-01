CMAKE_MINIMUM_REQUIRED(VERSION 3.23)
project(rayengine)


# 
FILE(GLOB SOURCE_FILES engine/cpp/*.cpp)

# make .so shared library
add_library(engine SHARED engine/main.cpp ${SOURCE_FILES})

# compile options
set(CMAKE_CXX_FLAGS "-Wall -O2")
set_property(TARGET engine PROPERTY CXX_STANDARD 20)

# includes
target_include_directories(
    engine PRIVATE
    engine/include/
)
