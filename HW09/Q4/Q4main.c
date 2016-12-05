#include <stdio.h>
#include <stdlib.h>
#include "Q4.h"

int main(int argc, char** argv) {

   if ( argc != 3 ) {
      printf("Invoke as:  $s <integer value> <integer value>\n", argv[0]);
      return 1;
   }

   int mx = atoi(argv[1]);
   int my = atoi(argv[2]);
   int mz = Q4(mx, my);

   printf("my = %d\n", mz);

   return 0;
}

