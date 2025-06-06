# cpp-template

A C++ template project with Apache Arrow integration and GitHub Actions CI.

## Features

- Modern C++17 project structure
- Apache Arrow integration for columnar data processing
- CMake build system with optional dependency handling
- Basic test infrastructure using CTest
- GitHub Actions CI workflow
- Cross-platform support

## Building

### Prerequisites

- CMake 3.16 or later
- C++17 compatible compiler (GCC, Clang, MSVC)
- Apache Arrow (optional for local development)

### Local Build

```bash
# Configure
cmake -B build -DCMAKE_BUILD_TYPE=Release

# Build
cmake --build build --config Release

# Run tests
cd build && ctest --output-on-failure

# Run the main executable
./build/main
```

### With Apache Arrow

If Apache Arrow is installed, the project will automatically detect and use it:

```bash
# Ubuntu/Debian
sudo apt-get install libarrow-dev

# Build with Arrow support
cmake -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build --config Release
./build/main
```

## Project Structure

```
├── src/              # Source files
├── include/          # Header files
├── tests/            # Test files
├── .github/workflows/# CI configuration
├── CMakeLists.txt    # Root CMake configuration
└── README.md         # This file
```

## CI/CD

The project includes a GitHub Actions workflow that:
- Builds on Ubuntu latest
- Installs Apache Arrow
- Runs all tests
- Triggers on push to main/develop and pull requests

## Development

The project is designed to be developer-friendly:
- Builds without Apache Arrow for quick local development
- Full Arrow integration tested in CI
- Minimal dependencies for fast iteration
- Clear separation of concerns
