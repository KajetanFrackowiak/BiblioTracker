# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /home/kajetan/.local/share/JetBrains/Toolbox/apps/clion-nova/bin/cmake/linux/x64/bin/cmake

# The command to remove a file.
RM = /home/kajetan/.local/share/JetBrains/Toolbox/apps/clion-nova/bin/cmake/linux/x64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kajetan/CLionProjects/BiblioTracker/BiblioTracker

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kajetan/CLionProjects/BiblioTracker/BiblioTracker/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/projectCpp.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/projectCpp.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/projectCpp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/projectCpp.dir/flags.make

CMakeFiles/projectCpp.dir/main.cpp.o: CMakeFiles/projectCpp.dir/flags.make
CMakeFiles/projectCpp.dir/main.cpp.o: /home/kajetan/CLionProjects/BiblioTracker/BiblioTracker/main.cpp
CMakeFiles/projectCpp.dir/main.cpp.o: CMakeFiles/projectCpp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/kajetan/CLionProjects/BiblioTracker/BiblioTracker/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/projectCpp.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/projectCpp.dir/main.cpp.o -MF CMakeFiles/projectCpp.dir/main.cpp.o.d -o CMakeFiles/projectCpp.dir/main.cpp.o -c /home/kajetan/CLionProjects/BiblioTracker/BiblioTracker/main.cpp

CMakeFiles/projectCpp.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/projectCpp.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kajetan/CLionProjects/BiblioTracker/BiblioTracker/main.cpp > CMakeFiles/projectCpp.dir/main.cpp.i

CMakeFiles/projectCpp.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/projectCpp.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kajetan/CLionProjects/BiblioTracker/BiblioTracker/main.cpp -o CMakeFiles/projectCpp.dir/main.cpp.s

CMakeFiles/projectCpp.dir/DateChecker.cpp.o: CMakeFiles/projectCpp.dir/flags.make
CMakeFiles/projectCpp.dir/DateChecker.cpp.o: /home/kajetan/CLionProjects/BiblioTracker/BiblioTracker/DateChecker.cpp
CMakeFiles/projectCpp.dir/DateChecker.cpp.o: CMakeFiles/projectCpp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/kajetan/CLionProjects/BiblioTracker/BiblioTracker/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/projectCpp.dir/DateChecker.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/projectCpp.dir/DateChecker.cpp.o -MF CMakeFiles/projectCpp.dir/DateChecker.cpp.o.d -o CMakeFiles/projectCpp.dir/DateChecker.cpp.o -c /home/kajetan/CLionProjects/BiblioTracker/BiblioTracker/DateChecker.cpp

CMakeFiles/projectCpp.dir/DateChecker.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/projectCpp.dir/DateChecker.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kajetan/CLionProjects/BiblioTracker/BiblioTracker/DateChecker.cpp > CMakeFiles/projectCpp.dir/DateChecker.cpp.i

CMakeFiles/projectCpp.dir/DateChecker.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/projectCpp.dir/DateChecker.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kajetan/CLionProjects/BiblioTracker/BiblioTracker/DateChecker.cpp -o CMakeFiles/projectCpp.dir/DateChecker.cpp.s

CMakeFiles/projectCpp.dir/BibliographyRecord.cpp.o: CMakeFiles/projectCpp.dir/flags.make
CMakeFiles/projectCpp.dir/BibliographyRecord.cpp.o: /home/kajetan/CLionProjects/BiblioTracker/BiblioTracker/BibliographyRecord.cpp
CMakeFiles/projectCpp.dir/BibliographyRecord.cpp.o: CMakeFiles/projectCpp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/kajetan/CLionProjects/BiblioTracker/BiblioTracker/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/projectCpp.dir/BibliographyRecord.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/projectCpp.dir/BibliographyRecord.cpp.o -MF CMakeFiles/projectCpp.dir/BibliographyRecord.cpp.o.d -o CMakeFiles/projectCpp.dir/BibliographyRecord.cpp.o -c /home/kajetan/CLionProjects/BiblioTracker/BiblioTracker/BibliographyRecord.cpp

CMakeFiles/projectCpp.dir/BibliographyRecord.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/projectCpp.dir/BibliographyRecord.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kajetan/CLionProjects/BiblioTracker/BiblioTracker/BibliographyRecord.cpp > CMakeFiles/projectCpp.dir/BibliographyRecord.cpp.i

CMakeFiles/projectCpp.dir/BibliographyRecord.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/projectCpp.dir/BibliographyRecord.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kajetan/CLionProjects/BiblioTracker/BiblioTracker/BibliographyRecord.cpp -o CMakeFiles/projectCpp.dir/BibliographyRecord.cpp.s

