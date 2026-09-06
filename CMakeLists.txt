cmake_minimum_required(VERSION 4.2.3)
project(SibsutisLabs VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

enable_testing()
add_subdirectory(third_party/googletest ${CMAKE_BINARY_DIR}/googletest EXCLUDE_FROM_ALL)

add_subdirectory(lab1)