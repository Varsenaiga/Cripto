# CMAKE VERSION_
cmake_minimum_required(VERSION 3.12) 

project(cripto_project)

# FIND SEAL VERSION:
find_package(SEAL 3.6.0 EXACT REQUIRED)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/executable)

# CHOOSE EXECUTABLE NAME (e.g exec)
add_executable(cripto)

# ADD ALL SOURCE FILES TO BE COMPILED (e.g. exec.cpp)
target_sources(cripto PRIVATE main.cpp processing/data_processing.cpp bd.cpp)

# LINK SEAL
target_link_libraries(cripto SEAL::seal)