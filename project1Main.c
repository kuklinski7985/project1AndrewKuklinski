#include <stdio.h>
#include <stdint.h>
#include "debug.h"
#include "memory.h"
#include "conversion.h"


int main(){

  //uint32_t length = 20;
  //uint8_t testArray[] = "This is only a test.";
  //uint8_t length = 6;
  //uint8_t testArray2[] = {0x02, 0x04, 0x06, 0x10, 0xA7, 0xF0};
  //uint8_t destArray[length];
  //int8_t * int8returnValue = NULL;
  //uint8_t * uint8returnValue = NULL;
 // int32_t * int32returnValue = NULL;
 
  
  //print_memory(testArray2, length);
  //int8returnValue = my_memset(testArray2, length, 3);
  //printf("returnValue: %p\n",int8returnValue);
  //print_memory(testArray2, length);

  //uint8returnValue = my_memzero(testArray2,(size_t) length);
  //printf("returnValue: %p\n",uint8returnValue);
  //print_memory(testArray2, length);

  //print_memory(testArray2, length);
  //print_memory(destArray, length);
  // uint8returnValue = my_memcpy(testArray2,destArray,6);
 //  int32returnValue = reserve_words(6);
 // printf("returnValue: %p\n",int32returnValue);
  //print_memory(testArray2, length);

  /* uint32_t testArray[] = {0x90ab426c};
  uint32_t length = 1;
  print_memory((uint8_t*) testArray, length*4);
  //printf("0x%02x\n",*testArray);
  //  big_to_little32(testArray, length);
  little_to_big32(testArray, length);
  print_memory((uint8_t*) testArray, length*4);
  // printf("0x%02x\n",*testArray);*/

  int32_t testValue = 1234;
  int32_t baseValue = 10;
  uint8_t *valuePtr;
  uint8_t length=0;
  uint8_t testString[4] = {'1','2','3','4'};
  valuePtr = (uint8_t*) &testValue;
// printf("entered main");
 // length =  my_itoa(testValue, valuePtr, baseValue);
 // print_memory(valuePtr,length);
 
  int32_t num=0;
  num = baseValue^2;
  printf("%d\n",num); 
  int32_t final_value;
  final_value = my_atoi(testString,4,baseValue);
//  printf("  Final Decimal number: %d\n",final_value); 
  return 0;
}
