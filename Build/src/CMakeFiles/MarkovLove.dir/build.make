# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.5

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files (x86)\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files (x86)\CMake\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Amalie\Desktop\GJ_Nov\MarkovLove\Trunk

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Amalie\Desktop\GJ_Nov\MarkovLove\Build

# Include any dependencies generated for this target.
include src/CMakeFiles/MarkovLove.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/MarkovLove.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/MarkovLove.dir/flags.make

src/CMakeFiles/MarkovLove.dir/main.cpp.obj: src/CMakeFiles/MarkovLove.dir/flags.make
src/CMakeFiles/MarkovLove.dir/main.cpp.obj: src/CMakeFiles/MarkovLove.dir/includes_CXX.rsp
src/CMakeFiles/MarkovLove.dir/main.cpp.obj: C:/Users/Amalie/Desktop/GJ_Nov/MarkovLove/Trunk/src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Amalie\Desktop\GJ_Nov\MarkovLove\Build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/MarkovLove.dir/main.cpp.obj"
	cd /d C:\Users\Amalie\Desktop\GJ_Nov\MarkovLove\Build\src && C:\PROGRA~2\mingw32\bin\G__~1.EXE   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\MarkovLove.dir\main.cpp.obj -c C:\Users\Amalie\Desktop\GJ_Nov\MarkovLove\Trunk\src\main.cpp

src/CMakeFiles/MarkovLove.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MarkovLove.dir/main.cpp.i"
	cd /d C:\Users\Amalie\Desktop\GJ_Nov\MarkovLove\Build\src && C:\PROGRA~2\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Amalie\Desktop\GJ_Nov\MarkovLove\Trunk\src\main.cpp > CMakeFiles\MarkovLove.dir\main.cpp.i

src/CMakeFiles/MarkovLove.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MarkovLove.dir/main.cpp.s"
	cd /d C:\Users\Amalie\Desktop\GJ_Nov\MarkovLove\Build\src && C:\PROGRA~2\mingw32\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Amalie\Desktop\GJ_Nov\MarkovLove\Trunk\src\main.cpp -o CMakeFiles\MarkovLove.dir\main.cpp.s

src/CMakeFiles/MarkovLove.dir/main.cpp.obj.requires:

.PHONY : src/CMakeFiles/MarkovLove.dir/main.cpp.obj.requires

src/CMakeFiles/MarkovLove.dir/main.cpp.obj.provides: src/CMakeFiles/MarkovLove.dir/main.cpp.obj.requires
	$(MAKE) -f src\CMakeFiles\MarkovLove.dir\build.make src/CMakeFiles/MarkovLove.dir/main.cpp.obj.provides.build
.PHONY : src/CMakeFiles/MarkovLove.dir/main.cpp.obj.provides

src/CMakeFiles/MarkovLove.dir/main.cpp.obj.provides.build: src/CMakeFiles/MarkovLove.dir/main.cpp.obj


src/CMakeFiles/MarkovLove.dir/parser.cpp.o: src/CMakeFiles/MarkovLove.dir/flags.make
src/CMakeFiles/MarkovLove.dir/parser.cpp.o: /home/rtollefson/Documents/MarkovLove/Trunk/src/parser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/rtollefson/Documents/MarkovLove/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/MarkovLove.dir/parser.cpp.o"
	cd /home/rtollefson/Documents/MarkovLove/Build/src && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MarkovLove.dir/parser.cpp.o -c /home/rtollefson/Documents/MarkovLove/Trunk/src/parser.cpp

src/CMakeFiles/MarkovLove.dir/parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MarkovLove.dir/parser.cpp.i"
	cd /home/rtollefson/Documents/MarkovLove/Build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/rtollefson/Documents/MarkovLove/Trunk/src/parser.cpp > CMakeFiles/MarkovLove.dir/parser.cpp.i

src/CMakeFiles/MarkovLove.dir/parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MarkovLove.dir/parser.cpp.s"
	cd /home/rtollefson/Documents/MarkovLove/Build/src && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/rtollefson/Documents/MarkovLove/Trunk/src/parser.cpp -o CMakeFiles/MarkovLove.dir/parser.cpp.s

src/CMakeFiles/MarkovLove.dir/parser.cpp.o.requires:

.PHONY : src/CMakeFiles/MarkovLove.dir/parser.cpp.o.requires

