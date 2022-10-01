CMAKE_MINIMUM_REQUIRED(VERSION 3.23) # 3.16
project(rayengine)


# compile options
set(CMAKE_CXX_FLAGS "-Wall -O2")


# LIBRARIES
# SPDLOG
add_subdirectory(thirdparty/spdlog)

# GLFW
add_subdirectory(thirdparty/glfw)

#spdlog headers
set(SPDLOG_HEADERS 
        thirdparty/spdlog/include/spdlog/sinks/stdout_color_sinks.h
        thirdparty/spdlog/include/spdlog/spdlog.h
)

set(ENGINE_HEADERS
        engine/src/include/engine.hpp
)


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
        engine/src/include/window
        engine/src/include/platforms/windows
        engine/src/pch
) # includes for engine


target_include_directories(engine PRIVATE thirdparty/spdlog/include/)
target_precompile_headers(engine PRIVATE ${SPDLOG_HEADERS} engine/src/include/pch/enginepch.hpp)



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

target_precompile_headers(lightray PRIVATE ${ENGINE_HEADERS})

target_link_libraries(lightray engine spdlog glfw)

