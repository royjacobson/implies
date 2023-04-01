find_package(GTest REQUIRED)

add_executable(
    test_implies
    test_implies.cpp
)
target_link_libraries(
    test_implies
    GTest::gtest_main implies
)

include(GoogleTest)
gtest_discover_tests(test_implies)
