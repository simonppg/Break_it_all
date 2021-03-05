add_library(BreakItAllLibJNIWrapper
            SHARED
            main.cpp)

add_subdirectory(../BreakItAll ../BreakItAll)

target_link_libraries(BreakItAllLibJNIWrapper
                      BreakItAll
                      -landroid)