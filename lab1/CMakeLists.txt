cmake_minimum_required(VERSION 3.10)
project(OrderCalc VERSION 1.0 LANGUAGES CXX)

# Задаем современный стандарт C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Создаем библиотеку из исходников
add_library(order_calc src/order_calc.cpp src/order_calc.h)

# Указываем, где искать хедеры (пригодится, если будешь подключать извне)
target_include_directories(order_calc PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})