#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>

#include "BinaryInt.h"

void testAdd();

int main(int argc, char** argv) {

   testAdd();
   
   return 0;
}

void testAdd() {
   uint8_t Sum[32];
   uint8_t Left[32];
   uint8_t Right[32];
   
   uint32_t first = 83647;
   uint32_t second = -3647;
   
   BI_Create(Right, first);
   BI_Create(Left, second);
   
   
   
   bool val = BI_Add(Sum, Left, Right);

   for (int i = 31; i > -1; i--)
	{
		printf("%d", Right[i]);
	}
	printf("\n");
	for (int i = 31; i > -1; i--)
	{
		printf("%d", Left[i]);
	}
	printf("\n");
	for (int i = 31; i > -1; i--)
	{
		printf("%d", Sum[i]);
	}
	printf("\n");
	if (val == false) printf("Overflow Occured.\n");
}
