cmake_minimum_required(VERSION 3.10)
project(Lever)
set(CMAKE_CXX_STANDARD 17)

# EXECUTABLE SECTION
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin/)

add_executable(main main.cpp)

target_include_directories(main PRIVATE include)

target_sources(main PRIVATE src/lever.cpp
                            src/EB_Device.cpp
                            src/myMachine.cpp
                            )

target_link_libraries(main)

# TESTS SECTION
# Basically makes CMake read the CMakeLists.txt file contained in tests
add_subdirectory(tests)