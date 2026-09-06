add_library(order_calc src/order_calc.cpp src/order_calc.h)
target_include_directories(order_calc PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(order_tests test/test_order.cpp)
target_link_libraries(order_tests PRIVATE order_calc GTest::gtest_main)
add_test(NAME tests_lab1 COMMAND order_tests)