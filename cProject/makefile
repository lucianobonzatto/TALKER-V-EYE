# Name of the project
PROJ_NAME=TALKER-V-EYE

# .c files
C_SOURCE=$(wildcard ./source/*.cpp)
C_SOURCE_INCLUDE=$(wildcard ./include/*.cpp)

# .h files
H_SOURCE=$(wildcard ./source/*.h)
H_SOURCE_INCLUDE=$(wildcard ./include/*.h)

# Object files
OBJ=$(subst .cpp,.o,$(subst source,objects,$(C_SOURCE)))

# Compiler and linker
CC=g++

# Flags for compiler
CC_FLAGS=-c           \
         -lrealsense2 \
         -lopencv_core\
         -lpigpio
#         -ansi        \
#         -W           \
#         -Wall        \
#         -pedantic

# Command used at clean target
RM = rm -rf

#
# Compilation and linking
#
all: objFolder $(PROJ_NAME)

$(PROJ_NAME): $(OBJ)
	@ echo 'Building $@'
	g++ $^ -o $@ -lrealsense2 -lpigpio
	@ echo 'Finished building binary: $@'
	@ echo ' '

./objects/%.o: ./source/%.cpp ./source/%.h
	@ echo 'Building $<'
	g++ $< -o $@ $(CC_FLAGS)
	@ echo ' '

./objects/main.o: ./source/main.cpp $(H_SOURCE)
	@ echo 'Building $<'
	g++ $< -o $@ $(CC_FLAGS)
	@ echo ' '

objFolder:
	@ mkdir -p objects

clean:
	@ $(RM) ./objects/*.o $(PROJ_NAME) *~
	@ rmdir objects

.PHONY: all clean
