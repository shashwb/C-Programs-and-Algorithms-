#include <stdio.h>
#include <stdlib.h>
#include "Rectangle.h"
#include "Rectangle.c"

void testRectangle();

//main method that will always run
int main(int argc, char** argv) {

   testRectangle();
   
   return 0;
}

void testRectangle() {
	
	//Declare rectangle objects to test with using RectangleInit.
	
	Rectangle rec1 = RectangleInit(2, 2, 2, 3);
    
    Rectangle recOverlap1 = RectangleInit(2, 2, 2, 3);
    Rectangle recOverlap2 = RectangleInit(3, 3, 2, 2);
    Rectangle recNoOverlap = RectangleInit(7, 7, 1, 1);
    
    Rectangle recIsIn1 = RectangleInit(2, 2, 3, 3);
    Rectangle recisIn2 = RectangleInit(3, 3, 1, 1);
    Rectangle recNotIn = RectangleInit(7, 7, 1, 1);
    
    Rectangle recEqual = RectangleInit(0, 1, 2, 3);
	
	Rectangle rec2 = RectangleInit(-1, 9, 1, 1);

	Rectangle rec3 = RectangleInit(-2, -3, 2, 3);
    
    Rectangle hulled1 = RectangleInit(2, 2, 2, 2);
    Rectangle hulled2 = RectangleInit(4, 4, 3, 3);
    
    
    
    
    Rectangle isIn1 = RectangleInit(20, -16, 32, 29);
    
    
    printf("\nTesting rectangle equality! %d\n", RectangleEquals(rec1, rec1));
    
    printf("\nTesting getting area of Rectangle! %d\n", RectangleArea(rec1));
    
    Rectangle rectangleScaled = RectangleScale(rec1, 3);
    printf("\nTesting scaling the rectangle from original point! new width:  %d  new height:  %d\n", rectangleScaled.Height, rectangleScaled.Width);
	
    Rectangle rectangleShifted = RectangleShift(rec1, UP, 2);
    printf("\nTesting shifting the rectangle's in a direction based on a distance  xCoordinate:  %d  yCoordinate:  %d\n", rectangleShifted.swX, rectangleShifted.swY);
    
    Rectangle rectangleFlipped = RectangleFlip(rec1, UP);
    printf("\nTesting RectangleFlip(): xCoordinate  %d  yCoordinate  %d\n", rectangleFlipped.swX, rectangleFlipped.swY);
    
    
    Rectangle rectangleRotated = RectangleRotate(rec1, SW, CLOCKWISE);
    printf("\nTesting RectangleArea(): xCoordiante  %d  yCoordinate  %d\n", rectangleRotated.swX, rectangleRotated.swY);

    
    uint32_t areaOfRectangle = RectangleArea(rec1);
    printf("\nTesting RectangleRotate(): areaOfRectangle  %d      ", areaOfRectangle);
    
    printf("\nTesting RectangleOverlap():  Do the following rectangles overlap (1 for true)?:  %d\n", RectangleOverlap(recOverlap1, recOverlap2));
    
    printf("\nTesting RectangleOverlap():  Do the following rectangles overlap (1 for true)?:  %d\n    ", RectangleOverlap(recOverlap1, recNoOverlap));
    
    printf("\nTesting RectangleIsIn(): is the first rectangle within the bounds of the second rectangle? (1 for true)?:  %d\n", RectangleIsIn(recisIn2, recIsIn1));
    
    printf("\nTesting RectangleIsIn(): is the first rectangle within the bounds of the second rectangle? (1 for true)?:  %d\n", RectangleIsIn(recNotIn, recIsIn1));
    
    printf("\nTesting RectangleIsIn(): is the first rectangle within the bounds of the second rectangle? (1 for true)?:  %d\n", RectangleIsIn(isIn1, isIn1));
    
    Rectangle rectangleHulled = RectangleHull(hulled1, hulled2);
    printf("\nTesting RectangleHull(): xCoordinate  %d  yCoordinate  %d  width  %d  height  %d", rectangleHulled.swX, rectangleHulled.swY, rectangleHulled.Width, rectangleHulled.Height);
    
    
    

//	printf("Testing Overlap\n");
//	RectangleOverlap(rec2, rec1);

}
