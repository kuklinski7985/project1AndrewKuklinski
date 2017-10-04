SOURCES = conversion.c debug.c memory.c main.c project1.c
OBJS = $(SOURCES:.c=.o)
IMP = $(SOURCES:.c=.i)
INCLUDES = 
CC = gcc
DEBUG = -g -Wall -Werror -std=c99
CPPFLAGS = -E
LDFLAGS = -lm -Wl,-Map,project1.map -MMD
CFLAGS = -c
LFLAGS = -S

ifeq ($(PLATFORM),HOST)
	CC = gcc
endif

ifeq ($(PLTFORM),BBB)
	CC = arm-linux-gnueabi-gcc
endif

ifeq ($(PLATFORM),KL25Z)
	CC = arm-none-eabi-gcc
endif



%.o:%.c
	$(CC) $(DEBUG) $(CFLAGS) $^ -o $@

%.i:%.c
	$(CC) $(DEBUG) $(CPPFLAGS) $^ -o $@

%.asm:%.c
	$(CC) $(CFLAGS) -S $< -o $@

.PHONY: compile-all
compile-all: $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) $< -o $@

.PHONY: build
build: $(OBJS)
	$(CC) $(DEBUG) $(OBJS) $(LDFLAGS) -o project1.elf
	$(CC) $(DEBUG) $(SOURCES) $(LDFLAGS)

.PHONY: clean
clean:
	-rm *.o *.map *.d project1.elf
