# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = /home/leandro/Downloads/clion-2017.1.2/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/leandro/Downloads/clion-2017.1.2/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/home/leandro/Dropbox/DOUTORADO/Computação Evolutiva/LocationRouting"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/home/leandro/Dropbox/DOUTORADO/Computação Evolutiva/LocationRouting/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/LocationRouting.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/LocationRouting.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/LocationRouting.dir/flags.make

CMakeFiles/LocationRouting.dir/main.cpp.o: CMakeFiles/LocationRouting.dir/flags.make
CMakeFiles/LocationRouting.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/leandro/Dropbox/DOUTORADO/Computação Evolutiva/LocationRouting/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/LocationRouting.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LocationRouting.dir/main.cpp.o -c "/home/leandro/Dropbox/DOUTORADO/Computação Evolutiva/LocationRouting/main.cpp"

CMakeFiles/LocationRouting.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LocationRouting.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/leandro/Dropbox/DOUTORADO/Computação Evolutiva/LocationRouting/main.cpp" > CMakeFiles/LocationRouting.dir/main.cpp.i

CMakeFiles/LocationRouting.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LocationRouting.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/leandro/Dropbox/DOUTORADO/Computação Evolutiva/LocationRouting/main.cpp" -o CMakeFiles/LocationRouting.dir/main.cpp.s

CMakeFiles/LocationRouting.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/LocationRouting.dir/main.cpp.o.requires

CMakeFiles/LocationRouting.dir/main.cpp.o.provides: CMakeFiles/LocationRouting.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/LocationRouting.dir/build.make CMakeFiles/LocationRouting.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/LocationRouting.dir/main.cpp.o.provides

CMakeFiles/LocationRouting.dir/main.cpp.o.provides.build: CMakeFiles/LocationRouting.dir/main.cpp.o


CMakeFiles/LocationRouting.dir/LocationRoutingSolution.cpp.o: CMakeFiles/LocationRouting.dir/flags.make
CMakeFiles/LocationRouting.dir/LocationRoutingSolution.cpp.o: ../LocationRoutingSolution.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/leandro/Dropbox/DOUTORADO/Computação Evolutiva/LocationRouting/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/LocationRouting.dir/LocationRoutingSolution.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LocationRouting.dir/LocationRoutingSolution.cpp.o -c "/home/leandro/Dropbox/DOUTORADO/Computação Evolutiva/LocationRouting/LocationRoutingSolution.cpp"

CMakeFiles/LocationRouting.dir/LocationRoutingSolution.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LocationRouting.dir/LocationRoutingSolution.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/leandro/Dropbox/DOUTORADO/Computação Evolutiva/LocationRouting/LocationRoutingSolution.cpp" > CMakeFiles/LocationRouting.dir/LocationRoutingSolution.cpp.i

CMakeFiles/LocationRouting.dir/LocationRoutingSolution.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LocationRouting.dir/LocationRoutingSolution.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/leandro/Dropbox/DOUTORADO/Computação Evolutiva/LocationRouting/LocationRoutingSolution.cpp" -o CMakeFiles/LocationRouting.dir/LocationRoutingSolution.cpp.s

CMakeFiles/LocationRouting.dir/LocationRoutingSolution.cpp.o.requires:

.PHONY : CMakeFiles/LocationRouting.dir/LocationRoutingSolution.cpp.o.requires

CMakeFiles/LocationRouting.dir/LocationRoutingSolution.cpp.o.provides: CMakeFiles/LocationRouting.dir/LocationRoutingSolution.cpp.o.requires
	$(MAKE) -f CMakeFiles/LocationRouting.dir/build.make CMakeFiles/LocationRouting.dir/LocationRoutingSolution.cpp.o.provides.build
.PHONY : CMakeFiles/LocationRouting.dir/LocationRoutingSolution.cpp.o.provides

CMakeFiles/LocationRouting.dir/LocationRoutingSolution.cpp.o.provides.build: CMakeFiles/LocationRouting.dir/LocationRoutingSolution.cpp.o


CMakeFiles/LocationRouting.dir/LocationRoutingProblem.cpp.o: CMakeFiles/LocationRouting.dir/flags.make
CMakeFiles/LocationRouting.dir/LocationRoutingProblem.cpp.o: ../LocationRoutingProblem.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/leandro/Dropbox/DOUTORADO/Computação Evolutiva/LocationRouting/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/LocationRouting.dir/LocationRoutingProblem.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LocationRouting.dir/LocationRoutingProblem.cpp.o -c "/home/leandro/Dropbox/DOUTORADO/Computação Evolutiva/LocationRouting/LocationRoutingProblem.cpp"

CMakeFiles/LocationRouting.dir/LocationRoutingProblem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LocationRouting.dir/LocationRoutingProblem.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/leandro/Dropbox/DOUTORADO/Computação Evolutiva/LocationRouting/LocationRoutingProblem.cpp" > CMakeFiles/LocationRouting.dir/LocationRoutingProblem.cpp.i

