# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/anastasia/project_c_sem1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/anastasia/project_c_sem1/build

# Include any dependencies generated for this target.
include project_c/src/CMakeFiles/balls.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include project_c/src/CMakeFiles/balls.dir/compiler_depend.make

# Include the progress variables for this target.
include project_c/src/CMakeFiles/balls.dir/progress.make

# Include the compile flags for this target's objects.
include project_c/src/CMakeFiles/balls.dir/flags.make

project_c/src/CMakeFiles/balls.dir/main.cpp.o: project_c/src/CMakeFiles/balls.dir/flags.make
project_c/src/CMakeFiles/balls.dir/main.cpp.o: ../project_c/src/main.cpp
project_c/src/CMakeFiles/balls.dir/main.cpp.o: project_c/src/CMakeFiles/balls.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anastasia/project_c_sem1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object project_c/src/CMakeFiles/balls.dir/main.cpp.o"
	cd /home/anastasia/project_c_sem1/build/project_c/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT project_c/src/CMakeFiles/balls.dir/main.cpp.o -MF CMakeFiles/balls.dir/main.cpp.o.d -o CMakeFiles/balls.dir/main.cpp.o -c /home/anastasia/project_c_sem1/project_c/src/main.cpp

project_c/src/CMakeFiles/balls.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/balls.dir/main.cpp.i"
	cd /home/anastasia/project_c_sem1/build/project_c/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anastasia/project_c_sem1/project_c/src/main.cpp > CMakeFiles/balls.dir/main.cpp.i

project_c/src/CMakeFiles/balls.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/balls.dir/main.cpp.s"
	cd /home/anastasia/project_c_sem1/build/project_c/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anastasia/project_c_sem1/project_c/src/main.cpp -o CMakeFiles/balls.dir/main.cpp.s

project_c/src/CMakeFiles/balls.dir/frontend.cpp.o: project_c/src/CMakeFiles/balls.dir/flags.make
project_c/src/CMakeFiles/balls.dir/frontend.cpp.o: ../project_c/src/frontend.cpp
project_c/src/CMakeFiles/balls.dir/frontend.cpp.o: project_c/src/CMakeFiles/balls.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anastasia/project_c_sem1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object project_c/src/CMakeFiles/balls.dir/frontend.cpp.o"
	cd /home/anastasia/project_c_sem1/build/project_c/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT project_c/src/CMakeFiles/balls.dir/frontend.cpp.o -MF CMakeFiles/balls.dir/frontend.cpp.o.d -o CMakeFiles/balls.dir/frontend.cpp.o -c /home/anastasia/project_c_sem1/project_c/src/frontend.cpp

project_c/src/CMakeFiles/balls.dir/frontend.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/balls.dir/frontend.cpp.i"
	cd /home/anastasia/project_c_sem1/build/project_c/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anastasia/project_c_sem1/project_c/src/frontend.cpp > CMakeFiles/balls.dir/frontend.cpp.i

project_c/src/CMakeFiles/balls.dir/frontend.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/balls.dir/frontend.cpp.s"
	cd /home/anastasia/project_c_sem1/build/project_c/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anastasia/project_c_sem1/project_c/src/frontend.cpp -o CMakeFiles/balls.dir/frontend.cpp.s

project_c/src/CMakeFiles/balls.dir/backend.cpp.o: project_c/src/CMakeFiles/balls.dir/flags.make
project_c/src/CMakeFiles/balls.dir/backend.cpp.o: ../project_c/src/backend.cpp
project_c/src/CMakeFiles/balls.dir/backend.cpp.o: project_c/src/CMakeFiles/balls.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anastasia/project_c_sem1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object project_c/src/CMakeFiles/balls.dir/backend.cpp.o"
	cd /home/anastasia/project_c_sem1/build/project_c/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT project_c/src/CMakeFiles/balls.dir/backend.cpp.o -MF CMakeFiles/balls.dir/backend.cpp.o.d -o CMakeFiles/balls.dir/backend.cpp.o -c /home/anastasia/project_c_sem1/project_c/src/backend.cpp

project_c/src/CMakeFiles/balls.dir/backend.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/balls.dir/backend.cpp.i"
	cd /home/anastasia/project_c_sem1/build/project_c/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anastasia/project_c_sem1/project_c/src/backend.cpp > CMakeFiles/balls.dir/backend.cpp.i

project_c/src/CMakeFiles/balls.dir/backend.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/balls.dir/backend.cpp.s"
	cd /home/anastasia/project_c_sem1/build/project_c/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anastasia/project_c_sem1/project_c/src/backend.cpp -o CMakeFiles/balls.dir/backend.cpp.s

