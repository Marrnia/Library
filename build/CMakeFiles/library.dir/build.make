# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = "D:\Program files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Informatics\Library

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Informatics\Library\build

# Include any dependencies generated for this target.
include CMakeFiles/library.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/library.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/library.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/library.dir/flags.make

CMakeFiles/library.dir/main.cpp.obj: CMakeFiles/library.dir/flags.make
CMakeFiles/library.dir/main.cpp.obj: CMakeFiles/library.dir/includes_CXX.rsp
CMakeFiles/library.dir/main.cpp.obj: ../main.cpp
CMakeFiles/library.dir/main.cpp.obj: CMakeFiles/library.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Informatics\Library\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/library.dir/main.cpp.obj"
	D:\TDM-GCC-64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/library.dir/main.cpp.obj -MF CMakeFiles\library.dir\main.cpp.obj.d -o CMakeFiles\library.dir\main.cpp.obj -c D:\Informatics\Library\main.cpp

CMakeFiles/library.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/library.dir/main.cpp.i"
	D:\TDM-GCC-64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Informatics\Library\main.cpp > CMakeFiles\library.dir\main.cpp.i

CMakeFiles/library.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/library.dir/main.cpp.s"
	D:\TDM-GCC-64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Informatics\Library\main.cpp -o CMakeFiles\library.dir\main.cpp.s

CMakeFiles/library.dir/src/menu.cpp.obj: CMakeFiles/library.dir/flags.make
CMakeFiles/library.dir/src/menu.cpp.obj: CMakeFiles/library.dir/includes_CXX.rsp
CMakeFiles/library.dir/src/menu.cpp.obj: ../src/menu.cpp
CMakeFiles/library.dir/src/menu.cpp.obj: CMakeFiles/library.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Informatics\Library\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/library.dir/src/menu.cpp.obj"
	D:\TDM-GCC-64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/library.dir/src/menu.cpp.obj -MF CMakeFiles\library.dir\src\menu.cpp.obj.d -o CMakeFiles\library.dir\src\menu.cpp.obj -c D:\Informatics\Library\src\menu.cpp

CMakeFiles/library.dir/src/menu.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/library.dir/src/menu.cpp.i"
	D:\TDM-GCC-64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Informatics\Library\src\menu.cpp > CMakeFiles\library.dir\src\menu.cpp.i

CMakeFiles/library.dir/src/menu.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/library.dir/src/menu.cpp.s"
	D:\TDM-GCC-64\bin\x86_64-w64-mingw32-g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Informatics\Library\src\menu.cpp -o CMakeFiles\library.dir\src\menu.cpp.s

# Object files for target library
library_OBJECTS = \
"CMakeFiles/library.dir/main.cpp.obj" \
"CMakeFiles/library.dir/src/menu.cpp.obj"

# External object files for target library
library_EXTERNAL_OBJECTS =

library.exe: CMakeFiles/library.dir/main.cpp.obj
library.exe: CMakeFiles/library.dir/src/menu.cpp.obj
library.exe: CMakeFiles/library.dir/build.make
library.exe: CMakeFiles/library.dir/linklibs.rsp
library.exe: CMakeFiles/library.dir/objects1.rsp
library.exe: CMakeFiles/library.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Informatics\Library\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable library.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\library.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/library.dir/build: library.exe
.PHONY : CMakeFiles/library.dir/build

CMakeFiles/library.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\library.dir\cmake_clean.cmake
.PHONY : CMakeFiles/library.dir/clean

CMakeFiles/library.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Informatics\Library D:\Informatics\Library D:\Informatics\Library\build D:\Informatics\Library\build D:\Informatics\Library\build\CMakeFiles\library.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/library.dir/depend

