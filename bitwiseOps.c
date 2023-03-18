#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FIRST_FLAG 0b1
#define SECOND_FLAG 0b10
#define THIRD_FLAG 0b10000000

int main(int argc, char *argv[]) {

  // unsigned int flags = 2;
  unsigned int flags = FIRST_FLAG | SECOND_FLAG | THIRD_FLAG; // 1 , 2, and 128 in binary
  //unsigned int = 4 Bytes (4*8 32 bits)
  //00000000 00000000 00000000 00000001 <-- binary value of 1
  //00000000 00000000 00000000 00000010  | <-- binary value of 2
  //00000000 00000000 00000000 10000000  | <-- binary value of 128
  // or operation will result in
  //00000000 00000000 00000000 10000011 <-- binary value of flags

  //to turn of one feature (one bit)
  // flags = flags & ~SECOND_FLAG;
  flags &= ~SECOND_FLAG; // short hand
  // flags ^= SECOND_FLAG; // even better with xor (1st will turn off)
  // flags ^= SECOND_FLAG; // (2nd time will turn on)
  //to turn it back on
  flags = flags | SECOND_FLAG; //flags |= SECOND_FLAG;

  // Both actually the same with "!= 0" or without it
  // if ((flags & FIRST_FLAG) != 0) { // bitwise anding
  if (flags & FIRST_FLAG) { // bitwise anding
  //00000000 00000000 00000000 00000001 &  <- value of 1 
  //00000000 00000000 00000000 10000011    <- vlaue of flags
  //00000000 00000000 00000000 10000000    <- anding operation result
    printf("1st feature is enabled\n");
  }

  if ((flags & SECOND_FLAG) != 0) { // bitwise andingW
    printf("2st feature is enabled\n");
  }
  if ((flags & THIRD_FLAG) != 0) { // bitwise anding
    printf("3st feature is enabled\n");
  }

  return 0;
}
