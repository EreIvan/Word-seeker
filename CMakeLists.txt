cmake_minimum_required(VERSION 2.8 FATAL_ERROR)

project(MarkTheWord LANGUAGES CXX)

add_executable(${PROJECT_NAME} main.cpp)

target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

set_target_properties (${PROJECT_NAME} PROPERTIES

    CXX_EXTENSIONS OFF

)
