# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /cygdrive/c/Users/serha/AppData/Local/JetBrains/CLion2021.2/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/serha/AppData/Local/JetBrains/CLion2021.2/cygwin_cmake/bin/cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cygdrive/c/Users/serha/CLionProjects/Uebung2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cygdrive/c/Users/serha/CLionProjects/Uebung2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Uebung2.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Uebung2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Uebung2.dir/flags.make

CMakeFiles/Uebung2.dir/main.cpp.o: CMakeFiles/Uebung2.dir/flags.make
CMakeFiles/Uebung2.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/serha/CLionProjects/Uebung2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Uebung2.dir/main.cpp.o"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Uebung2.dir/main.cpp.o -c /cygdrive/c/Users/serha/CLionProjects/Uebung2/main.cpp

CMakeFiles/Uebung2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Uebung2.dir/main.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/serha/CLionProjects/Uebung2/main.cpp > CMakeFiles/Uebung2.dir/main.cpp.i

CMakeFiles/Uebung2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Uebung2.dir/main.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/serha/CLionProjects/Uebung2/main.cpp -o CMakeFiles/Uebung2.dir/main.cpp.s

CMakeFiles/Uebung2.dir/ListNode.cpp.o: CMakeFiles/Uebung2.dir/flags.make
CMakeFiles/Uebung2.dir/ListNode.cpp.o: ../ListNode.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/serha/CLionProjects/Uebung2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Uebung2.dir/ListNode.cpp.o"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Uebung2.dir/ListNode.cpp.o -c /cygdrive/c/Users/serha/CLionProjects/Uebung2/ListNode.cpp

CMakeFiles/Uebung2.dir/ListNode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Uebung2.dir/ListNode.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/serha/CLionProjects/Uebung2/ListNode.cpp > CMakeFiles/Uebung2.dir/ListNode.cpp.i

CMakeFiles/Uebung2.dir/ListNode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Uebung2.dir/ListNode.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/serha/CLionProjects/Uebung2/ListNode.cpp -o CMakeFiles/Uebung2.dir/ListNode.cpp.s

CMakeFiles/Uebung2.dir/LinkedList.cpp.o: CMakeFiles/Uebung2.dir/flags.make
CMakeFiles/Uebung2.dir/LinkedList.cpp.o: ../LinkedList.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cygdrive/c/Users/serha/CLionProjects/Uebung2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Uebung2.dir/LinkedList.cpp.o"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Uebung2.dir/LinkedList.cpp.o -c /cygdrive/c/Users/serha/CLionProjects/Uebung2/LinkedList.cpp

CMakeFiles/Uebung2.dir/LinkedList.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Uebung2.dir/LinkedList.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cygdrive/c/Users/serha/CLionProjects/Uebung2/LinkedList.cpp > CMakeFiles/Uebung2.dir/LinkedList.cpp.i

CMakeFiles/Uebung2.dir/LinkedList.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Uebung2.dir/LinkedList.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cygdrive/c/Users/serha/CLionProjects/Uebung2/LinkedList.cpp -o CMakeFiles/Uebung2.dir/LinkedList.cpp.s

# Object files for target Uebung2
Uebung2_OBJECTS = \
"CMakeFiles/Uebung2.dir/main.cpp.o" \
"CMakeFiles/Uebung2.dir/ListNode.cpp.o" \
"CMakeFiles/Uebung2.dir/LinkedList.cpp.o"

# External object files for target Uebung2
Uebung2_EXTERNAL_OBJECTS =

Uebung2.exe: CMakeFiles/Uebung2.dir/main.cpp.o
Uebung2.exe: CMakeFiles/Uebung2.dir/ListNode.cpp.o
Uebung2.exe: CMakeFiles/Uebung2.dir/LinkedList.cpp.o
Uebung2.exe: CMakeFiles/Uebung2.dir/build.make
Uebung2.exe: CMakeFiles/Uebung2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cygdrive/c/Users/serha/CLionProjects/Uebung2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable Uebung2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Uebung2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Uebung2.dir/build: Uebung2.exe
.PHONY : CMakeFiles/Uebung2.dir/build

CMakeFiles/Uebung2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Uebung2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Uebung2.dir/clean

CMakeFiles/Uebung2.dir/depend:
	cd /cygdrive/c/Users/serha/CLionProjects/Uebung2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cygdrive/c/Users/serha/CLionProjects/Uebung2 /cygdrive/c/Users/serha/CLionProjects/Uebung2 /cygdrive/c/Users/serha/CLionProjects/Uebung2/cmake-build-debug /cygdrive/c/Users/serha/CLionProjects/Uebung2/cmake-build-debug /cygdrive/c/Users/serha/CLionProjects/Uebung2/cmake-build-debug/CMakeFiles/Uebung2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Uebung2.dir/depend

