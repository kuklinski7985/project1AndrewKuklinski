SOURCES = conversion.o debug.o memory.o main.o
#INCLUDES = 
CC = gcc
DEBUG = -g -Wall -Werror -std=c99
CPPFLAGS = -E $(DEBUG)
LDFLAGS = -lm
#PLATFORM = 
CFLAGS = -c
LFLAGS = -S

%.o:%.c
	$(CC) $(CFLAGS) $< -o $@

%.i:%.c
	$(CC) $(CPPFLAGS) $< -o $@

%.asm:%.c
	$(CC) $(LFLAGS) $< -o $@

.PHONY: compile-all
compile-all: $(SOURCES)
	$(CC) $(CFLAGS) $< -o $@

.PHONY: build
build: $(SOURCES)
	$(CC) $(CFLAGS)  $(SOURCES)  $(LDFLAGS) -o project1

.PHONY: clean
clean:
	-rm *.o *.map *.out *.asm *.i
