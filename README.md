# cpp-template

A C++ template project with Apache Arrow integration and GitHub Actions CI.

[![CI](https://github.com/etz-hadaat/cpp-template/workflows/CI/badge.svg)](https://github.com/etz-hadaat/cpp-template/actions/workflows/ci.yml)
[![Platform Support](https://img.shields.io/badge/platform-Linux%20%7C%20Windows%20%7C%20macOS-blue)](https://github.com/etz-hadaat/cpp-template/actions/workflows/ci.yml)
[![C++ Standards](https://img.shields.io/badge/C%2B%2B-17%20%7C%2020%20%7C%2023-green)](https://github.com/etz-hadaat/cpp-template)

## Features

- Modern C++ project structure with configurable standards (C++17, C++20, C++23)
- Apache Arrow integration for columnar data processing
- CMake build system with optional dependency handling
- Basic test infrastructure using CTest
- GitHub Actions CI workflow with cross-platform matrix testing
- Cross-platform support (Linux, Windows, macOS)

## Building

### Prerequisites

- CMake 3.16 or later
- C++17, C++20, or C++23 compatible compiler (GCC, Clang, MSVC)
- Apache Arrow (optional for local development)

### Supported Platforms

This project is tested on:
- **Operating Systems**: Ubuntu (latest), Windows (latest), macOS (latest)
- **C++ Standards**: C++17, C++20, C++23
- **Compilers**: GCC (Linux), MSVC (Windows), Clang (macOS)

### Local Build

```bash
# Configure (default: C++17)
cmake -B build -DCMAKE_BUILD_TYPE=Release

# Configure with specific C++ standard
cmake -B build -DCMAKE_BUILD_TYPE=Release -DCMAKE_CXX_STANDARD=20

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

# macOS
brew install apache-arrow

# Windows
# Apache Arrow installation on Windows is more complex
# See https://arrow.apache.org/install/ for detailed instructions

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

The project includes a comprehensive GitHub Actions workflow that:
- **Cross-platform testing**: Builds and tests on Linux (Ubuntu), Windows, and macOS
- **Multi-standard support**: Tests with C++17, C++20, and C++23 standards
- **Apache Arrow integration**: Attempts to install and test Arrow where possible
- **Pull request validation**: Triggers on push to main/develop branches and pull requests
- **Matrix strategy**: Uses fail-fast=false to run all combinations even if some fail

The CI matrix covers 9 combinations (3 OS × 3 C++ standards) to ensure broad compatibility.

## Development

The project is designed to be developer-friendly:
- Builds without Apache Arrow for quick local development
- Full Arrow integration tested in CI
- Minimal dependencies for fast iteration
- Clear separation of concerns
