add_library(andriodVersion
            SHARED
            main.cpp)

add_subdirectory(../BreakItAll ../BreakItAll)

target_link_libraries(andriodVersion
                      BreakItAll)