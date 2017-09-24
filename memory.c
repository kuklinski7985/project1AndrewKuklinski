#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "memory.h"

int8_t * my_memset(uint8_t * src, size_t length, uint8_t value)
{
  for(int i=0; i<length; i++)
  {
    *src = value;
    src++;
  }
  return ((int8_t*) src-length);
}


uint8_t * my_memzero(uint8_t * src, size_t length)
{
  for(int i=0; i<length; i++)
  {
    *src = 0;
    src++;
  }
  return ((uint8_t*) src-length);
}


uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length)
{
  uint8_t holdArray[length];
  uint8_t *holdArrayPtr = holdArray;
  for(int i=0; i<length; i++)
  {
    *holdArrayPtr = *src;
    src++;
    holdArrayPtr++;
  }
  holdArrayPtr = holdArray;
  for(int j=0; j<length; j++)
  {
    *dst = *holdArrayPtr;
    dst++;
    holdArrayPtr++;
  }
  
  return ((uint8_t*) dst-length);
}

uint8_t * my_memcpy(uint8_t * src, uint8_t * dst, size_t length)
{
  for(int i=0; i<length; i++)
  {
    *dst = *src;
    src++;
    dst++;
  }
  return (dst - length);
}


uint8_t * my_reverse(uint8_t * src, size_t length)
{
  uint8_t *ptrHead = src;    
  uint8_t *ptrTail = src + (length-1); 

  uint8_t holdArray[length];
  uint8_t *holdPtr = holdArray;
  
  uint8_t intermediate = 0;     

  while(!((ptrHead == ptrTail) || (ptrHead == (ptrTail -1))))
  {
    intermediate = *ptrHead;
    *ptrHead = *ptrTail;
    *ptrTail = intermediate;
    ptrHead++;
    ptrTail--;
    if(ptrHead == (ptrTail-1))
    {
      intermediate = *ptrHead;
      *ptrHead = *ptrTail;
      *ptrTail = intermediate; 
    }
  }
  return src;
}

int32_t * reserve_words(size_t length)
{
  int * reservePtr;
  reservePtr = (int *) malloc((sizeof(int)*length));
  if(reservePtr == 0)
  {
    return NULL;
  }
  return reservePtr;
}

void free_words(int32_t * src)
{
  free(src);
}
