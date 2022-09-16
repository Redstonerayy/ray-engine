CMAKE_MINIMUM_REQUIRED(VERSION 3.23)
project(rayengine)


# compile options
set(CMAKE_CXX_FLAGS "-Wall -O2")


# LIBRARIES
# SPDLOG
add_subdirectory(thirdparty/spdlog)


# ENGINE
FILE(GLOB SOURCE_FILES engine/src/**/*.cpp) # get source files

add_library(engine SHARED ${SOURCE_FILES}) # make .so shared library

set_property(TARGET engine PROPERTY CXX_STANDARD 20) # use c++20

target_include_directories(
    engine PRIVATE 
        engine/src/include
        engine/src/include/events
        engine/src/include/application
        engine/src/include/log
) # includes for engine
target_include_directories(engine PRIVATE thirdparty/spdlog/include/)


# LIGHTRAY
FILE(GLOB SOURCE_FILES lightray/src/**/*.cpp) # get source files

add_executable(lightray lightray/src/main.cpp ${SOURCE_FILES}) # make executable with main.cpp

set_property(TARGET lightray PROPERTY CXX_STANDARD 20) # use c++20

target_include_directories(
    lightray PRIVATE 
        engine/src/include
        engine/src/include/events
        engine/src/include/application
        engine/src/include/log
) # includes for engine
target_include_directories(lightray PRIVATE thirdparty/spdlog/include)

target_link_libraries(lightray engine spdlog)
