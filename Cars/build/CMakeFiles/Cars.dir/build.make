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
CMAKE_SOURCE_DIR = /home/bartlomiej/Desktop/Exercises/Cars

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bartlomiej/Desktop/Exercises/Cars/build

# Include any dependencies generated for this target.
include CMakeFiles/Cars.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Cars.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Cars.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Cars.dir/flags.make

CMakeFiles/Cars.dir/ElectricCar.cpp.o: CMakeFiles/Cars.dir/flags.make
CMakeFiles/Cars.dir/ElectricCar.cpp.o: ../ElectricCar.cpp
CMakeFiles/Cars.dir/ElectricCar.cpp.o: CMakeFiles/Cars.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bartlomiej/Desktop/Exercises/Cars/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Cars.dir/ElectricCar.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Cars.dir/ElectricCar.cpp.o -MF CMakeFiles/Cars.dir/ElectricCar.cpp.o.d -o CMakeFiles/Cars.dir/ElectricCar.cpp.o -c /home/bartlomiej/Desktop/Exercises/Cars/ElectricCar.cpp

CMakeFiles/Cars.dir/ElectricCar.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Cars.dir/ElectricCar.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bartlomiej/Desktop/Exercises/Cars/ElectricCar.cpp > CMakeFiles/Cars.dir/ElectricCar.cpp.i

CMakeFiles/Cars.dir/ElectricCar.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Cars.dir/ElectricCar.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bartlomiej/Desktop/Exercises/Cars/ElectricCar.cpp -o CMakeFiles/Cars.dir/ElectricCar.cpp.s

CMakeFiles/Cars.dir/ElectricEngine.cpp.o: CMakeFiles/Cars.dir/flags.make
CMakeFiles/Cars.dir/ElectricEngine.cpp.o: ../ElectricEngine.cpp
CMakeFiles/Cars.dir/ElectricEngine.cpp.o: CMakeFiles/Cars.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bartlomiej/Desktop/Exercises/Cars/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Cars.dir/ElectricEngine.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Cars.dir/ElectricEngine.cpp.o -MF CMakeFiles/Cars.dir/ElectricEngine.cpp.o.d -o CMakeFiles/Cars.dir/ElectricEngine.cpp.o -c /home/bartlomiej/Desktop/Exercises/Cars/ElectricEngine.cpp

CMakeFiles/Cars.dir/ElectricEngine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Cars.dir/ElectricEngine.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bartlomiej/Desktop/Exercises/Cars/ElectricEngine.cpp > CMakeFiles/Cars.dir/ElectricEngine.cpp.i

CMakeFiles/Cars.dir/ElectricEngine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Cars.dir/ElectricEngine.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bartlomiej/Desktop/Exercises/Cars/ElectricEngine.cpp -o CMakeFiles/Cars.dir/ElectricEngine.cpp.s

CMakeFiles/Cars.dir/HybridCar.cpp.o: CMakeFiles/Cars.dir/flags.make
CMakeFiles/Cars.dir/HybridCar.cpp.o: ../HybridCar.cpp
CMakeFiles/Cars.dir/HybridCar.cpp.o: CMakeFiles/Cars.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bartlomiej/Desktop/Exercises/Cars/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Cars.dir/HybridCar.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Cars.dir/HybridCar.cpp.o -MF CMakeFiles/Cars.dir/HybridCar.cpp.o.d -o CMakeFiles/Cars.dir/HybridCar.cpp.o -c /home/bartlomiej/Desktop/Exercises/Cars/HybridCar.cpp

CMakeFiles/Cars.dir/HybridCar.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Cars.dir/HybridCar.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bartlomiej/Desktop/Exercises/Cars/HybridCar.cpp > CMakeFiles/Cars.dir/HybridCar.cpp.i

CMakeFiles/Cars.dir/HybridCar.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Cars.dir/HybridCar.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bartlomiej/Desktop/Exercises/Cars/HybridCar.cpp -o CMakeFiles/Cars.dir/HybridCar.cpp.s

CMakeFiles/Cars.dir/main.cpp.o: CMakeFiles/Cars.dir/flags.make
CMakeFiles/Cars.dir/main.cpp.o: ../main.cpp
CMakeFiles/Cars.dir/main.cpp.o: CMakeFiles/Cars.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bartlomiej/Desktop/Exercises/Cars/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Cars.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Cars.dir/main.cpp.o -MF CMakeFiles/Cars.dir/main.cpp.o.d -o CMakeFiles/Cars.dir/main.cpp.o -c /home/bartlomiej/Desktop/Exercises/Cars/main.cpp

CMakeFiles/Cars.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Cars.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bartlomiej/Desktop/Exercises/Cars/main.cpp > CMakeFiles/Cars.dir/main.cpp.i

CMakeFiles/Cars.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Cars.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bartlomiej/Desktop/Exercises/Cars/main.cpp -o CMakeFiles/Cars.dir/main.cpp.s

