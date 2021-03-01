# Executable code and src files
add_executable(linuxVersion
                main.cpp)

# Tell cmake to look for more CMakeLists.txt files in those directories
add_subdirectory(../BreakItAll ../BreakItAll)
add_subdirectory(../platform ../platform)

# Link library BreakItAll and WindowManager to linuxVersion executable
target_link_libraries(linuxVersion
                      BreakItAll
                      WindowManager)

# Custom command to run in the linuxVersion in the terminal, e.g. $ make runNew
add_custom_target(runNew
                COMMAND linuxVersion
                DEPENDS linuxVersion
                WORKING_DIRECTORY ${CMAKE_PROJECT_DIR})