CMakeFiles/LocationRouting.dir/LocationRoutingProblem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LocationRouting.dir/LocationRoutingProblem.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/leandro/Dropbox/DOUTORADO/Computação Evolutiva/LocationRouting/LocationRoutingProblem.cpp" -o CMakeFiles/LocationRouting.dir/LocationRoutingProblem.cpp.s

CMakeFiles/LocationRouting.dir/LocationRoutingProblem.cpp.o.requires:

.PHONY : CMakeFiles/LocationRouting.dir/LocationRoutingProblem.cpp.o.requires

CMakeFiles/LocationRouting.dir/LocationRoutingProblem.cpp.o.provides: CMakeFiles/LocationRouting.dir/LocationRoutingProblem.cpp.o.requires
	$(MAKE) -f CMakeFiles/LocationRouting.dir/build.make CMakeFiles/LocationRouting.dir/LocationRoutingProblem.cpp.o.provides.build
.PHONY : CMakeFiles/LocationRouting.dir/LocationRoutingProblem.cpp.o.provides

CMakeFiles/LocationRouting.dir/LocationRoutingProblem.cpp.o.provides.build: CMakeFiles/LocationRouting.dir/LocationRoutingProblem.cpp.o


CMakeFiles/LocationRouting.dir/GA.cpp.o: CMakeFiles/LocationRouting.dir/flags.make
CMakeFiles/LocationRouting.dir/GA.cpp.o: ../GA.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/leandro/Dropbox/DOUTORADO/Computação Evolutiva/LocationRouting/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/LocationRouting.dir/GA.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LocationRouting.dir/GA.cpp.o -c "/home/leandro/Dropbox/DOUTORADO/Computação Evolutiva/LocationRouting/GA.cpp"

CMakeFiles/LocationRouting.dir/GA.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LocationRouting.dir/GA.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/leandro/Dropbox/DOUTORADO/Computação Evolutiva/LocationRouting/GA.cpp" > CMakeFiles/LocationRouting.dir/GA.cpp.i

CMakeFiles/LocationRouting.dir/GA.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LocationRouting.dir/GA.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/leandro/Dropbox/DOUTORADO/Computação Evolutiva/LocationRouting/GA.cpp" -o CMakeFiles/LocationRouting.dir/GA.cpp.s

CMakeFiles/LocationRouting.dir/GA.cpp.o.requires:

.PHONY : CMakeFiles/LocationRouting.dir/GA.cpp.o.requires

CMakeFiles/LocationRouting.dir/GA.cpp.o.provides: CMakeFiles/LocationRouting.dir/GA.cpp.o.requires
	$(MAKE) -f CMakeFiles/LocationRouting.dir/build.make CMakeFiles/LocationRouting.dir/GA.cpp.o.provides.build
.PHONY : CMakeFiles/LocationRouting.dir/GA.cpp.o.provides

CMakeFiles/LocationRouting.dir/GA.cpp.o.provides.build: CMakeFiles/LocationRouting.dir/GA.cpp.o


CMakeFiles/LocationRouting.dir/AE.cpp.o: CMakeFiles/LocationRouting.dir/flags.make
CMakeFiles/LocationRouting.dir/AE.cpp.o: ../AE.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/leandro/Dropbox/DOUTORADO/Computação Evolutiva/LocationRouting/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/LocationRouting.dir/AE.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LocationRouting.dir/AE.cpp.o -c "/home/leandro/Dropbox/DOUTORADO/Computação Evolutiva/LocationRouting/AE.cpp"

CMakeFiles/LocationRouting.dir/AE.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LocationRouting.dir/AE.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/leandro/Dropbox/DOUTORADO/Computação Evolutiva/LocationRouting/AE.cpp" > CMakeFiles/LocationRouting.dir/AE.cpp.i

CMakeFiles/LocationRouting.dir/AE.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LocationRouting.dir/AE.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/leandro/Dropbox/DOUTORADO/Computação Evolutiva/LocationRouting/AE.cpp" -o CMakeFiles/LocationRouting.dir/AE.cpp.s

CMakeFiles/LocationRouting.dir/AE.cpp.o.requires:

.PHONY : CMakeFiles/LocationRouting.dir/AE.cpp.o.requires

CMakeFiles/LocationRouting.dir/AE.cpp.o.provides: CMakeFiles/LocationRouting.dir/AE.cpp.o.requires
	$(MAKE) -f CMakeFiles/LocationRouting.dir/build.make CMakeFiles/LocationRouting.dir/AE.cpp.o.provides.build
.PHONY : CMakeFiles/LocationRouting.dir/AE.cpp.o.provides

CMakeFiles/LocationRouting.dir/AE.cpp.o.provides.build: CMakeFiles/LocationRouting.dir/AE.cpp.o


CMakeFiles/LocationRouting.dir/Individual.cpp.o: CMakeFiles/LocationRouting.dir/flags.make
CMakeFiles/LocationRouting.dir/Individual.cpp.o: ../Individual.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/home/leandro/Dropbox/DOUTORADO/Computação Evolutiva/LocationRouting/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/LocationRouting.dir/Individual.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/LocationRouting.dir/Individual.cpp.o -c "/home/leandro/Dropbox/DOUTORADO/Computação Evolutiva/LocationRouting/Individual.cpp"

