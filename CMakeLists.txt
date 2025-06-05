cmake_minimum_required(VERSION 3.16)
project(cpp_template VERSION 1.0.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Try to find Apache Arrow, but make it optional for local development
find_package(Arrow QUIET)

# Include directories
include_directories(include)

# Add the main executable
add_executable(main src/main.cpp src/example.cpp)

# Conditionally compile with Apache Arrow if available
if(Arrow_FOUND)
    target_link_libraries(main Arrow::arrow_shared)
    target_compile_definitions(main PRIVATE HAVE_ARROW=1)
    message(STATUS "Apache Arrow found and enabled")
else()
    message(WARNING "Apache Arrow not found - building without Arrow support")
endif()

# Enable testing
enable_testing()

# Add subdirectory for tests
add_subdirectory(tests)