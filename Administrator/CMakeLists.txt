# CMAKE VERSION_
cmake_minimum_required(VERSION 3.12) 

project(cripto_project)

# FIND SEAL VERSION:
find_package(SEAL 3.6.0 EXACT REQUIRED)

# CHOOSE EXECUTABLE NAME (e.g exec)
add_executable(create)

# ADD ALL SOURCE FILES TO BE COMPILED (e.g. exec.cpp)
target_sources(create PRIVATE create.cpp encryptions.cpp)

# LINK SEAL
target_link_libraries(create SEAL::seal)