CMakeFiles/LocationRouting.dir/Individual.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/LocationRouting.dir/Individual.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/home/leandro/Dropbox/DOUTORADO/Computação Evolutiva/LocationRouting/Individual.cpp" > CMakeFiles/LocationRouting.dir/Individual.cpp.i

CMakeFiles/LocationRouting.dir/Individual.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/LocationRouting.dir/Individual.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/home/leandro/Dropbox/DOUTORADO/Computação Evolutiva/LocationRouting/Individual.cpp" -o CMakeFiles/LocationRouting.dir/Individual.cpp.s

CMakeFiles/LocationRouting.dir/Individual.cpp.o.requires:

.PHONY : CMakeFiles/LocationRouting.dir/Individual.cpp.o.requires

CMakeFiles/LocationRouting.dir/Individual.cpp.o.provides: CMakeFiles/LocationRouting.dir/Individual.cpp.o.requires
	$(MAKE) -f CMakeFiles/LocationRouting.dir/build.make CMakeFiles/LocationRouting.dir/Individual.cpp.o.provides.build
.PHONY : CMakeFiles/LocationRouting.dir/Individual.cpp.o.provides

CMakeFiles/LocationRouting.dir/Individual.cpp.o.provides.build: CMakeFiles/LocationRouting.dir/Individual.cpp.o


# Object files for target LocationRouting
LocationRouting_OBJECTS = \
"CMakeFiles/LocationRouting.dir/main.cpp.o" \
"CMakeFiles/LocationRouting.dir/LocationRoutingSolution.cpp.o" \
"CMakeFiles/LocationRouting.dir/LocationRoutingProblem.cpp.o" \
"CMakeFiles/LocationRouting.dir/GA.cpp.o" \
"CMakeFiles/LocationRouting.dir/AE.cpp.o" \
"CMakeFiles/LocationRouting.dir/Individual.cpp.o"

# External object files for target LocationRouting
LocationRouting_EXTERNAL_OBJECTS =

LocationRouting: CMakeFiles/LocationRouting.dir/main.cpp.o
LocationRouting: CMakeFiles/LocationRouting.dir/LocationRoutingSolution.cpp.o
LocationRouting: CMakeFiles/LocationRouting.dir/LocationRoutingProblem.cpp.o
LocationRouting: CMakeFiles/LocationRouting.dir/GA.cpp.o
LocationRouting: CMakeFiles/LocationRouting.dir/AE.cpp.o
LocationRouting: CMakeFiles/LocationRouting.dir/Individual.cpp.o
LocationRouting: CMakeFiles/LocationRouting.dir/build.make
LocationRouting: CMakeFiles/LocationRouting.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/home/leandro/Dropbox/DOUTORADO/Computação Evolutiva/LocationRouting/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable LocationRouting"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/LocationRouting.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/LocationRouting.dir/build: LocationRouting

.PHONY : CMakeFiles/LocationRouting.dir/build

CMakeFiles/LocationRouting.dir/requires: CMakeFiles/LocationRouting.dir/main.cpp.o.requires
CMakeFiles/LocationRouting.dir/requires: CMakeFiles/LocationRouting.dir/LocationRoutingSolution.cpp.o.requires
CMakeFiles/LocationRouting.dir/requires: CMakeFiles/LocationRouting.dir/LocationRoutingProblem.cpp.o.requires
CMakeFiles/LocationRouting.dir/requires: CMakeFiles/LocationRouting.dir/GA.cpp.o.requires
CMakeFiles/LocationRouting.dir/requires: CMakeFiles/LocationRouting.dir/AE.cpp.o.requires
CMakeFiles/LocationRouting.dir/requires: CMakeFiles/LocationRouting.dir/Individual.cpp.o.requires

.PHONY : CMakeFiles/LocationRouting.dir/requires

CMakeFiles/LocationRouting.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/LocationRouting.dir/cmake_clean.cmake
.PHONY : CMakeFiles/LocationRouting.dir/clean

CMakeFiles/LocationRouting.dir/depend:
	cd "/home/leandro/Dropbox/DOUTORADO/Computação Evolutiva/LocationRouting/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/home/leandro/Dropbox/DOUTORADO/Computação Evolutiva/LocationRouting" "/home/leandro/Dropbox/DOUTORADO/Computação Evolutiva/LocationRouting" "/home/leandro/Dropbox/DOUTORADO/Computação Evolutiva/LocationRouting/cmake-build-debug" "/home/leandro/Dropbox/DOUTORADO/Computação Evolutiva/LocationRouting/cmake-build-debug" "/home/leandro/Dropbox/DOUTORADO/Computação Evolutiva/LocationRouting/cmake-build-debug/CMakeFiles/LocationRouting.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/LocationRouting.dir/depend

