enable_testing()

include(cmake/DownloadProject.cmake)
include(cmake/googletest.cmake)

add_executable(executeTests
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
        COMMAND lcov -c -i -d ${CMAKE_BINARY_DIR} -o lcov.before.info
        COMMAND executeTests
        COMMAND lcov -c -d ${CMAKE_BINARY_DIR} -o lcov.after.info
        COMMAND lcov -a lcov.before.info -a lcov.after.info -o lcov.coverage.info
        DEPENDS executeTests
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})

add_custom_target(showCoverage
        COMMAND genhtml lcov.coverage.info -o out
        COMMAND google-chrome out/index.html
        DEPENDS coverage
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
