# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/Users/ASUS/documents/faculdade/4_ano/1ºsemestre/cripto/Cripto

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/ASUS/documents/faculdade/4_ano/1ºsemestre/cripto/Cripto

# Include any dependencies generated for this target.
include CMakeFiles/exec.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/exec.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/exec.dir/flags.make

CMakeFiles/exec.dir/example.cpp.o: CMakeFiles/exec.dir/flags.make
CMakeFiles/exec.dir/example.cpp.o: example.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/ASUS/documents/faculdade/4_ano/1ºsemestre/cripto/Cripto/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/exec.dir/example.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/exec.dir/example.cpp.o -c /mnt/c/Users/ASUS/documents/faculdade/4_ano/1ºsemestre/cripto/Cripto/example.cpp

CMakeFiles/exec.dir/example.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/exec.dir/example.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/ASUS/documents/faculdade/4_ano/1ºsemestre/cripto/Cripto/example.cpp > CMakeFiles/exec.dir/example.cpp.i

CMakeFiles/exec.dir/example.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/exec.dir/example.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/ASUS/documents/faculdade/4_ano/1ºsemestre/cripto/Cripto/example.cpp -o CMakeFiles/exec.dir/example.cpp.s

# Object files for target exec
exec_OBJECTS = \
"CMakeFiles/exec.dir/example.cpp.o"

# External object files for target exec
exec_EXTERNAL_OBJECTS =

newdir/exec: CMakeFiles/exec.dir/example.cpp.o
newdir/exec: CMakeFiles/exec.dir/build.make
newdir/exec: /home/maxvital/mnt/c/Users/ASUS/documents/faculdade/4_ano/1ºsemestre/cripto/Cripto/lib/libseal-3.6.a
newdir/exec: CMakeFiles/exec.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/ASUS/documents/faculdade/4_ano/1ºsemestre/cripto/Cripto/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable newdir/exec"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/exec.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/exec.dir/build: newdir/exec

.PHONY : CMakeFiles/exec.dir/build

CMakeFiles/exec.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/exec.dir/cmake_clean.cmake
.PHONY : CMakeFiles/exec.dir/clean

CMakeFiles/exec.dir/depend:
	cd /mnt/c/Users/ASUS/documents/faculdade/4_ano/1ºsemestre/cripto/Cripto && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/ASUS/documents/faculdade/4_ano/1ºsemestre/cripto/Cripto /mnt/c/Users/ASUS/documents/faculdade/4_ano/1ºsemestre/cripto/Cripto /mnt/c/Users/ASUS/documents/faculdade/4_ano/1ºsemestre/cripto/Cripto /mnt/c/Users/ASUS/documents/faculdade/4_ano/1ºsemestre/cripto/Cripto /mnt/c/Users/ASUS/documents/faculdade/4_ano/1ºsemestre/cripto/Cripto/CMakeFiles/exec.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/exec.dir/depend

