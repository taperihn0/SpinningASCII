# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /home/szymek/Source/SpiningASCII

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/szymek/Source/SpiningASCII/build

# Include any dependencies generated for this target.
include CMakeFiles/SpinASCII.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/SpinASCII.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/SpinASCII.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SpinASCII.dir/flags.make

CMakeFiles/SpinASCII.dir/main.c.o: CMakeFiles/SpinASCII.dir/flags.make
CMakeFiles/SpinASCII.dir/main.c.o: /home/szymek/Source/SpiningASCII/main.c
CMakeFiles/SpinASCII.dir/main.c.o: CMakeFiles/SpinASCII.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/szymek/Source/SpiningASCII/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/SpinASCII.dir/main.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/SpinASCII.dir/main.c.o -MF CMakeFiles/SpinASCII.dir/main.c.o.d -o CMakeFiles/SpinASCII.dir/main.c.o -c /home/szymek/Source/SpiningASCII/main.c

CMakeFiles/SpinASCII.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/SpinASCII.dir/main.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/szymek/Source/SpiningASCII/main.c > CMakeFiles/SpinASCII.dir/main.c.i

CMakeFiles/SpinASCII.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/SpinASCII.dir/main.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/szymek/Source/SpiningASCII/main.c -o CMakeFiles/SpinASCII.dir/main.c.s

# Object files for target SpinASCII
SpinASCII_OBJECTS = \
"CMakeFiles/SpinASCII.dir/main.c.o"

# External object files for target SpinASCII
SpinASCII_EXTERNAL_OBJECTS =

SpinASCII: CMakeFiles/SpinASCII.dir/main.c.o
SpinASCII: CMakeFiles/SpinASCII.dir/build.make
SpinASCII: /usr/lib/x86_64-linux-gnu/libm.so
SpinASCII: CMakeFiles/SpinASCII.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/szymek/Source/SpiningASCII/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable SpinASCII"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SpinASCII.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SpinASCII.dir/build: SpinASCII
.PHONY : CMakeFiles/SpinASCII.dir/build

CMakeFiles/SpinASCII.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SpinASCII.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SpinASCII.dir/clean

CMakeFiles/SpinASCII.dir/depend:
	cd /home/szymek/Source/SpiningASCII/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/szymek/Source/SpiningASCII /home/szymek/Source/SpiningASCII /home/szymek/Source/SpiningASCII/build /home/szymek/Source/SpiningASCII/build /home/szymek/Source/SpiningASCII/build/CMakeFiles/SpinASCII.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/SpinASCII.dir/depend

