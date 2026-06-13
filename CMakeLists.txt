cmake_minimum_required(VERSION 3.15)
project(BlueWhaleEngine VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Compiler flags for optimization
if(MSVC)
    add_compile_options(/O2 /W4)
else()
    add_compile_options(-O3 -Wall -Wextra -march=native)
endif()

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/src)

# Core engine source files
set(ENGINE_SOURCES
    src/core/bitboard.cpp
    src/core/zobrist.cpp
    src/core/board.cpp
    src/core/move.cpp
    src/core/movegen.cpp
    src/evaluation/pst.cpp
    src/evaluation/eval.cpp
    src/search/search.cpp
    src/search/transposition.cpp
    src/uci/uci.cpp
    src/main.cpp
)

# Create main executable
add_executable(BlueWhale ${ENGINE_SOURCES})

# Enable multi-threading
set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)
target_link_libraries(BlueWhale PRIVATE Threads::Threads)

# Compiler optimizations for Release build
if(CMAKE_BUILD_TYPE MATCHES Release)
    if(MSVC)
        target_compile_options(BlueWhale PRIVATE /O2 /fp:fast)
    else()
        target_compile_options(BlueWhale PRIVATE -O3 -march=native -flto)
        target_link_options(BlueWhale PRIVATE -flto)
    endif()
endif()

# Testing
enable_testing()
add_subdirectory(tests)
