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
CMAKE_SOURCE_DIR = /home/bolgarin/workspace/code/Sound_Processor

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bolgarin/workspace/code/Sound_Processor/build

# Include any dependencies generated for this target.
include CMakeFiles/converter_lib.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/converter_lib.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/converter_lib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/converter_lib.dir/flags.make

CMakeFiles/converter_lib.dir/src/base/converter/dist_converter.cpp.o: CMakeFiles/converter_lib.dir/flags.make
CMakeFiles/converter_lib.dir/src/base/converter/dist_converter.cpp.o: ../src/base/converter/dist_converter.cpp
CMakeFiles/converter_lib.dir/src/base/converter/dist_converter.cpp.o: CMakeFiles/converter_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bolgarin/workspace/code/Sound_Processor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/converter_lib.dir/src/base/converter/dist_converter.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/converter_lib.dir/src/base/converter/dist_converter.cpp.o -MF CMakeFiles/converter_lib.dir/src/base/converter/dist_converter.cpp.o.d -o CMakeFiles/converter_lib.dir/src/base/converter/dist_converter.cpp.o -c /home/bolgarin/workspace/code/Sound_Processor/src/base/converter/dist_converter.cpp

CMakeFiles/converter_lib.dir/src/base/converter/dist_converter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/converter_lib.dir/src/base/converter/dist_converter.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bolgarin/workspace/code/Sound_Processor/src/base/converter/dist_converter.cpp > CMakeFiles/converter_lib.dir/src/base/converter/dist_converter.cpp.i

CMakeFiles/converter_lib.dir/src/base/converter/dist_converter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/converter_lib.dir/src/base/converter/dist_converter.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bolgarin/workspace/code/Sound_Processor/src/base/converter/dist_converter.cpp -o CMakeFiles/converter_lib.dir/src/base/converter/dist_converter.cpp.s

CMakeFiles/converter_lib.dir/src/base/converter/factory/dist_converter_factory.cpp.o: CMakeFiles/converter_lib.dir/flags.make
CMakeFiles/converter_lib.dir/src/base/converter/factory/dist_converter_factory.cpp.o: ../src/base/converter/factory/dist_converter_factory.cpp
CMakeFiles/converter_lib.dir/src/base/converter/factory/dist_converter_factory.cpp.o: CMakeFiles/converter_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bolgarin/workspace/code/Sound_Processor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/converter_lib.dir/src/base/converter/factory/dist_converter_factory.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/converter_lib.dir/src/base/converter/factory/dist_converter_factory.cpp.o -MF CMakeFiles/converter_lib.dir/src/base/converter/factory/dist_converter_factory.cpp.o.d -o CMakeFiles/converter_lib.dir/src/base/converter/factory/dist_converter_factory.cpp.o -c /home/bolgarin/workspace/code/Sound_Processor/src/base/converter/factory/dist_converter_factory.cpp

CMakeFiles/converter_lib.dir/src/base/converter/factory/dist_converter_factory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/converter_lib.dir/src/base/converter/factory/dist_converter_factory.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bolgarin/workspace/code/Sound_Processor/src/base/converter/factory/dist_converter_factory.cpp > CMakeFiles/converter_lib.dir/src/base/converter/factory/dist_converter_factory.cpp.i

CMakeFiles/converter_lib.dir/src/base/converter/factory/dist_converter_factory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/converter_lib.dir/src/base/converter/factory/dist_converter_factory.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bolgarin/workspace/code/Sound_Processor/src/base/converter/factory/dist_converter_factory.cpp -o CMakeFiles/converter_lib.dir/src/base/converter/factory/dist_converter_factory.cpp.s

CMakeFiles/converter_lib.dir/src/base/converter/factory/mix_converter_factory.cpp.o: CMakeFiles/converter_lib.dir/flags.make
CMakeFiles/converter_lib.dir/src/base/converter/factory/mix_converter_factory.cpp.o: ../src/base/converter/factory/mix_converter_factory.cpp
CMakeFiles/converter_lib.dir/src/base/converter/factory/mix_converter_factory.cpp.o: CMakeFiles/converter_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bolgarin/workspace/code/Sound_Processor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/converter_lib.dir/src/base/converter/factory/mix_converter_factory.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/converter_lib.dir/src/base/converter/factory/mix_converter_factory.cpp.o -MF CMakeFiles/converter_lib.dir/src/base/converter/factory/mix_converter_factory.cpp.o.d -o CMakeFiles/converter_lib.dir/src/base/converter/factory/mix_converter_factory.cpp.o -c /home/bolgarin/workspace/code/Sound_Processor/src/base/converter/factory/mix_converter_factory.cpp

