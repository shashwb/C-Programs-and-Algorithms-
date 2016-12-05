#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include "AddEm.h"

#define BUFFSZ 20
#define LISTSZ 10

int main() {

   int32_t  Buffer[BUFFSZ] = {-1, -1, -1, 1, -1, 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, -1, -1, -1, -1, -1};
   int32_t* A = &Buffer[5];

   int32_t Sum = AddEm(A, LISTSZ);

   printf("Sum is %"PRId32"\n", Sum);

   return 0;
}

