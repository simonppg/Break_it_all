# Wrapper library for glfw
add_library(WindowManager STATIC
            WindowManager.cpp)

target_link_libraries(WindowManager
                      -lglfw)

# Executable code and src files
add_executable(linuxVersion
                main.cpp)

# Tell cmake to look for more CMakeLists.txt files in this directory
add_subdirectory(../BreakItAll ../BreakItAll)

# Link library BreakItAll to linuxVersion executable
target_link_libraries(linuxVersion
                      BreakItAll
                      WindowManager)

# Custome commad to run in terminal, $ make runNew
add_custom_target(runNew
                COMMAND linuxVersion
                DEPENDS linuxVersion
                WORKING_DIRECTORY ${CMAKE_PROJECT_DIR})