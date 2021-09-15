add_library(BreakItAllLibJNIWrapper
            SHARED
            main.cpp)

target_link_libraries(BreakItAllLibJNIWrapper
                      BreakItAll
                      -landroid)