src/CMakeFiles/MarkovLove.dir/parser.cpp.o.provides: src/CMakeFiles/MarkovLove.dir/parser.cpp.o.requires
	$(MAKE) -f src/CMakeFiles/MarkovLove.dir/build.make src/CMakeFiles/MarkovLove.dir/parser.cpp.o.provides.build
.PHONY : src/CMakeFiles/MarkovLove.dir/parser.cpp.o.provides

src/CMakeFiles/MarkovLove.dir/parser.cpp.o.provides.build: src/CMakeFiles/MarkovLove.dir/parser.cpp.o


# Object files for target MarkovLove
MarkovLove_OBJECTS = \
<<<<<<< HEAD
"CMakeFiles/MarkovLove.dir/main.cpp.o" \
"CMakeFiles/MarkovLove.dir/parser.cpp.o"
=======
"CMakeFiles/MarkovLove.dir/main.cpp.obj"
>>>>>>> ef94ad5c25d3ee1d6d32cd6f12008f9dec535666

# External object files for target MarkovLove
MarkovLove_EXTERNAL_OBJECTS =

<<<<<<< HEAD
src/MarkovLove: src/CMakeFiles/MarkovLove.dir/main.cpp.o
src/MarkovLove: src/CMakeFiles/MarkovLove.dir/parser.cpp.o
src/MarkovLove: src/CMakeFiles/MarkovLove.dir/build.make
src/MarkovLove: src/CMakeFiles/MarkovLove.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/rtollefson/Documents/MarkovLove/Build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable MarkovLove"
	cd /home/rtollefson/Documents/MarkovLove/Build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MarkovLove.dir/link.txt --verbose=$(VERBOSE)
=======
src/MarkovLove.exe: src/CMakeFiles/MarkovLove.dir/main.cpp.obj
src/MarkovLove.exe: src/CMakeFiles/MarkovLove.dir/build.make
src/MarkovLove.exe: src/CMakeFiles/MarkovLove.dir/linklibs.rsp
src/MarkovLove.exe: src/CMakeFiles/MarkovLove.dir/objects1.rsp
src/MarkovLove.exe: src/CMakeFiles/MarkovLove.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Amalie\Desktop\GJ_Nov\MarkovLove\Build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable MarkovLove.exe"
	cd /d C:\Users\Amalie\Desktop\GJ_Nov\MarkovLove\Build\src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\MarkovLove.dir\link.txt --verbose=$(VERBOSE)
>>>>>>> ef94ad5c25d3ee1d6d32cd6f12008f9dec535666

# Rule to build all files generated by this target.
src/CMakeFiles/MarkovLove.dir/build: src/MarkovLove.exe

.PHONY : src/CMakeFiles/MarkovLove.dir/build

<<<<<<< HEAD
src/CMakeFiles/MarkovLove.dir/requires: src/CMakeFiles/MarkovLove.dir/main.cpp.o.requires
src/CMakeFiles/MarkovLove.dir/requires: src/CMakeFiles/MarkovLove.dir/parser.cpp.o.requires
=======
src/CMakeFiles/MarkovLove.dir/requires: src/CMakeFiles/MarkovLove.dir/main.cpp.obj.requires
>>>>>>> ef94ad5c25d3ee1d6d32cd6f12008f9dec535666

.PHONY : src/CMakeFiles/MarkovLove.dir/requires

src/CMakeFiles/MarkovLove.dir/clean:
	cd /d C:\Users\Amalie\Desktop\GJ_Nov\MarkovLove\Build\src && $(CMAKE_COMMAND) -P CMakeFiles\MarkovLove.dir\cmake_clean.cmake
.PHONY : src/CMakeFiles/MarkovLove.dir/clean

src/CMakeFiles/MarkovLove.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Amalie\Desktop\GJ_Nov\MarkovLove\Trunk C:\Users\Amalie\Desktop\GJ_Nov\MarkovLove\Trunk\src C:\Users\Amalie\Desktop\GJ_Nov\MarkovLove\Build C:\Users\Amalie\Desktop\GJ_Nov\MarkovLove\Build\src C:\Users\Amalie\Desktop\GJ_Nov\MarkovLove\Build\src\CMakeFiles\MarkovLove.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/MarkovLove.dir/depend

