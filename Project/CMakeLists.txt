cmake_minimum_required(VERSION 3.10)
project(SupermercadoProject)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)
include_directories(include/model)
include_directories(include/view)
include_directories(include/controller)
include_directories(include/repo)
include_directories(include/services)
include_directories(include/exceptions)
include_directories(include/dto)
include_directories(include/mappers)

file(GLOB_RECURSE SOURCES 
    "src/model/*.cpp"
    "src/view/*.cpp"
    "src/controller/*.cpp"
    "src/repo/*.cpp"
    "src/services/*.cpp"
    "src/exceptions/*.cpp"
    "src/mappers/*.cpp"
    "main.cpp"
)

add_executable(supermercado_app ${SOURCES})
