cmake_minimum_required(VERSION 3.10)
project(TaskManager)

# Find GLFW package (this is the modern way)
find_package(glfw3 REQUIRED)

# If the above doesn't work, you can try pkg-config (common on Linux)
# find_package(PkgConfig REQUIRED)
# pkg_search_module(GLFW REQUIRED glfw3)

# Create the executable
add_executable(Task_Manager todo.c)

# Link GLFW to your program
target_link_libraries(Task_Manager glfw)

# On Linux, you may need additional OpenGL libraries
if(UNIX AND NOT APPLE)
    target_link_libraries(Task_Manager GL X11 pthread Xrandr Xi dl)
endif()