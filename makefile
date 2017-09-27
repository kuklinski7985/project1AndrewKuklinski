CC=gcc

CFLAGS=-c -Wall -Map


all: project1Main

project1Main: project1Main.o memory.o debug.o conversion.o
	$(CC) project1Main.o memory.o debug.o conversion.o -o project1Main

project1Main.o: project1Main.c
	$(CC) $(CFLAGS) project1Main.c

conversion.o: conversion.c
	$(CC) $(CFLAGS) conversion.c

debug.o: debug.c
	$(CC) $(CFLAGS) debug.c

memory.o: memory.c
	$(CC) $(CFLAGS) memory.c