project_c/src/CMakeFiles/balls.dir/__/lib/Graph_lib/Graph.cpp.o: project_c/src/CMakeFiles/balls.dir/flags.make
project_c/src/CMakeFiles/balls.dir/__/lib/Graph_lib/Graph.cpp.o: ../project_c/lib/Graph_lib/Graph.cpp
project_c/src/CMakeFiles/balls.dir/__/lib/Graph_lib/Graph.cpp.o: project_c/src/CMakeFiles/balls.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anastasia/project_c_sem1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object project_c/src/CMakeFiles/balls.dir/__/lib/Graph_lib/Graph.cpp.o"
	cd /home/anastasia/project_c_sem1/build/project_c/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT project_c/src/CMakeFiles/balls.dir/__/lib/Graph_lib/Graph.cpp.o -MF CMakeFiles/balls.dir/__/lib/Graph_lib/Graph.cpp.o.d -o CMakeFiles/balls.dir/__/lib/Graph_lib/Graph.cpp.o -c /home/anastasia/project_c_sem1/project_c/lib/Graph_lib/Graph.cpp

project_c/src/CMakeFiles/balls.dir/__/lib/Graph_lib/Graph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/balls.dir/__/lib/Graph_lib/Graph.cpp.i"
	cd /home/anastasia/project_c_sem1/build/project_c/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anastasia/project_c_sem1/project_c/lib/Graph_lib/Graph.cpp > CMakeFiles/balls.dir/__/lib/Graph_lib/Graph.cpp.i

project_c/src/CMakeFiles/balls.dir/__/lib/Graph_lib/Graph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/balls.dir/__/lib/Graph_lib/Graph.cpp.s"
	cd /home/anastasia/project_c_sem1/build/project_c/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anastasia/project_c_sem1/project_c/lib/Graph_lib/Graph.cpp -o CMakeFiles/balls.dir/__/lib/Graph_lib/Graph.cpp.s

project_c/src/CMakeFiles/balls.dir/__/lib/Graph_lib/GUI.cpp.o: project_c/src/CMakeFiles/balls.dir/flags.make
project_c/src/CMakeFiles/balls.dir/__/lib/Graph_lib/GUI.cpp.o: ../project_c/lib/Graph_lib/GUI.cpp
project_c/src/CMakeFiles/balls.dir/__/lib/Graph_lib/GUI.cpp.o: project_c/src/CMakeFiles/balls.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anastasia/project_c_sem1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object project_c/src/CMakeFiles/balls.dir/__/lib/Graph_lib/GUI.cpp.o"
	cd /home/anastasia/project_c_sem1/build/project_c/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT project_c/src/CMakeFiles/balls.dir/__/lib/Graph_lib/GUI.cpp.o -MF CMakeFiles/balls.dir/__/lib/Graph_lib/GUI.cpp.o.d -o CMakeFiles/balls.dir/__/lib/Graph_lib/GUI.cpp.o -c /home/anastasia/project_c_sem1/project_c/lib/Graph_lib/GUI.cpp

project_c/src/CMakeFiles/balls.dir/__/lib/Graph_lib/GUI.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/balls.dir/__/lib/Graph_lib/GUI.cpp.i"
	cd /home/anastasia/project_c_sem1/build/project_c/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anastasia/project_c_sem1/project_c/lib/Graph_lib/GUI.cpp > CMakeFiles/balls.dir/__/lib/Graph_lib/GUI.cpp.i

project_c/src/CMakeFiles/balls.dir/__/lib/Graph_lib/GUI.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/balls.dir/__/lib/Graph_lib/GUI.cpp.s"
	cd /home/anastasia/project_c_sem1/build/project_c/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anastasia/project_c_sem1/project_c/lib/Graph_lib/GUI.cpp -o CMakeFiles/balls.dir/__/lib/Graph_lib/GUI.cpp.s

project_c/src/CMakeFiles/balls.dir/__/lib/Graph_lib/Window.cpp.o: project_c/src/CMakeFiles/balls.dir/flags.make
project_c/src/CMakeFiles/balls.dir/__/lib/Graph_lib/Window.cpp.o: ../project_c/lib/Graph_lib/Window.cpp
project_c/src/CMakeFiles/balls.dir/__/lib/Graph_lib/Window.cpp.o: project_c/src/CMakeFiles/balls.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/anastasia/project_c_sem1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object project_c/src/CMakeFiles/balls.dir/__/lib/Graph_lib/Window.cpp.o"
	cd /home/anastasia/project_c_sem1/build/project_c/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT project_c/src/CMakeFiles/balls.dir/__/lib/Graph_lib/Window.cpp.o -MF CMakeFiles/balls.dir/__/lib/Graph_lib/Window.cpp.o.d -o CMakeFiles/balls.dir/__/lib/Graph_lib/Window.cpp.o -c /home/anastasia/project_c_sem1/project_c/lib/Graph_lib/Window.cpp

