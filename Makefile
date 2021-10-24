SCRIPTS = src/*.cpp

COMPILER = g++

INCLUDE_PATHS = -Idependencies/include

LIBRARY_PATHS = -Ldependencies/lib

LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2 -lSDL2_image

OBJ_NAME = main

all: $(SCRIPTS)
	$(COMPILER) $(SCRIPTS) $(INCLUDE_PATHS) -Wall $(LIBRARY_PATHS) $(LINKER_FLAGS) -o $(OBJ_NAME)