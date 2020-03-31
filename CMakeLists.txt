# Project Settings
cmake_minimum_required(VERSION 3.1)
project(MineWASM)

set(source_dir "${PROJECT_SOURCE_DIR}/src/")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/public")
add_executable(main
    ${source_dir}/main.cpp
)

set_property(TARGET main PROPERTY CXX_STANDARD 14)
target_compile_options(main PRIVATE -Wall)

# glfw
add_subdirectory(lib/glfw EXCLUDE_FROM_ALL)
target_link_libraries(main PRIVATE glfw)

# glew
add_definitions(-DGLEW_STATIC)
add_subdirectory(lib/glew-cmake EXCLUDE_FROM_ALL)
target_link_libraries(main PRIVATE libglew_static)

# glm
add_subdirectory(lib/glm EXCLUDE_FROM_ALL)
target_link_libraries(main PRIVATE glm)