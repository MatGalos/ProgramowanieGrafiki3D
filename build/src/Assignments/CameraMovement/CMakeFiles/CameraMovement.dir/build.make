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
include src/Assignments/CameraMovement/CMakeFiles/CameraMovement.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/Assignments/CameraMovement/CMakeFiles/CameraMovement.dir/compiler_depend.make

# Include the progress variables for this target.
include src/Assignments/CameraMovement/CMakeFiles/CameraMovement.dir/progress.make

# Include the compile flags for this target's objects.
include src/Assignments/CameraMovement/CMakeFiles/CameraMovement.dir/flags.make

src/Assignments/CameraMovement/CMakeFiles/CameraMovement.dir/codegen:
.PHONY : src/Assignments/CameraMovement/CMakeFiles/CameraMovement.dir/codegen

src/Assignments/CameraMovement/CMakeFiles/CameraMovement.dir/main.cpp.o: src/Assignments/CameraMovement/CMakeFiles/CameraMovement.dir/flags.make
src/Assignments/CameraMovement/CMakeFiles/CameraMovement.dir/main.cpp.o: /Users/mateuszgalos/uczelnia/Programowanie\ grafiki\ 3D\ zaliczenie/src/Assignments/CameraMovement/main.cpp
src/Assignments/CameraMovement/CMakeFiles/CameraMovement.dir/main.cpp.o: src/Assignments/CameraMovement/CMakeFiles/CameraMovement.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/mateuszgalos/uczelnia/Programowanie grafiki 3D zaliczenie/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/Assignments/CameraMovement/CMakeFiles/CameraMovement.dir/main.cpp.o"
	cd "/Users/mateuszgalos/uczelnia/Programowanie grafiki 3D zaliczenie/build/src/Assignments/CameraMovement" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/Assignments/CameraMovement/CMakeFiles/CameraMovement.dir/main.cpp.o -MF CMakeFiles/CameraMovement.dir/main.cpp.o.d -o CMakeFiles/CameraMovement.dir/main.cpp.o -c "/Users/mateuszgalos/uczelnia/Programowanie grafiki 3D zaliczenie/src/Assignments/CameraMovement/main.cpp"

src/Assignments/CameraMovement/CMakeFiles/CameraMovement.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/CameraMovement.dir/main.cpp.i"
	cd "/Users/mateuszgalos/uczelnia/Programowanie grafiki 3D zaliczenie/build/src/Assignments/CameraMovement" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/mateuszgalos/uczelnia/Programowanie grafiki 3D zaliczenie/src/Assignments/CameraMovement/main.cpp" > CMakeFiles/CameraMovement.dir/main.cpp.i

src/Assignments/CameraMovement/CMakeFiles/CameraMovement.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/CameraMovement.dir/main.cpp.s"
	cd "/Users/mateuszgalos/uczelnia/Programowanie grafiki 3D zaliczenie/build/src/Assignments/CameraMovement" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/mateuszgalos/uczelnia/Programowanie grafiki 3D zaliczenie/src/Assignments/CameraMovement/main.cpp" -o CMakeFiles/CameraMovement.dir/main.cpp.s

src/Assignments/CameraMovement/CMakeFiles/CameraMovement.dir/app.cpp.o: src/Assignments/CameraMovement/CMakeFiles/CameraMovement.dir/flags.make
src/Assignments/CameraMovement/CMakeFiles/CameraMovement.dir/app.cpp.o: /Users/mateuszgalos/uczelnia/Programowanie\ grafiki\ 3D\ zaliczenie/src/Assignments/CameraMovement/app.cpp
src/Assignments/CameraMovement/CMakeFiles/CameraMovement.dir/app.cpp.o: src/Assignments/CameraMovement/CMakeFiles/CameraMovement.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir="/Users/mateuszgalos/uczelnia/Programowanie grafiki 3D zaliczenie/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/Assignments/CameraMovement/CMakeFiles/CameraMovement.dir/app.cpp.o"
	cd "/Users/mateuszgalos/uczelnia/Programowanie grafiki 3D zaliczenie/build/src/Assignments/CameraMovement" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/Assignments/CameraMovement/CMakeFiles/CameraMovement.dir/app.cpp.o -MF CMakeFiles/CameraMovement.dir/app.cpp.o.d -o CMakeFiles/CameraMovement.dir/app.cpp.o -c "/Users/mateuszgalos/uczelnia/Programowanie grafiki 3D zaliczenie/src/Assignments/CameraMovement/app.cpp"

src/Assignments/CameraMovement/CMakeFiles/CameraMovement.dir/app.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/CameraMovement.dir/app.cpp.i"
	cd "/Users/mateuszgalos/uczelnia/Programowanie grafiki 3D zaliczenie/build/src/Assignments/CameraMovement" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/mateuszgalos/uczelnia/Programowanie grafiki 3D zaliczenie/src/Assignments/CameraMovement/app.cpp" > CMakeFiles/CameraMovement.dir/app.cpp.i

