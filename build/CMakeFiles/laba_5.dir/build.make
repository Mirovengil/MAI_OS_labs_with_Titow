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
CMAKE_SOURCE_DIR = /home/ivan/MAI/OS/laba_5/MAI_OS_labs_with_Titow

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ivan/MAI/OS/laba_5/MAI_OS_labs_with_Titow/build

# Include any dependencies generated for this target.
include CMakeFiles/laba_5.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/laba_5.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/laba_5.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/laba_5.dir/flags.make

CMakeFiles/laba_5.dir/main.cpp.o: CMakeFiles/laba_5.dir/flags.make
CMakeFiles/laba_5.dir/main.cpp.o: ../main.cpp
CMakeFiles/laba_5.dir/main.cpp.o: CMakeFiles/laba_5.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ivan/MAI/OS/laba_5/MAI_OS_labs_with_Titow/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/laba_5.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/laba_5.dir/main.cpp.o -MF CMakeFiles/laba_5.dir/main.cpp.o.d -o CMakeFiles/laba_5.dir/main.cpp.o -c /home/ivan/MAI/OS/laba_5/MAI_OS_labs_with_Titow/main.cpp

CMakeFiles/laba_5.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/laba_5.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ivan/MAI/OS/laba_5/MAI_OS_labs_with_Titow/main.cpp > CMakeFiles/laba_5.dir/main.cpp.i

CMakeFiles/laba_5.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/laba_5.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ivan/MAI/OS/laba_5/MAI_OS_labs_with_Titow/main.cpp -o CMakeFiles/laba_5.dir/main.cpp.s

# Object files for target laba_5
laba_5_OBJECTS = \
"CMakeFiles/laba_5.dir/main.cpp.o"

# External object files for target laba_5
laba_5_EXTERNAL_OBJECTS =

laba_5: CMakeFiles/laba_5.dir/main.cpp.o
laba_5: CMakeFiles/laba_5.dir/build.make
laba_5: CMakeFiles/laba_5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ivan/MAI/OS/laba_5/MAI_OS_labs_with_Titow/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable laba_5"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/laba_5.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/laba_5.dir/build: laba_5
.PHONY : CMakeFiles/laba_5.dir/build

CMakeFiles/laba_5.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/laba_5.dir/cmake_clean.cmake
.PHONY : CMakeFiles/laba_5.dir/clean

CMakeFiles/laba_5.dir/depend:
	cd /home/ivan/MAI/OS/laba_5/MAI_OS_labs_with_Titow/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ivan/MAI/OS/laba_5/MAI_OS_labs_with_Titow /home/ivan/MAI/OS/laba_5/MAI_OS_labs_with_Titow /home/ivan/MAI/OS/laba_5/MAI_OS_labs_with_Titow/build /home/ivan/MAI/OS/laba_5/MAI_OS_labs_with_Titow/build /home/ivan/MAI/OS/laba_5/MAI_OS_labs_with_Titow/build/CMakeFiles/laba_5.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/laba_5.dir/depend
