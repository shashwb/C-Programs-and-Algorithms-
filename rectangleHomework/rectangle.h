#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <stdint.h>
#include <stdbool.h>

//hull get all 4 corners and compare what is bigger and what is less


//  Represents a rectangle by storing the integer coordinates of its lower-left
//  (southwest) corner, its height (vertical dimension), and its width (horizontal
//  dimension).
struct _Rectangle {
    
    int32_t swX;
    int32_t swY;
    uint32_t Height;
    uint32_t Width;
};
typedef struct _Rectangle Rectangle;

//  Represents the possible directions in which a Rectangle object can be
//  flipped across an edge or shifted (parallel to the Cartesian axes).
enum Direction {UP, DOWN, LEFT, RIGHT};
typedef enum Direction FlipDirection;
typedef enum Direction ShiftDirection;

//  Represents the possible directions in which a Rectangle object can be
//  rotated about a corner.
enum Rotation {CLOCKWISE, COUNTERCLOCKWISE};
typedef enum Rotation RotDirection;

//  Represents the possible pivot points around which a Rectangle object
//  can be rotated.
enum Corner {SW, SE, NE, NW};
typedef enum Corner Pivot;

/**
 *   Creates and returns a Rectangle object with the specified attributes.
 */
Rectangle RectangleInit(int32_t X, int32_t Y, uint32_t hDim, uint32_t vDim);

/**  Returns true iff RL and RR represent the same rectangle.
 */
bool RectangleEquals(Rectangle RL, Rectangle RR);

/**  Returns true iff RL does not extend beyond the boundaries of RR.
 */
bool RectangleIsIn(Rectangle RL, Rectangle RR);

/**  Returns true iff RL and RR have at least one point in common,
 *   on the boundary or internally.
 */
bool RectangleOverlap(Rectangle RL, Rectangle RR);

/**  Returns smallest Rectangle that covers both RR and RL.
 */
Rectangle RectangleHull(Rectangle RL, Rectangle RR);

/**
 *   Computes and returns the area of a Rectangle object.
 */
uint32_t RectangleArea(Rectangle R);

/**
 *   Creates and returns a Rectangle object with the same SW corner as a given
 *   Rectangle object, but with dimensions scaled by a constant factor.
 */
Rectangle RectangleScale(Rectangle R, uint32_t sFactor);

/**  Creates and returns a Rectangle object corresponding to shifting a given
 *   Rectangle in the specified direction by the specified amount.
 */
Rectangle RectangleShift(Rectangle R, ShiftDirection Dir, int32_t Distance);

/**
 *   Creates and returns a Rectangle object corresponding to flipping a given
 *   Rectangle across an edge in the specified direction.
 */
Rectangle RectangleFlip(Rectangle R, FlipDirection Dir);

/**
 *   Creates and returns a Rectangle object corresponding to rotating a
 *   given Rectangle 90 degrees in the specified direction around the
 *   specified point.
 */
Rectangle RectangleRotate(Rectangle R, Pivot Center, RotDirection RotDir);

#endif