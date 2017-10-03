SOURCES = conversion.o debug.o memory.o
#INCLUDES = 
CC = gcc
DEBUG = -g
CPPFLAGS = -E
#LDFLAGS =
#PLATFORM = 
CFLAGS = -Wall -Werror -std=c99 $(DEBUG)
LFLAGS = -Wall -Werror -std=c99 $(DEBUG)

#project1Main : $(SOURCES)
#	$(CC) $(CFLAGS) $(SOURCES) -o project1Main

.PHONY: compile-all
compile-all:  $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o a.out

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

%.i:%.c
	$(CC) $(CFLAGS) $(CPPFLAGS)  $< -o $@

%.asm:%.c
	$(CC) $(CFLAGS) -S $< -o $@

#conversion.o : conversion.c conversion.h
#	$(CC) $(CFLAGS) conversion.c

#debug.o : debug.c debug.h
#	$(CC) $(CFLAGS) debug.c

#memory.o : memory.c memory.h
#	$(CC) $(CFLAGS) memory.c

#build: $(SOURCES) project1Main.c
#	$(CC) $(LFLAGS) project1Main.c

.PHONY: build
build:

.PHONY: clean
clean:
	-rm *.o *.map *.out *.asm *.i
