#include <stdio.h>
#include <stdint.h>
#include "debug.h"

/*function definitions for Project 1 ECEN5813, Fall 2017*/

void print_memory(uint8_t * start, uint32_t length)
{
  //printf("Values at memory location [%p] to [%p]\n", &start, (&start+length));
  for(int i=0; i < length; i++)
  {
    printf("Address: %p | Hex Value: 0x%02x \n",start, *start);
    start++;
  }
  printf("\n");
}
