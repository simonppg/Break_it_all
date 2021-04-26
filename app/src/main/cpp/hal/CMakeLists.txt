if(ANDROID)
        add_library(hal
                src/android/logger.hpp
                src/android/filesManager.cpp)

        target_link_libraries(hal
                -landroid
                -llog)

        add_library(gameLibJNIWrapper
                SHARED
                src/android/main.cpp)

        target_link_libraries(gameLibJNIWrapper
                common)
else(ANDROID)
        add_definitions("-DPROJECT_DIR=\"${PROJECT_SOURCE_DIR}\"")

        add_library(hal
                src/linux/WindowManager.cpp
                src/linux/logger.hpp
                src/linux/filesManager.cpp)
        
        target_link_libraries(hal
                glfw)

        add_executable(linuxLauncher
                src/linux/main.cpp)

        target_link_libraries(linuxLauncher
                common
                glfw)

        add_custom_target(run
                COMMAND linuxLauncher
                DEPENDS linuxLauncher
                WORKING_DIRECTORY ${CMAKE_PROJECT_DIR})
endif(ANDROID)

target_include_directories(hal PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