project_c/src/CMakeFiles/balls.dir/__/lib/Graph_lib/Window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/balls.dir/__/lib/Graph_lib/Window.cpp.i"
	cd /home/anastasia/project_c_sem1/build/project_c/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/anastasia/project_c_sem1/project_c/lib/Graph_lib/Window.cpp > CMakeFiles/balls.dir/__/lib/Graph_lib/Window.cpp.i

project_c/src/CMakeFiles/balls.dir/__/lib/Graph_lib/Window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/balls.dir/__/lib/Graph_lib/Window.cpp.s"
	cd /home/anastasia/project_c_sem1/build/project_c/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/anastasia/project_c_sem1/project_c/lib/Graph_lib/Window.cpp -o CMakeFiles/balls.dir/__/lib/Graph_lib/Window.cpp.s

# Object files for target balls
balls_OBJECTS = \
"CMakeFiles/balls.dir/main.cpp.o" \
"CMakeFiles/balls.dir/frontend.cpp.o" \
"CMakeFiles/balls.dir/backend.cpp.o" \
"CMakeFiles/balls.dir/__/lib/Graph_lib/Graph.cpp.o" \
"CMakeFiles/balls.dir/__/lib/Graph_lib/GUI.cpp.o" \
"CMakeFiles/balls.dir/__/lib/Graph_lib/Window.cpp.o"

# External object files for target balls
balls_EXTERNAL_OBJECTS =

project_c/src/balls: project_c/src/CMakeFiles/balls.dir/main.cpp.o
project_c/src/balls: project_c/src/CMakeFiles/balls.dir/frontend.cpp.o
project_c/src/balls: project_c/src/CMakeFiles/balls.dir/backend.cpp.o
project_c/src/balls: project_c/src/CMakeFiles/balls.dir/__/lib/Graph_lib/Graph.cpp.o
project_c/src/balls: project_c/src/CMakeFiles/balls.dir/__/lib/Graph_lib/GUI.cpp.o
project_c/src/balls: project_c/src/CMakeFiles/balls.dir/__/lib/Graph_lib/Window.cpp.o
project_c/src/balls: project_c/src/CMakeFiles/balls.dir/build.make
project_c/src/balls: /usr/lib/x86_64-linux-gnu/libGL.so
project_c/src/balls: /usr/lib/x86_64-linux-gnu/libX11.so
project_c/src/balls: /usr/lib/x86_64-linux-gnu/libm.so
project_c/src/balls: /usr/lib/x86_64-linux-gnu/libGL.so
project_c/src/balls: /usr/lib/x86_64-linux-gnu/libGLU.so
project_c/src/balls: /usr/lib/x86_64-linux-gnu/libGL.so
project_c/src/balls: /usr/lib/x86_64-linux-gnu/libX11.so
project_c/src/balls: /usr/lib/x86_64-linux-gnu/libm.so
project_c/src/balls: /usr/lib/x86_64-linux-gnu/libGL.so
project_c/src/balls: /usr/lib/x86_64-linux-gnu/libGLU.so
project_c/src/balls: project_c/src/CMakeFiles/balls.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/anastasia/project_c_sem1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable balls"
	cd /home/anastasia/project_c_sem1/build/project_c/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/balls.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
project_c/src/CMakeFiles/balls.dir/build: project_c/src/balls
.PHONY : project_c/src/CMakeFiles/balls.dir/build

project_c/src/CMakeFiles/balls.dir/clean:
	cd /home/anastasia/project_c_sem1/build/project_c/src && $(CMAKE_COMMAND) -P CMakeFiles/balls.dir/cmake_clean.cmake
.PHONY : project_c/src/CMakeFiles/balls.dir/clean

project_c/src/CMakeFiles/balls.dir/depend:
	cd /home/anastasia/project_c_sem1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/anastasia/project_c_sem1 /home/anastasia/project_c_sem1/project_c/src /home/anastasia/project_c_sem1/build /home/anastasia/project_c_sem1/build/project_c/src /home/anastasia/project_c_sem1/build/project_c/src/CMakeFiles/balls.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : project_c/src/CMakeFiles/balls.dir/depend
