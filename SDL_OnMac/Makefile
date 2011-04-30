EXE := main
CC := g++

CFLAGS := -Wall -I/Library/Frameworks/SDL.framework/Versions/A/Headers/
LDFLAGS := 
SDL_FLAGS := -framework SDL -framework Cocoa

SRCS := $(wildcard src/*.cpp)
OBJS := $(patsubst src/%.cpp,obj/%.o,$(SRCS))
#SRCS += src/SDLMain.m
#OBJS += obj/SDLMain.o
DEPS := $(wildcard src/*.h*)

all : LDFLAGS += -O3
all : $(EXE)

debug : CXXFLAGS += -pg
debug : LDFLAGS += -pg -O0
debug : $(EXE)

$(EXE) : $(OBJS) obj/SDLMain.o
	$(CC) $(SDL_FLAGS) $(LDFLAGS) -o $@ $^ $(LIBS)

$(OBJS) : $(SRCS) $(DEPS)
	$(CC) -c $(CXXFLAGS) -o $@ $<

obj/SDLMain.o : src/SDLMain.m src/SDLMain.h
	$(CC) -c $(CXXFLAGS) -o $@ $<

clean:
	rm -f obj/*.o $(EXE)

.PHONY: all clean debug
