cmake_minimum_required(VERSION 3.20)
project(OpenGL_CLion_Template)

set(CMAKE_CXX_STANDARD 14)

include_directories(
        ThirdParty/glfw/include
        ThirdParty/glad/include
)
link_directories(
        ThirdParty/glfw/lib
)
link_libraries(
        opengl32.lib
        glfw3.lib
)
add_executable(
        OpenGL_CLion_Template
        Source/main.cpp
        ThirdParty/glad/src/glad.c
)

