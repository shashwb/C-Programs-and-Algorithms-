// Driver for HW07.
// Instructions:
//   Compile with your Untangle.c and the appropriate version of GeneratorXX.o.
//   Run as:
//     driver -Q1         // randomly-selected quotation, Q1 testing
//     driver -Q2         // randomly-selected quotation, Q2 testing
//     driver NN  -Q1     // use quotation #NN (0 <= NN <= 50), Q1 testing
//     driver NN  -Q2     // use quotation #NN (0 <= NN <= 50), Q2 testing
//
//   Use hexdump -C on resulting Data.bin to view data supplied to Untangle().
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdint.h>
#include <inttypes.h>
#include <ctype.h>
#include <stdbool.h>

#include "Generator.h"
#include "Untangle.h"

void prepBuffer();

#define BUFFER_SZ  1024         // memory buffer size
#define FILL_VALUE 0xFF         // memory buffer fill value

uint8_t* quoteBuffer = NULL;    // pointer to memory buffer
bool     Q2Selected  = false;   // question selector; set via command-line
const int qLimit = 50;          // maximum index for a quotation

int main(int argc, char** argv) {

   char* binFileName = "Data.bin";
   uint8_t seqNo = 0;
   
   if ( argc == 1 || argc > 3 ) {
      printf("Error:  see execution instructions in driver.c\n");
      return 1;
   }
   else if ( argc == 2 ) {    // use random quotation, Q1 or Q2
      seqNo = 255;
      if ( strcmp(argv[1], "-Q1") == 0 ) {
         Q2Selected = false;
      }
      else {
         Q2Selected = true;
      }
   }  
   else if ( argc == 3 ) {     // use selected quotation, Q1 or Q2
      int qSelector = atoi(argv[2]);
      if ( qSelector < 0 || qSelector > qLimit ) {
         printf("%d is invalid, using random quotation.\n", qSelector);
         seqNo = 255;
      }
      else {
         seqNo = (uint8_t) qSelector;
      }
      if ( strcmp(argv[1], "-Q1") == 0 ) {
         Q2Selected = false;
      }
      else {
         Q2Selected = true;
      }
   }

   // Write filler values into memory buffer:
   prepBuffer();
   // Write representation of scrambled quotation into binary file and
   // into memory buffer:
   GenerateInput(binFileName, seqNo);
   
   // Call your implementation of Untangle() on the given memory region;
   // sending output to stdout:
   Untangle(quoteBuffer, stdout);

   return 0;
}

void prepBuffer() {
   
   quoteBuffer = malloc(BUFFER_SZ);
   if ( quoteBuffer == NULL ) {
      exit(1);
   }
   
   uint8_t* curr = quoteBuffer;
   while ( curr < quoteBuffer + BUFFER_SZ ) {
      *curr = FILL_VALUE;
      curr++;
   }
}