src/Assignments/CameraMovement/CMakeFiles/CameraMovement.dir/app.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/CameraMovement.dir/app.cpp.s"
	cd "/Users/mateuszgalos/uczelnia/Programowanie grafiki 3D zaliczenie/build/src/Assignments/CameraMovement" && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/mateuszgalos/uczelnia/Programowanie grafiki 3D zaliczenie/src/Assignments/CameraMovement/app.cpp" -o CMakeFiles/CameraMovement.dir/app.cpp.s

# Object files for target CameraMovement
CameraMovement_OBJECTS = \
"CMakeFiles/CameraMovement.dir/main.cpp.o" \
"CMakeFiles/CameraMovement.dir/app.cpp.o"

# External object files for target CameraMovement
CameraMovement_EXTERNAL_OBJECTS = \
"/Users/mateuszgalos/uczelnia/Programowanie grafiki 3D zaliczenie/build/CMakeFiles/glad.dir/src/3rdParty/glad/glad_4_1/glad/src/gl.c.o"

src/Assignments/CameraMovement/CameraMovement: src/Assignments/CameraMovement/CMakeFiles/CameraMovement.dir/main.cpp.o
src/Assignments/CameraMovement/CameraMovement: src/Assignments/CameraMovement/CMakeFiles/CameraMovement.dir/app.cpp.o
src/Assignments/CameraMovement/CameraMovement: CMakeFiles/glad.dir/src/3rdParty/glad/glad_4_1/glad/src/gl.c.o
src/Assignments/CameraMovement/CameraMovement: src/Assignments/CameraMovement/CMakeFiles/CameraMovement.dir/build.make
src/Assignments/CameraMovement/CameraMovement: /Library/Developer/CommandLineTools/SDKs/MacOSX15.1.sdk/System/Library/Frameworks/OpenGL.framework
src/Assignments/CameraMovement/CameraMovement: _deps/glfw-build/src/libglfw3.a
src/Assignments/CameraMovement/CameraMovement: _deps/glm-build/glm/libglm.a
src/Assignments/CameraMovement/CameraMovement: src/Application/libapplication.a
src/Assignments/CameraMovement/CameraMovement: _deps/spdlog-build/libspdlog.a
src/Assignments/CameraMovement/CameraMovement: src/XeEngine/libxe-engine.a
src/Assignments/CameraMovement/CameraMovement: src/ObjectReader/libobjreader.a
src/Assignments/CameraMovement/CameraMovement: /Library/Developer/CommandLineTools/SDKs/MacOSX15.1.sdk/System/Library/Frameworks/OpenGL.framework
src/Assignments/CameraMovement/CameraMovement: _deps/glfw-build/src/libglfw3.a
src/Assignments/CameraMovement/CameraMovement: _deps/glm-build/glm/libglm.a
src/Assignments/CameraMovement/CameraMovement: _deps/spdlog-build/libspdlog.a
src/Assignments/CameraMovement/CameraMovement: src/Assignments/CameraMovement/CMakeFiles/CameraMovement.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir="/Users/mateuszgalos/uczelnia/Programowanie grafiki 3D zaliczenie/build/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable CameraMovement"
	cd "/Users/mateuszgalos/uczelnia/Programowanie grafiki 3D zaliczenie/build/src/Assignments/CameraMovement" && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CameraMovement.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/Assignments/CameraMovement/CMakeFiles/CameraMovement.dir/build: src/Assignments/CameraMovement/CameraMovement
.PHONY : src/Assignments/CameraMovement/CMakeFiles/CameraMovement.dir/build

src/Assignments/CameraMovement/CMakeFiles/CameraMovement.dir/clean:
	cd "/Users/mateuszgalos/uczelnia/Programowanie grafiki 3D zaliczenie/build/src/Assignments/CameraMovement" && $(CMAKE_COMMAND) -P CMakeFiles/CameraMovement.dir/cmake_clean.cmake
.PHONY : src/Assignments/CameraMovement/CMakeFiles/CameraMovement.dir/clean

src/Assignments/CameraMovement/CMakeFiles/CameraMovement.dir/depend:
	cd "/Users/mateuszgalos/uczelnia/Programowanie grafiki 3D zaliczenie/build" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/mateuszgalos/uczelnia/Programowanie grafiki 3D zaliczenie" "/Users/mateuszgalos/uczelnia/Programowanie grafiki 3D zaliczenie/src/Assignments/CameraMovement" "/Users/mateuszgalos/uczelnia/Programowanie grafiki 3D zaliczenie/build" "/Users/mateuszgalos/uczelnia/Programowanie grafiki 3D zaliczenie/build/src/Assignments/CameraMovement" "/Users/mateuszgalos/uczelnia/Programowanie grafiki 3D zaliczenie/build/src/Assignments/CameraMovement/CMakeFiles/CameraMovement.dir/DependInfo.cmake" "--color=$(COLOR)"
.PHONY : src/Assignments/CameraMovement/CMakeFiles/CameraMovement.dir/depend

