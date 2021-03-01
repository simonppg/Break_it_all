add_executable(linuxVersion
                main.cpp)

add_subdirectory(../BreakItAll ../BreakItAll)

target_link_libraries(linuxVersion
                      BreakItAll)

add_custom_target(runNew
                COMMAND linuxVersion
                DEPENDS linuxVersion
                WORKING_DIRECTORY ${CMAKE_PROJECT_DIR})