# Test CMakeLists.txt
# Try to find Apache Arrow, but make it optional for local development
find_package(Arrow QUIET)

# Simple test executable
add_executable(test_example test_example.cpp ../src/example.cpp)
target_include_directories(test_example PRIVATE ../include)

# Conditionally compile with Apache Arrow if available
if(Arrow_FOUND)
    target_link_libraries(test_example Arrow::arrow_shared)
    target_compile_definitions(test_example PRIVATE HAVE_ARROW=1)
endif()

# Add test
add_test(NAME BasicTest COMMAND test_example)