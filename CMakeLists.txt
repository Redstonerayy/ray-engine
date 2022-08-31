CMAKE_MINIMUM_REQUIRED(VERSION 3.24)
project(rayengine)

#
FILE(GLOB SOURCE_FILES)

#
add_executable(engine)

#
target_include_directories(
    engine PRIVATE
    src/include/
)

target_compile_features(

)

target_link_libraries(

)