CMakeFiles/converter_lib.dir/src/base/converter/factory/mix_converter_factory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/converter_lib.dir/src/base/converter/factory/mix_converter_factory.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bolgarin/workspace/code/Sound_Processor/src/base/converter/factory/mix_converter_factory.cpp > CMakeFiles/converter_lib.dir/src/base/converter/factory/mix_converter_factory.cpp.i

CMakeFiles/converter_lib.dir/src/base/converter/factory/mix_converter_factory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/converter_lib.dir/src/base/converter/factory/mix_converter_factory.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bolgarin/workspace/code/Sound_Processor/src/base/converter/factory/mix_converter_factory.cpp -o CMakeFiles/converter_lib.dir/src/base/converter/factory/mix_converter_factory.cpp.s

CMakeFiles/converter_lib.dir/src/base/converter/factory/mute_converter_factory.cpp.o: CMakeFiles/converter_lib.dir/flags.make
CMakeFiles/converter_lib.dir/src/base/converter/factory/mute_converter_factory.cpp.o: ../src/base/converter/factory/mute_converter_factory.cpp
CMakeFiles/converter_lib.dir/src/base/converter/factory/mute_converter_factory.cpp.o: CMakeFiles/converter_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bolgarin/workspace/code/Sound_Processor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/converter_lib.dir/src/base/converter/factory/mute_converter_factory.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/converter_lib.dir/src/base/converter/factory/mute_converter_factory.cpp.o -MF CMakeFiles/converter_lib.dir/src/base/converter/factory/mute_converter_factory.cpp.o.d -o CMakeFiles/converter_lib.dir/src/base/converter/factory/mute_converter_factory.cpp.o -c /home/bolgarin/workspace/code/Sound_Processor/src/base/converter/factory/mute_converter_factory.cpp

CMakeFiles/converter_lib.dir/src/base/converter/factory/mute_converter_factory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/converter_lib.dir/src/base/converter/factory/mute_converter_factory.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bolgarin/workspace/code/Sound_Processor/src/base/converter/factory/mute_converter_factory.cpp > CMakeFiles/converter_lib.dir/src/base/converter/factory/mute_converter_factory.cpp.i

CMakeFiles/converter_lib.dir/src/base/converter/factory/mute_converter_factory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/converter_lib.dir/src/base/converter/factory/mute_converter_factory.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bolgarin/workspace/code/Sound_Processor/src/base/converter/factory/mute_converter_factory.cpp -o CMakeFiles/converter_lib.dir/src/base/converter/factory/mute_converter_factory.cpp.s

CMakeFiles/converter_lib.dir/src/base/converter/mix_converter.cpp.o: CMakeFiles/converter_lib.dir/flags.make
CMakeFiles/converter_lib.dir/src/base/converter/mix_converter.cpp.o: ../src/base/converter/mix_converter.cpp
CMakeFiles/converter_lib.dir/src/base/converter/mix_converter.cpp.o: CMakeFiles/converter_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bolgarin/workspace/code/Sound_Processor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/converter_lib.dir/src/base/converter/mix_converter.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/converter_lib.dir/src/base/converter/mix_converter.cpp.o -MF CMakeFiles/converter_lib.dir/src/base/converter/mix_converter.cpp.o.d -o CMakeFiles/converter_lib.dir/src/base/converter/mix_converter.cpp.o -c /home/bolgarin/workspace/code/Sound_Processor/src/base/converter/mix_converter.cpp

CMakeFiles/converter_lib.dir/src/base/converter/mix_converter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/converter_lib.dir/src/base/converter/mix_converter.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bolgarin/workspace/code/Sound_Processor/src/base/converter/mix_converter.cpp > CMakeFiles/converter_lib.dir/src/base/converter/mix_converter.cpp.i

