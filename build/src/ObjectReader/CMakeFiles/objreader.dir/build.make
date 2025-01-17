# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.31

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
CMAKE_COMMAND = /opt/homebrew/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/mateuszgalos/uczelnia/Programowanie grafiki 3D zaliczenie"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/mateuszgalos/uczelnia/Programowanie grafiki 3D zaliczenie/build"

# Include any dependencies generated for this target.
include src/ObjectReader/CMakeFiles/objreader.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/ObjectReader/CMakeFiles/objreader.dir/compiler_depend.make

# Include the progress variables for this target.
include src/ObjectReader/CMakeFiles/objreader.dir/progress.make

# Include the compile flags for this target's objects.
include src/ObjectReader/CMakeFiles/objreader.dir/flags.make

src/ObjectReader/CMakeFiles/objreader.dir/codegen:
.PHONY : src/ObjectReader/CMakeFiles/objreader.dir/codegen

src/ObjectReader/CMakeFiles/objreader.dir/obj_reader.cpp.o: src/ObjectReader/CMakeFiles/objreader.dir/flags.make
src/ObjectReader/CMakeFiles/objreader.dir/obj_reader.cpp.o: /Users/mateuszgalos/uczelnia/Programowanie\ grafiki\ 3D\ zaliczenie/src/ObjectReader/obj_reader.cpp
src/ObjectReader/CMakeFiles/objreader.dir/obj_reader.cpp.o: src/ObjectReader/CMakeFiles/objreader.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/mateuszgalos/uczelnia/Programowanie grafiki 3D zaliczenie/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/ObjectReader/CMakeFiles/objreader.dir/obj_reader.cpp.o"
	cd "/Users/mateuszgalos/uczelnia/Programowanie grafiki 3D zaliczenie/build/src/ObjectReader" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/ObjectReader/CMakeFiles/objreader.dir/obj_reader.cpp.o -MF CMakeFiles/objreader.dir/obj_reader.cpp.o.d -o CMakeFiles/objreader.dir/obj_reader.cpp.o -c "/Users/mateuszgalos/uczelnia/Programowanie grafiki 3D zaliczenie/src/ObjectReader/obj_reader.cpp"

src/ObjectReader/CMakeFiles/objreader.dir/obj_reader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/objreader.dir/obj_reader.cpp.i"
	cd "/Users/mateuszgalos/uczelnia/Programowanie grafiki 3D zaliczenie/build/src/ObjectReader" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/mateuszgalos/uczelnia/Programowanie grafiki 3D zaliczenie/src/ObjectReader/obj_reader.cpp" > CMakeFiles/objreader.dir/obj_reader.cpp.i

src/ObjectReader/CMakeFiles/objreader.dir/obj_reader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/objreader.dir/obj_reader.cpp.s"
	cd "/Users/mateuszgalos/uczelnia/Programowanie grafiki 3D zaliczenie/build/src/ObjectReader" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/mateuszgalos/uczelnia/Programowanie grafiki 3D zaliczenie/src/ObjectReader/obj_reader.cpp" -o CMakeFiles/objreader.dir/obj_reader.cpp.s

# Object files for target objreader
objreader_OBJECTS = \
"CMakeFiles/objreader.dir/obj_reader.cpp.o"

# External object files for target objreader
objreader_EXTERNAL_OBJECTS = \
"/Users/mateuszgalos/uczelnia/Programowanie grafiki 3D zaliczenie/build/CMakeFiles/glad.dir/src/3rdParty/glad/glad_4_1/glad/src/gl.c.o"

src/ObjectReader/libobjreader.a: src/ObjectReader/CMakeFiles/objreader.dir/obj_reader.cpp.o
src/ObjectReader/libobjreader.a: CMakeFiles/glad.dir/src/3rdParty/glad/glad_4_1/glad/src/gl.c.o
src/ObjectReader/libobjreader.a: src/ObjectReader/CMakeFiles/objreader.dir/build.make
src/ObjectReader/libobjreader.a: src/ObjectReader/CMakeFiles/objreader.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/Users/mateuszgalos/uczelnia/Programowanie grafiki 3D zaliczenie/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libobjreader.a"
	cd "/Users/mateuszgalos/uczelnia/Programowanie grafiki 3D zaliczenie/build/src/ObjectReader" && $(CMAKE_COMMAND) -P CMakeFiles/objreader.dir/cmake_clean_target.cmake
	cd "/Users/mateuszgalos/uczelnia/Programowanie grafiki 3D zaliczenie/build/src/ObjectReader" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/objreader.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/ObjectReader/CMakeFiles/objreader.dir/build: src/ObjectReader/libobjreader.a
.PHONY : src/ObjectReader/CMakeFiles/objreader.dir/build

src/ObjectReader/CMakeFiles/objreader.dir/clean:
	cd "/Users/mateuszgalos/uczelnia/Programowanie grafiki 3D zaliczenie/build/src/ObjectReader" && $(CMAKE_COMMAND) -P CMakeFiles/objreader.dir/cmake_clean.cmake
.PHONY : src/ObjectReader/CMakeFiles/objreader.dir/clean

src/ObjectReader/CMakeFiles/objreader.dir/depend:
	cd "/Users/mateuszgalos/uczelnia/Programowanie grafiki 3D zaliczenie/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/mateuszgalos/uczelnia/Programowanie grafiki 3D zaliczenie" "/Users/mateuszgalos/uczelnia/Programowanie grafiki 3D zaliczenie/src/ObjectReader" "/Users/mateuszgalos/uczelnia/Programowanie grafiki 3D zaliczenie/build" "/Users/mateuszgalos/uczelnia/Programowanie grafiki 3D zaliczenie/build/src/ObjectReader" "/Users/mateuszgalos/uczelnia/Programowanie grafiki 3D zaliczenie/build/src/ObjectReader/CMakeFiles/objreader.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : src/ObjectReader/CMakeFiles/objreader.dir/depend

