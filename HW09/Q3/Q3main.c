#include <stdio.h>
#include <ctype.h>
#include "Q3.h"

int main(int argc, char** argv) {

   if ( argc != 2 ) {
      printf("Invocation:  $s <string>\n", argv[0]);
      return 1;
   }
   
   char* mc = argv[1];
   if ( Q3(mc) ) {
      printf("%s worked\n", mc);
   }

   return 0;
}