CMakeFiles/Cars.dir/PetrolCar.cpp.o: CMakeFiles/Cars.dir/flags.make
CMakeFiles/Cars.dir/PetrolCar.cpp.o: ../PetrolCar.cpp
CMakeFiles/Cars.dir/PetrolCar.cpp.o: CMakeFiles/Cars.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bartlomiej/Desktop/Exercises/Cars/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Cars.dir/PetrolCar.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Cars.dir/PetrolCar.cpp.o -MF CMakeFiles/Cars.dir/PetrolCar.cpp.o.d -o CMakeFiles/Cars.dir/PetrolCar.cpp.o -c /home/bartlomiej/Desktop/Exercises/Cars/PetrolCar.cpp

CMakeFiles/Cars.dir/PetrolCar.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Cars.dir/PetrolCar.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bartlomiej/Desktop/Exercises/Cars/PetrolCar.cpp > CMakeFiles/Cars.dir/PetrolCar.cpp.i

CMakeFiles/Cars.dir/PetrolCar.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Cars.dir/PetrolCar.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bartlomiej/Desktop/Exercises/Cars/PetrolCar.cpp -o CMakeFiles/Cars.dir/PetrolCar.cpp.s

CMakeFiles/Cars.dir/PetrolEngine.cpp.o: CMakeFiles/Cars.dir/flags.make
CMakeFiles/Cars.dir/PetrolEngine.cpp.o: ../PetrolEngine.cpp
CMakeFiles/Cars.dir/PetrolEngine.cpp.o: CMakeFiles/Cars.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bartlomiej/Desktop/Exercises/Cars/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Cars.dir/PetrolEngine.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Cars.dir/PetrolEngine.cpp.o -MF CMakeFiles/Cars.dir/PetrolEngine.cpp.o.d -o CMakeFiles/Cars.dir/PetrolEngine.cpp.o -c /home/bartlomiej/Desktop/Exercises/Cars/PetrolEngine.cpp

CMakeFiles/Cars.dir/PetrolEngine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Cars.dir/PetrolEngine.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bartlomiej/Desktop/Exercises/Cars/PetrolEngine.cpp > CMakeFiles/Cars.dir/PetrolEngine.cpp.i

CMakeFiles/Cars.dir/PetrolEngine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Cars.dir/PetrolEngine.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bartlomiej/Desktop/Exercises/Cars/PetrolEngine.cpp -o CMakeFiles/Cars.dir/PetrolEngine.cpp.s

CMakeFiles/Cars.dir/Car.cpp.o: CMakeFiles/Cars.dir/flags.make
CMakeFiles/Cars.dir/Car.cpp.o: ../Car.cpp
CMakeFiles/Cars.dir/Car.cpp.o: CMakeFiles/Cars.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bartlomiej/Desktop/Exercises/Cars/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Cars.dir/Car.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Cars.dir/Car.cpp.o -MF CMakeFiles/Cars.dir/Car.cpp.o.d -o CMakeFiles/Cars.dir/Car.cpp.o -c /home/bartlomiej/Desktop/Exercises/Cars/Car.cpp

CMakeFiles/Cars.dir/Car.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Cars.dir/Car.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bartlomiej/Desktop/Exercises/Cars/Car.cpp > CMakeFiles/Cars.dir/Car.cpp.i

CMakeFiles/Cars.dir/Car.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Cars.dir/Car.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bartlomiej/Desktop/Exercises/Cars/Car.cpp -o CMakeFiles/Cars.dir/Car.cpp.s

# Object files for target Cars
Cars_OBJECTS = \
"CMakeFiles/Cars.dir/ElectricCar.cpp.o" \
"CMakeFiles/Cars.dir/ElectricEngine.cpp.o" \
"CMakeFiles/Cars.dir/HybridCar.cpp.o" \
"CMakeFiles/Cars.dir/main.cpp.o" \
"CMakeFiles/Cars.dir/PetrolCar.cpp.o" \
"CMakeFiles/Cars.dir/PetrolEngine.cpp.o" \
"CMakeFiles/Cars.dir/Car.cpp.o"

# External object files for target Cars
Cars_EXTERNAL_OBJECTS =

Cars: CMakeFiles/Cars.dir/ElectricCar.cpp.o
Cars: CMakeFiles/Cars.dir/ElectricEngine.cpp.o
Cars: CMakeFiles/Cars.dir/HybridCar.cpp.o
Cars: CMakeFiles/Cars.dir/main.cpp.o
Cars: CMakeFiles/Cars.dir/PetrolCar.cpp.o
Cars: CMakeFiles/Cars.dir/PetrolEngine.cpp.o
Cars: CMakeFiles/Cars.dir/Car.cpp.o
Cars: CMakeFiles/Cars.dir/build.make
Cars: CMakeFiles/Cars.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bartlomiej/Desktop/Exercises/Cars/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable Cars"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Cars.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Cars.dir/build: Cars
.PHONY : CMakeFiles/Cars.dir/build

CMakeFiles/Cars.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Cars.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Cars.dir/clean

CMakeFiles/Cars.dir/depend:
	cd /home/bartlomiej/Desktop/Exercises/Cars/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bartlomiej/Desktop/Exercises/Cars /home/bartlomiej/Desktop/Exercises/Cars /home/bartlomiej/Desktop/Exercises/Cars/build /home/bartlomiej/Desktop/Exercises/Cars/build /home/bartlomiej/Desktop/Exercises/Cars/build/CMakeFiles/Cars.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Cars.dir/depend

