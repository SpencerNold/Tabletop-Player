cmake_minimum_required(VERSION 3.29.3)

project(Tabletop-Player)

add_executable(${PROJECT_NAME}
    src/main.c
)

add_subdirectory(extern/glfw extern/glad)

target_include_directories(${PROJECT_NAME}
    PUBLIC extern/glfw/include
    PUBLIC extern/glad/include
)

target_link_directories(${PROJECT_NAME}
    PRIVATE extern/glad/build/Debug
)

target_link_libraries(${PROJECT_NAME}
    glfw
    glad
)