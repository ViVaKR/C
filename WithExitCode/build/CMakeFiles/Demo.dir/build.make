# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.29

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = C:\MSYS\clangarm64\bin\cmake.exe

# The command to remove a file.
RM = C:\MSYS\clangarm64\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Temp\C

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Temp\C\build

# Include any dependencies generated for this target.
include CMakeFiles/Demo.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Demo.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Demo.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Demo.dir/flags.make

CMakeFiles/Demo.dir/main.c.obj: CMakeFiles/Demo.dir/flags.make
CMakeFiles/Demo.dir/main.c.obj: C:/Temp/C/main.c
CMakeFiles/Demo.dir/main.c.obj: CMakeFiles/Demo.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Temp\C\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Demo.dir/main.c.obj"
	C:\MSYS\clangarm64\bin\clang.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Demo.dir/main.c.obj -MF CMakeFiles\Demo.dir\main.c.obj.d -o CMakeFiles\Demo.dir\main.c.obj -c C:\Temp\C\main.c

CMakeFiles/Demo.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/Demo.dir/main.c.i"
	C:\MSYS\clangarm64\bin\clang.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Temp\C\main.c > CMakeFiles\Demo.dir\main.c.i

CMakeFiles/Demo.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/Demo.dir/main.c.s"
	C:\MSYS\clangarm64\bin\clang.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Temp\C\main.c -o CMakeFiles\Demo.dir\main.c.s

# Object files for target Demo
Demo_OBJECTS = \
"CMakeFiles/Demo.dir/main.c.obj"

# External object files for target Demo
Demo_EXTERNAL_OBJECTS =

Demo.exe: CMakeFiles/Demo.dir/main.c.obj
Demo.exe: CMakeFiles/Demo.dir/build.make
Demo.exe: CMakeFiles/Demo.dir/linkLibs.rsp
Demo.exe: CMakeFiles/Demo.dir/objects1.rsp
Demo.exe: CMakeFiles/Demo.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Temp\C\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Demo.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Demo.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Demo.dir/build: Demo.exe
.PHONY : CMakeFiles/Demo.dir/build

CMakeFiles/Demo.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Demo.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Demo.dir/clean

CMakeFiles/Demo.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Temp\C C:\Temp\C C:\Temp\C\build C:\Temp\C\build C:\Temp\C\build\CMakeFiles\Demo.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Demo.dir/depend
