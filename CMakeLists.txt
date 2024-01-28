cmake_minimum_required(VERSION 3.20)
project(test)

set(CMAKE_CXX_STANDARD 20)

include(FetchContent)
FetchContent_Declare(
    sfml
    GIT_REPOSITORY https://github.com/SFML/SFML
    GIT_TAG 2.6.0
)
FetchContent_MakeAvailable(sfml)

add_executable(test src/main.cpp src/Engine.cpp headers/Engine.h src/Board.cpp headers/Board.h)
target_include_directories(${PROJECT_NAME} PRIVATE headers ${sfml_SOURCE_DIR}/include)
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-system sfml-window sfml-graphics sfml-network sfml-audio)