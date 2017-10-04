SOURCES = conversion.c debug.c memory.c project1Main.c
OBJS =conversion.o debug.o memory.o project1Main.o
#INCLUDES = 

ifeq ($(PLATFORM),HOST)
	CC = gcc
endif

ifeq ($(PLATFORM),BBB)
	CC = arm-linux-gnueabi-gcc
endif

ifeq ($(PLATFORM),KL25Z)
	CC = arm-none-eabi-gcc
endif

DEBUG = -g
CPPFLAGS = -E
LDFLAGS = -lm
#PLATFORM = 
CFLAGS = -Wall -Werror -std=c99 $(DEBUG)
LFLAGS = -lm

#project1Main : $(SOURCES)
#	$(CC) $(CFLAGS) $(SOURCES) -o project1Main

.PHONY: compile-all
compile-all:  $(OBJS)
	$(CC) $(CFLAGS) -c $< -o $@

%.o:%.c
	$(CC) $(CFLAGS) -c $< -o $@

%.i:%.c
	$(CC) $(CFLAGS) $(CPPFLAGS)  $< -o $@

%.asm:%.c
	$(CC) $(CFLAGS) -S $< -o $@

.PHONY: build
build: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LDFLAGS) -o project1

.PHONY: clean
clean:
	-rm *.o *.map *.out *.asm *.i
