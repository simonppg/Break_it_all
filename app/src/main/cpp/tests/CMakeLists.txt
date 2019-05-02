enable_testing()
add_executable(executeTests
        src/tests/game_test.cpp)

target_link_libraries(executeTests
        math
        gtest)

add_test(NAME executeTests
        COMMAND executeTests)

add_custom_target(check
        COMMAND env CTEST_OUTPUT_ON_FAILURE=1 GTEST_COLOR=1 ${CMAKE_CTEST_COMMAND} -VV
        DEPENDS executeTests)

get_target_property(math_binary_dir math BINARY_DIR)

add_custom_target(coverage
        COMMAND lcov -c -d ${math_binary_dir} -o cov.info
        COMMAND genhtml cov.info -o out
        COMMAND google-chrome out/index.html
        DEPENDS check
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
