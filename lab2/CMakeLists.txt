add_library(lab2 src/Playlist.cpp src/Playlist.h)
target_include_directories(lab2 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

add_executable(lab2_test test/test.cpp)
target_link_libraries(lab2_test PRIVATE lab2 GTest::gtest_main)
add_test(NAME test2 COMMAND lab2_test)