#include <iostream>
#ifdef HAVE_ARROW
#include <arrow/api.h>
#endif
#include "example.h"

int main() {
    // Simple greeting example
    std::cout << cpp_template::greet("World") << std::endl;
    
#ifdef HAVE_ARROW
    // Basic Apache Arrow usage to verify integration
    auto pool = arrow::default_memory_pool();
    std::cout << "Apache Arrow memory pool initialized successfully" << std::endl;
#else
    std::cout << "Apache Arrow not available - running in basic mode" << std::endl;
#endif
    
    return 0;
}