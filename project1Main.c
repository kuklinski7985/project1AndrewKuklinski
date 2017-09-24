#include "debug.h"
#include "memory.h"


int main(){

  //uint32_t length = 20;
  //uint8_t testArray[] = "This is only a test.";
  uint8_t length = 6;
  uint8_t testArray2[] = {0x02, 0x04, 0x06, 0x10, 0xA7, 0xF0};
  uint8_t destArray[length];
  //int8_t * int8returnValue = NULL;
  //uint8_t * uint8returnValue = NULL;
  int32_t * int32returnValue = NULL;
 
  
  //print_memory(testArray2, length);
  //int8returnValue = my_memset(testArray2, length, 3);
  //printf("returnValue: %p\n",int8returnValue);
  //print_memory(testArray2, length);

  //uint8returnValue = my_memzero(testArray2,(size_t) length);
  //printf("returnValue: %p\n",uint8returnValue);
  //print_memory(testArray2, length);

  print_memory(testArray2, length);
  //print_memory(destArray, length);
  // uint8returnValue = my_memcpy(testArray2,destArray,6);
  int32returnValue = reserve_words(6);
  printf("returnValue: %p\n",int32returnValue);
  //print_memory(testArray2, length);
  

  return 0;
}
