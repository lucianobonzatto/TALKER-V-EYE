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

# Flags for compiler
CC_FLAGS=-c         \
         -W         \
         -Wall      \
         -ansi      \
         -pedantic

# Command used at clean target
RM = rm -rf

#
# Compilation and linking
#
all: objFolder $(PROJ_NAME)

$(PROJ_NAME): $(OBJ)
	@ echo 'Building $@'
	$(CC) $^ -o $@
	@ echo 'Finished building binary: $@'
	@ echo ' '

./objects/%.o: ./source/%.cpp ./source/%.h
	@ echo 'Building $<'
	$(CC) $< $(CC_FLAGS) -o $@
	@ echo ' '

./objects/main.o: ./source/main.cpp $(H_SOURCE)
	@ echo 'Building $<'
	$(CC) $< $(CC_FLAGS) -o $@
	@ echo ' '

objFolder:
	@ mkdir -p objects

clean:
	@ $(RM) ./objects/*.o $(PROJ_NAME) *~
	@ rmdir objects

.PHONY: all clean
