# Name of the project
PROJ_NAME=TALKER-V-EYE

# .c files
C_SOURCE=$(wildcard ./source/*.cpp)

# .h files
H_SOURCE=$(wildcard ./source/*.h)

# Object files
OBJ=$(subst .cpp,.o,$(subst source,objects,$(C_SOURCE)))

# Compiler and linker
CC=g++

# Command used at clean target
RM = rm -rf

#
# Compilation and linking
#
all:
	echo 'oi'
	g++ source/main.cpp -o rs_main -lrealsense2
