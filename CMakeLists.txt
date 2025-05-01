cmake_minimum_required(VERSION 3.10)
project(TaskManager)

# Find GLFW package (this is the modern way)
find_package(glfw3 REQUIRED)
file(COPY fonts DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

# Create the executable
add_executable(Task_Manager TaskManager.c)

# Link GLFW to your program
target_link_libraries(Task_Manager 
    glfw
    GL
    leif
    clipboard
    xcb
    m
)
# On Linux, you may need additional OpenGL libraries
if(UNIX AND NOT APPLE)
    target_link_libraries(Task_Manager GL X11 pthread Xrandr Xi dl)
endif()
