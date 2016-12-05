#include <stdlib.h>
#define CANARY	0XDEADBEEF

#include "WriteSquares.h"

int main() {

   int  Sz = 100;
   int* MemoryBlock = malloc(Sz * sizeof(int) + 16);
   if ( MemoryBlock == NULL ) return 1;

   *MemoryBlock = CANARY;
   *(MemoryBlock + 1) = CANARY;
   *(MemoryBlock + Sz + 2) = CANARY;
   *(MemoryBlock + Sz + 3) = CANARY;
   int* A = MemoryBlock + 2;
   A[-1] = CANARY;

   // We suspect this function may contain a bug (or two),
   // and it may write outside the proper boundaries of the
   // array A of dimension Sz:
   WriteSquares(A, Sz);

   free(MemoryBlock);   
   return 0;
}

