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

# App principal
file(GLOB_RECURSE APP_SOURCES
    "src/model/*.cpp"
    "src/view/*.cpp"
    "src/controller/*.cpp"
    "src/repo/*.cpp"
    "src/services/*.cpp"
    "src/exceptions/*.cpp"
    "src/mappers/*.cpp"
    "main.cpp"
)

add_executable(supermercado_app ${APP_SOURCES})

# Testes
find_package(GTest REQUIRED)

# Mesmos ficheiros que a app, menos main.cpp
file(GLOB_RECURSE TEST_SRC
    "src/model/*.cpp"
    "src/view/*.cpp"
    "src/controller/*.cpp"
    "src/repo/*.cpp"
    "src/services/*.cpp"
    "src/exceptions/*.cpp"
    "src/mappers/*.cpp"
)

# Ficheiros de teste
file(GLOB_RECURSE TEST_FILES "../ProjectTester/src/*.cpp")

add_executable(supermercado_tester ${TEST_SRC} ${TEST_FILES})
target_include_directories(supermercado_tester PRIVATE ${GTEST_INCLUDE_DIRS})
target_link_libraries(supermercado_tester ${GTEST_LIBRARIES} pthread)
