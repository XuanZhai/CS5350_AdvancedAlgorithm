# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_SOURCE_DIR = /mnt/c/VS-Code/Xuan-James-Zhai-CS5350/FinalProject/PartB/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/VS-Code/Xuan-James-Zhai-CS5350/FinalProject/PartB/src/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/src.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/src.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/src.dir/flags.make

CMakeFiles/src.dir/main.cpp.o: CMakeFiles/src.dir/flags.make
CMakeFiles/src.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/VS-Code/Xuan-James-Zhai-CS5350/FinalProject/PartB/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/src.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/src.dir/main.cpp.o -c /mnt/c/VS-Code/Xuan-James-Zhai-CS5350/FinalProject/PartB/src/main.cpp

CMakeFiles/src.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/VS-Code/Xuan-James-Zhai-CS5350/FinalProject/PartB/src/main.cpp > CMakeFiles/src.dir/main.cpp.i

CMakeFiles/src.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/VS-Code/Xuan-James-Zhai-CS5350/FinalProject/PartB/src/main.cpp -o CMakeFiles/src.dir/main.cpp.s

CMakeFiles/src.dir/DLLNode.cpp.o: CMakeFiles/src.dir/flags.make
CMakeFiles/src.dir/DLLNode.cpp.o: ../DLLNode.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/VS-Code/Xuan-James-Zhai-CS5350/FinalProject/PartB/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/src.dir/DLLNode.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/src.dir/DLLNode.cpp.o -c /mnt/c/VS-Code/Xuan-James-Zhai-CS5350/FinalProject/PartB/src/DLLNode.cpp

CMakeFiles/src.dir/DLLNode.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/DLLNode.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/VS-Code/Xuan-James-Zhai-CS5350/FinalProject/PartB/src/DLLNode.cpp > CMakeFiles/src.dir/DLLNode.cpp.i

CMakeFiles/src.dir/DLLNode.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/DLLNode.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/VS-Code/Xuan-James-Zhai-CS5350/FinalProject/PartB/src/DLLNode.cpp -o CMakeFiles/src.dir/DLLNode.cpp.s

CMakeFiles/src.dir/DLList.cpp.o: CMakeFiles/src.dir/flags.make
CMakeFiles/src.dir/DLList.cpp.o: ../DLList.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/VS-Code/Xuan-James-Zhai-CS5350/FinalProject/PartB/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/src.dir/DLList.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/src.dir/DLList.cpp.o -c /mnt/c/VS-Code/Xuan-James-Zhai-CS5350/FinalProject/PartB/src/DLList.cpp

CMakeFiles/src.dir/DLList.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/src.dir/DLList.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/VS-Code/Xuan-James-Zhai-CS5350/FinalProject/PartB/src/DLList.cpp > CMakeFiles/src.dir/DLList.cpp.i

CMakeFiles/src.dir/DLList.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/src.dir/DLList.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/VS-Code/Xuan-James-Zhai-CS5350/FinalProject/PartB/src/DLList.cpp -o CMakeFiles/src.dir/DLList.cpp.s

# Object files for target src
src_OBJECTS = \
"CMakeFiles/src.dir/main.cpp.o" \
"CMakeFiles/src.dir/DLLNode.cpp.o" \
"CMakeFiles/src.dir/DLList.cpp.o"

# External object files for target src
src_EXTERNAL_OBJECTS =

src: CMakeFiles/src.dir/main.cpp.o
src: CMakeFiles/src.dir/DLLNode.cpp.o
src: CMakeFiles/src.dir/DLList.cpp.o
src: CMakeFiles/src.dir/build.make
src: CMakeFiles/src.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/VS-Code/Xuan-James-Zhai-CS5350/FinalProject/PartB/src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable src"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/src.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/src.dir/build: src
.PHONY : CMakeFiles/src.dir/build

CMakeFiles/src.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/src.dir/cmake_clean.cmake
.PHONY : CMakeFiles/src.dir/clean

CMakeFiles/src.dir/depend:
	cd /mnt/c/VS-Code/Xuan-James-Zhai-CS5350/FinalProject/PartB/src/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/VS-Code/Xuan-James-Zhai-CS5350/FinalProject/PartB/src /mnt/c/VS-Code/Xuan-James-Zhai-CS5350/FinalProject/PartB/src /mnt/c/VS-Code/Xuan-James-Zhai-CS5350/FinalProject/PartB/src/cmake-build-debug /mnt/c/VS-Code/Xuan-James-Zhai-CS5350/FinalProject/PartB/src/cmake-build-debug /mnt/c/VS-Code/Xuan-James-Zhai-CS5350/FinalProject/PartB/src/cmake-build-debug/CMakeFiles/src.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/src.dir/depend