CMakeFiles/projectCpp.dir/Color.cpp.o: CMakeFiles/projectCpp.dir/flags.make
CMakeFiles/projectCpp.dir/Color.cpp.o: /home/kajetan/CLionProjects/BiblioTracker/BiblioTracker/Color.cpp
CMakeFiles/projectCpp.dir/Color.cpp.o: CMakeFiles/projectCpp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/kajetan/CLionProjects/BiblioTracker/BiblioTracker/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/projectCpp.dir/Color.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/projectCpp.dir/Color.cpp.o -MF CMakeFiles/projectCpp.dir/Color.cpp.o.d -o CMakeFiles/projectCpp.dir/Color.cpp.o -c /home/kajetan/CLionProjects/BiblioTracker/BiblioTracker/Color.cpp

CMakeFiles/projectCpp.dir/Color.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/projectCpp.dir/Color.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kajetan/CLionProjects/BiblioTracker/BiblioTracker/Color.cpp > CMakeFiles/projectCpp.dir/Color.cpp.i

CMakeFiles/projectCpp.dir/Color.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/projectCpp.dir/Color.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kajetan/CLionProjects/BiblioTracker/BiblioTracker/Color.cpp -o CMakeFiles/projectCpp.dir/Color.cpp.s

CMakeFiles/projectCpp.dir/BibliographyManager.cpp.o: CMakeFiles/projectCpp.dir/flags.make
CMakeFiles/projectCpp.dir/BibliographyManager.cpp.o: /home/kajetan/CLionProjects/BiblioTracker/BiblioTracker/BibliographyManager.cpp
CMakeFiles/projectCpp.dir/BibliographyManager.cpp.o: CMakeFiles/projectCpp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/kajetan/CLionProjects/BiblioTracker/BiblioTracker/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/projectCpp.dir/BibliographyManager.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/projectCpp.dir/BibliographyManager.cpp.o -MF CMakeFiles/projectCpp.dir/BibliographyManager.cpp.o.d -o CMakeFiles/projectCpp.dir/BibliographyManager.cpp.o -c /home/kajetan/CLionProjects/BiblioTracker/BiblioTracker/BibliographyManager.cpp

CMakeFiles/projectCpp.dir/BibliographyManager.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/projectCpp.dir/BibliographyManager.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kajetan/CLionProjects/BiblioTracker/BiblioTracker/BibliographyManager.cpp > CMakeFiles/projectCpp.dir/BibliographyManager.cpp.i

CMakeFiles/projectCpp.dir/BibliographyManager.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/projectCpp.dir/BibliographyManager.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kajetan/CLionProjects/BiblioTracker/BiblioTracker/BibliographyManager.cpp -o CMakeFiles/projectCpp.dir/BibliographyManager.cpp.s

# Object files for target projectCpp
projectCpp_OBJECTS = \
"CMakeFiles/projectCpp.dir/main.cpp.o" \
"CMakeFiles/projectCpp.dir/DateChecker.cpp.o" \
"CMakeFiles/projectCpp.dir/BibliographyRecord.cpp.o" \
"CMakeFiles/projectCpp.dir/Color.cpp.o" \
"CMakeFiles/projectCpp.dir/BibliographyManager.cpp.o"

# External object files for target projectCpp
projectCpp_EXTERNAL_OBJECTS =

projectCpp: CMakeFiles/projectCpp.dir/main.cpp.o
projectCpp: CMakeFiles/projectCpp.dir/DateChecker.cpp.o
projectCpp: CMakeFiles/projectCpp.dir/BibliographyRecord.cpp.o
projectCpp: CMakeFiles/projectCpp.dir/Color.cpp.o
projectCpp: CMakeFiles/projectCpp.dir/BibliographyManager.cpp.o
projectCpp: CMakeFiles/projectCpp.dir/build.make
projectCpp: CMakeFiles/projectCpp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/kajetan/CLionProjects/BiblioTracker/BiblioTracker/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable projectCpp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/projectCpp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/projectCpp.dir/build: projectCpp
.PHONY : CMakeFiles/projectCpp.dir/build

CMakeFiles/projectCpp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/projectCpp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/projectCpp.dir/clean

CMakeFiles/projectCpp.dir/depend:
	cd /home/kajetan/CLionProjects/BiblioTracker/BiblioTracker/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kajetan/CLionProjects/BiblioTracker/BiblioTracker /home/kajetan/CLionProjects/BiblioTracker/BiblioTracker /home/kajetan/CLionProjects/BiblioTracker/BiblioTracker/cmake-build-debug /home/kajetan/CLionProjects/BiblioTracker/BiblioTracker/cmake-build-debug /home/kajetan/CLionProjects/BiblioTracker/BiblioTracker/cmake-build-debug/CMakeFiles/projectCpp.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/projectCpp.dir/depend

