#include <iostream>
#include <cassert>
#ifdef HAVE_ARROW
#include <arrow/api.h>
#endif
#include "example.h"

int main() {
    // Test the greeting function
    std::string result = cpp_template::greet("Test");
    assert(result == "Hello, Test!");
    std::cout << "✓ Greeting test passed" << std::endl;
    
#ifdef HAVE_ARROW
    // Test Apache Arrow basic functionality
    auto pool = arrow::default_memory_pool();
    assert(pool != nullptr);
    std::cout << "✓ Apache Arrow integration test passed" << std::endl;
#else
    std::cout << "✓ Apache Arrow not available - skipping Arrow tests" << std::endl;
#endif
    
    std::cout << "All tests passed!" << std::endl;
    return 0;
}