enable_testing()

include(cmake/DownloadProject.cmake)
include(cmake/googletest.cmake)

add_executable(executeTests
        tests/sqrt_test.cpp
        tests/game_test.cpp)

target_link_libraries(executeTests
        common
        gtest)

add_test(NAME executeTests
        COMMAND executeTests)

add_custom_target(check
        COMMAND env CTEST_OUTPUT_ON_FAILURE=1 GTEST_COLOR=1 ${CMAKE_CTEST_COMMAND} -VV
        DEPENDS executeTests)

add_custom_target(coverage
        COMMAND lcov -c -d ${common_binary_dir} -o cov.info
        COMMAND genhtml cov.info -o out
        COMMAND google-chrome out/index.html
        DEPENDS check
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
