# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


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
CMAKE_COMMAND = "/Users/pete/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/192.5728.100/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/pete/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/192.5728.100/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/pete/CLionProjects/untitled2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/pete/CLionProjects/untitled2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/untitled2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/untitled2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/untitled2.dir/flags.make

CMakeFiles/untitled2.dir/main.cpp.o: CMakeFiles/untitled2.dir/flags.make
CMakeFiles/untitled2.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/pete/CLionProjects/untitled2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/untitled2.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/untitled2.dir/main.cpp.o -c /Users/pete/CLionProjects/untitled2/main.cpp

CMakeFiles/untitled2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/untitled2.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/pete/CLionProjects/untitled2/main.cpp > CMakeFiles/untitled2.dir/main.cpp.i

CMakeFiles/untitled2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/untitled2.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/pete/CLionProjects/untitled2/main.cpp -o CMakeFiles/untitled2.dir/main.cpp.s

CMakeFiles/untitled2.dir/Shader.cpp.o: CMakeFiles/untitled2.dir/flags.make
CMakeFiles/untitled2.dir/Shader.cpp.o: ../Shader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/pete/CLionProjects/untitled2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/untitled2.dir/Shader.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/untitled2.dir/Shader.cpp.o -c /Users/pete/CLionProjects/untitled2/Shader.cpp

CMakeFiles/untitled2.dir/Shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/untitled2.dir/Shader.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/pete/CLionProjects/untitled2/Shader.cpp > CMakeFiles/untitled2.dir/Shader.cpp.i

CMakeFiles/untitled2.dir/Shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/untitled2.dir/Shader.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/pete/CLionProjects/untitled2/Shader.cpp -o CMakeFiles/untitled2.dir/Shader.cpp.s

# Object files for target untitled2
untitled2_OBJECTS = \
"CMakeFiles/untitled2.dir/main.cpp.o" \
"CMakeFiles/untitled2.dir/Shader.cpp.o"

# External object files for target untitled2
untitled2_EXTERNAL_OBJECTS =

bin/untitled2: CMakeFiles/untitled2.dir/main.cpp.o
bin/untitled2: CMakeFiles/untitled2.dir/Shader.cpp.o
bin/untitled2: CMakeFiles/untitled2.dir/build.make
bin/untitled2: /Users/pete/.conan/data/glfw/3.3/bincrafters/stable/package/534dcc368c999e07e81f146b3466b8f656ef1f55/lib/libglfw3.a
bin/untitled2: /Users/pete/.conan/data/glad/0.1.29/bincrafters/stable/package/94d23a5b6799ba50e68988fd8c0740e6c4ee9b52/lib/libglad.a
bin/untitled2: CMakeFiles/untitled2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/pete/CLionProjects/untitled2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable bin/untitled2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/untitled2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/untitled2.dir/build: bin/untitled2

.PHONY : CMakeFiles/untitled2.dir/build

CMakeFiles/untitled2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/untitled2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/untitled2.dir/clean

CMakeFiles/untitled2.dir/depend:
	cd /Users/pete/CLionProjects/untitled2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/pete/CLionProjects/untitled2 /Users/pete/CLionProjects/untitled2 /Users/pete/CLionProjects/untitled2/cmake-build-debug /Users/pete/CLionProjects/untitled2/cmake-build-debug /Users/pete/CLionProjects/untitled2/cmake-build-debug/CMakeFiles/untitled2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/untitled2.dir/depend