CMakeFiles/converter_lib.dir/src/base/converter/mix_converter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/converter_lib.dir/src/base/converter/mix_converter.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bolgarin/workspace/code/Sound_Processor/src/base/converter/mix_converter.cpp -o CMakeFiles/converter_lib.dir/src/base/converter/mix_converter.cpp.s

CMakeFiles/converter_lib.dir/src/base/converter/mute_converter.cpp.o: CMakeFiles/converter_lib.dir/flags.make
CMakeFiles/converter_lib.dir/src/base/converter/mute_converter.cpp.o: ../src/base/converter/mute_converter.cpp
CMakeFiles/converter_lib.dir/src/base/converter/mute_converter.cpp.o: CMakeFiles/converter_lib.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bolgarin/workspace/code/Sound_Processor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/converter_lib.dir/src/base/converter/mute_converter.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/converter_lib.dir/src/base/converter/mute_converter.cpp.o -MF CMakeFiles/converter_lib.dir/src/base/converter/mute_converter.cpp.o.d -o CMakeFiles/converter_lib.dir/src/base/converter/mute_converter.cpp.o -c /home/bolgarin/workspace/code/Sound_Processor/src/base/converter/mute_converter.cpp

CMakeFiles/converter_lib.dir/src/base/converter/mute_converter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/converter_lib.dir/src/base/converter/mute_converter.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bolgarin/workspace/code/Sound_Processor/src/base/converter/mute_converter.cpp > CMakeFiles/converter_lib.dir/src/base/converter/mute_converter.cpp.i

CMakeFiles/converter_lib.dir/src/base/converter/mute_converter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/converter_lib.dir/src/base/converter/mute_converter.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bolgarin/workspace/code/Sound_Processor/src/base/converter/mute_converter.cpp -o CMakeFiles/converter_lib.dir/src/base/converter/mute_converter.cpp.s

# Object files for target converter_lib
converter_lib_OBJECTS = \
"CMakeFiles/converter_lib.dir/src/base/converter/dist_converter.cpp.o" \
"CMakeFiles/converter_lib.dir/src/base/converter/factory/dist_converter_factory.cpp.o" \
"CMakeFiles/converter_lib.dir/src/base/converter/factory/mix_converter_factory.cpp.o" \
"CMakeFiles/converter_lib.dir/src/base/converter/factory/mute_converter_factory.cpp.o" \
"CMakeFiles/converter_lib.dir/src/base/converter/mix_converter.cpp.o" \
"CMakeFiles/converter_lib.dir/src/base/converter/mute_converter.cpp.o"

# External object files for target converter_lib
converter_lib_EXTERNAL_OBJECTS =

libconverter_lib.a: CMakeFiles/converter_lib.dir/src/base/converter/dist_converter.cpp.o
libconverter_lib.a: CMakeFiles/converter_lib.dir/src/base/converter/factory/dist_converter_factory.cpp.o
libconverter_lib.a: CMakeFiles/converter_lib.dir/src/base/converter/factory/mix_converter_factory.cpp.o
libconverter_lib.a: CMakeFiles/converter_lib.dir/src/base/converter/factory/mute_converter_factory.cpp.o
libconverter_lib.a: CMakeFiles/converter_lib.dir/src/base/converter/mix_converter.cpp.o
libconverter_lib.a: CMakeFiles/converter_lib.dir/src/base/converter/mute_converter.cpp.o
libconverter_lib.a: CMakeFiles/converter_lib.dir/build.make
libconverter_lib.a: CMakeFiles/converter_lib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bolgarin/workspace/code/Sound_Processor/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX static library libconverter_lib.a"
	$(CMAKE_COMMAND) -P CMakeFiles/converter_lib.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/converter_lib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/converter_lib.dir/build: libconverter_lib.a
.PHONY : CMakeFiles/converter_lib.dir/build

CMakeFiles/converter_lib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/converter_lib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/converter_lib.dir/clean

CMakeFiles/converter_lib.dir/depend:
	cd /home/bolgarin/workspace/code/Sound_Processor/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bolgarin/workspace/code/Sound_Processor /home/bolgarin/workspace/code/Sound_Processor /home/bolgarin/workspace/code/Sound_Processor/build /home/bolgarin/workspace/code/Sound_Processor/build /home/bolgarin/workspace/code/Sound_Processor/build/CMakeFiles/converter_lib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/converter_lib.dir/depend
