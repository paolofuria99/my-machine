# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/paolo/myMachine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/paolo/myMachine/build

# Include any dependencies generated for this target.
include tests/CMakeFiles/catch2Test.dir/depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/catch2Test.dir/progress.make

# Include the compile flags for this target's objects.
include tests/CMakeFiles/catch2Test.dir/flags.make

tests/CMakeFiles/catch2Test.dir/catch2Main.cpp.o: tests/CMakeFiles/catch2Test.dir/flags.make
tests/CMakeFiles/catch2Test.dir/catch2Main.cpp.o: ../tests/catch2Main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/paolo/myMachine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tests/CMakeFiles/catch2Test.dir/catch2Main.cpp.o"
	cd /home/paolo/myMachine/build/tests && /bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/catch2Test.dir/catch2Main.cpp.o -c /home/paolo/myMachine/tests/catch2Main.cpp

tests/CMakeFiles/catch2Test.dir/catch2Main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/catch2Test.dir/catch2Main.cpp.i"
	cd /home/paolo/myMachine/build/tests && /bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/paolo/myMachine/tests/catch2Main.cpp > CMakeFiles/catch2Test.dir/catch2Main.cpp.i

tests/CMakeFiles/catch2Test.dir/catch2Main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/catch2Test.dir/catch2Main.cpp.s"
	cd /home/paolo/myMachine/build/tests && /bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/paolo/myMachine/tests/catch2Main.cpp -o CMakeFiles/catch2Test.dir/catch2Main.cpp.s

tests/CMakeFiles/catch2Test.dir/testMyHomework.cpp.o: tests/CMakeFiles/catch2Test.dir/flags.make
tests/CMakeFiles/catch2Test.dir/testMyHomework.cpp.o: ../tests/testMyHomework.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/paolo/myMachine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object tests/CMakeFiles/catch2Test.dir/testMyHomework.cpp.o"
	cd /home/paolo/myMachine/build/tests && /bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/catch2Test.dir/testMyHomework.cpp.o -c /home/paolo/myMachine/tests/testMyHomework.cpp

tests/CMakeFiles/catch2Test.dir/testMyHomework.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/catch2Test.dir/testMyHomework.cpp.i"
	cd /home/paolo/myMachine/build/tests && /bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/paolo/myMachine/tests/testMyHomework.cpp > CMakeFiles/catch2Test.dir/testMyHomework.cpp.i

tests/CMakeFiles/catch2Test.dir/testMyHomework.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/catch2Test.dir/testMyHomework.cpp.s"
	cd /home/paolo/myMachine/build/tests && /bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/paolo/myMachine/tests/testMyHomework.cpp -o CMakeFiles/catch2Test.dir/testMyHomework.cpp.s

tests/CMakeFiles/catch2Test.dir/__/src/lever.cpp.o: tests/CMakeFiles/catch2Test.dir/flags.make
tests/CMakeFiles/catch2Test.dir/__/src/lever.cpp.o: ../src/lever.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/paolo/myMachine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object tests/CMakeFiles/catch2Test.dir/__/src/lever.cpp.o"
	cd /home/paolo/myMachine/build/tests && /bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/catch2Test.dir/__/src/lever.cpp.o -c /home/paolo/myMachine/src/lever.cpp

tests/CMakeFiles/catch2Test.dir/__/src/lever.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/catch2Test.dir/__/src/lever.cpp.i"
	cd /home/paolo/myMachine/build/tests && /bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/paolo/myMachine/src/lever.cpp > CMakeFiles/catch2Test.dir/__/src/lever.cpp.i

tests/CMakeFiles/catch2Test.dir/__/src/lever.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/catch2Test.dir/__/src/lever.cpp.s"
	cd /home/paolo/myMachine/build/tests && /bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/paolo/myMachine/src/lever.cpp -o CMakeFiles/catch2Test.dir/__/src/lever.cpp.s

tests/CMakeFiles/catch2Test.dir/__/src/EB_Device.cpp.o: tests/CMakeFiles/catch2Test.dir/flags.make
tests/CMakeFiles/catch2Test.dir/__/src/EB_Device.cpp.o: ../src/EB_Device.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/paolo/myMachine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object tests/CMakeFiles/catch2Test.dir/__/src/EB_Device.cpp.o"
	cd /home/paolo/myMachine/build/tests && /bin/x86_64-linux-gnu-g++-9  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/catch2Test.dir/__/src/EB_Device.cpp.o -c /home/paolo/myMachine/src/EB_Device.cpp

tests/CMakeFiles/catch2Test.dir/__/src/EB_Device.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/catch2Test.dir/__/src/EB_Device.cpp.i"
	cd /home/paolo/myMachine/build/tests && /bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/paolo/myMachine/src/EB_Device.cpp > CMakeFiles/catch2Test.dir/__/src/EB_Device.cpp.i

tests/CMakeFiles/catch2Test.dir/__/src/EB_Device.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/catch2Test.dir/__/src/EB_Device.cpp.s"
	cd /home/paolo/myMachine/build/tests && /bin/x86_64-linux-gnu-g++-9 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/paolo/myMachine/src/EB_Device.cpp -o CMakeFiles/catch2Test.dir/__/src/EB_Device.cpp.s

# Object files for target catch2Test
catch2Test_OBJECTS = \
"CMakeFiles/catch2Test.dir/catch2Main.cpp.o" \
"CMakeFiles/catch2Test.dir/testMyHomework.cpp.o" \
"CMakeFiles/catch2Test.dir/__/src/lever.cpp.o" \
"CMakeFiles/catch2Test.dir/__/src/EB_Device.cpp.o"

# External object files for target catch2Test
catch2Test_EXTERNAL_OBJECTS =

../bin/catch2Test: tests/CMakeFiles/catch2Test.dir/catch2Main.cpp.o
../bin/catch2Test: tests/CMakeFiles/catch2Test.dir/testMyHomework.cpp.o
../bin/catch2Test: tests/CMakeFiles/catch2Test.dir/__/src/lever.cpp.o
../bin/catch2Test: tests/CMakeFiles/catch2Test.dir/__/src/EB_Device.cpp.o
../bin/catch2Test: tests/CMakeFiles/catch2Test.dir/build.make
../bin/catch2Test: tests/CMakeFiles/catch2Test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/paolo/myMachine/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX executable ../../bin/catch2Test"
	cd /home/paolo/myMachine/build/tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/catch2Test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tests/CMakeFiles/catch2Test.dir/build: ../bin/catch2Test

.PHONY : tests/CMakeFiles/catch2Test.dir/build

tests/CMakeFiles/catch2Test.dir/clean:
	cd /home/paolo/myMachine/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/catch2Test.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/catch2Test.dir/clean

tests/CMakeFiles/catch2Test.dir/depend:
	cd /home/paolo/myMachine/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/paolo/myMachine /home/paolo/myMachine/tests /home/paolo/myMachine/build /home/paolo/myMachine/build/tests /home/paolo/myMachine/build/tests/CMakeFiles/catch2Test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/catch2Test.dir/depend

