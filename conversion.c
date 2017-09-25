#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "conversion.h"


int8_t little_to_big32(uint32_t * data, uint32_t length)
{
  uint32_t original1 = *data & 0x000000ff;
  uint32_t original2 = *data & 0x0000ff00;
  uint32_t original3 = *data & 0x00ff0000;
  uint32_t original4 = *data & 0xff000000;

  uint32_t newDigit1 = original1 << 24;
  uint32_t newDigit2 = original2 << 8;
  uint32_t newDigit3 = original3 >> 8;
  uint32_t newDigit4 = original4 >> 24;

  *data = newDigit1 | newDigit2 | newDigit3 | newDigit4;

    
  if(((original1<<24)==newDigit1)&((original2<<8)==newDigit2)&
     ((original3>>8)==newDigit3)&((original4>>24)==newDigit4))
    {
      printf("word.\n\n");
      return 0;
    }
  else
    {
      printf("shit.\n\n");
      return 1;
    }
}


int8_t big_to_little32(uint32_t * data, uint32_t length)
{
  uint32_t original1 = *data & 0xff000000;
  uint32_t original2 = *data & 0x00ff0000;
  uint32_t original3 = *data & 0x0000ff00;
  uint32_t original4 = *data & 0x000000ff;

  uint32_t newDigit1 = original1 >> 24;
  uint32_t newDigit2 = original2 >> 8;
  uint32_t newDigit3 = original3 << 8;
  uint32_t newDigit4 = original4 << 24;

  *data = newDigit1 | newDigit2 | newDigit3 | newDigit4;
  
  if(((original1>>24)==newDigit1)&((original2>>8)==newDigit2)&
     ((original3<<8)==newDigit3)&((original4<<24)==newDigit4))
    {
      return 0;
    }
  else
    {
      return 1;
    }
}

//uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

//int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);
