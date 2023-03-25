add_library(WindowManager
  STATIC
  WindowManager.cpp
  WindowCanNotBeCreated.hpp)

target_link_libraries(WindowManager
  glfw)

target_include_directories(WindowManager
        PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR})
