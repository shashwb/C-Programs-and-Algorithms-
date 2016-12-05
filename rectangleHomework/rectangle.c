//
//  rectangle.c
//  
//
//  Created by Seth Balodi on 11/26/14.
//
//

#include <stdio.h>
#include "rectangle.h"




//****
/** this code is meant to create and return a Rectangle object with the specified attributes */
Rectangle RectangleInit(int32_t X, int32_t Y, uint32_t hDim, uint32_t vDim) {
    
    //declare a rectangle variable
    Rectangle rect;
    
    //set the struct options to the constructor parameters
    rect.swX = X;
    rect.swY = Y;
    rect.Width = hDim;
    rect.Height = vDim;

    
    return rect;
    
};


/** return true iff RL and RR represent the same rectangle. */
bool RectangleEquals(Rectangle RL, Rectangle RR) {
    
    if ((RL.swX == RR.swX) && (RL.swY == RR.swY)
        && (RL.Height == RR.Height) && (RL.Width == RR.Width)) {
        return true;
    }
    return false;
    
};


/** Returns true iff RL does not extend beyond the boundaries of RR */
bool RectangleIsIn(Rectangle RL, Rectangle RR) {
    int32_t largerNEX = RR.swX + RR.Width;
    int32_t largerNEY = RR.swY + RR.Height;
    
    int32_t smallerNEX = RL.swX + RL.Width;
    int32_t smallerNEY = RL.swY + RL.Height;
    
    if (RR.swY <= RL.swY &&
        RR.swX <= RL.swX &&
        largerNEX >= smallerNEX &&
        largerNEY >= smallerNEY) {
        return true;
    }
    return false;
};


/** Returns true iff RL and RR have at least one point in common, on the boundary or internally. **/
bool RectangleOverlap(Rectangle RL, Rectangle RR) {
    

    
    if      (!(RL.swX + RL.Width < RR.swX ||
             RL.swY + RL.Height < RR.swY ||
             RL.swX > RR.swX + RR.Width ||
             RL.swY > RR.swY + RR.Height)) {
        return false;
    }
    return true;
    
    
    
    
}


/** Returns the smallest rectangle that covers both RR and RL */
Rectangle RectangleHull(Rectangle RL, Rectangle RR) {
    


        Rectangle smallRect;
    
    
        int32_t smallRectNEX = 0;
        int32_t smallRectNEY = 0;
    
        int32_t RLneX = RL.swX + RL.Width;
        int32_t RLneY = RL.swY + RL.Height;
        int32_t RRneX = RR.swX + RR.Width;
        int32_t RRneY = RR.swY + RR.Height;
        
        if (RL.swX <= RR.swX) {
            smallRect.swX = RL.swX;
        }
        else {
            smallRect.swX = RR.swX;
        }
        
        if (RL.swY <= RR.swY){
            smallRect.swY = RL.swY;
        }
        else {
            smallRect.swY = RR.swY;
        }
        
        if (RLneX >= RRneX){
            smallRectNEX = RLneX;
        }
        else {
            smallRectNEX = RRneX;
        }
        
        if (RLneY >= RRneY){
            smallRectNEY = RLneY;
        }
        else {
            smallRectNEY = RRneY;
        }
        
        smallRect.Height = smallRectNEY - smallRect.swY;
        smallRect.Width = smallRectNEX - smallRect.swX;
        return smallRect;

    

}

/** Computes and returns the area of a Rectangle object. **/
uint32_t RectangleArea(Rectangle R) {
    
    //the area of a rectangle is just the length * height
    uint32_t areaOfRectangle = R.Height * R.Width;
    return areaOfRectangle;
    
}


/** Creates and returns a Rectangle object with the same SW corner as a given Rectangle object, but with dimensions scaled by a constant factor**/
Rectangle RectangleScale(Rectangle R, uint32_t sFactor) {
    
    uint32_t scaledHeight = R.Height * sFactor;
    uint32_t scaledWidth = R.Width * sFactor;
    R.Height = scaledHeight;
    R.Width = scaledWidth;

    return R;
}


/** creates and returns a Rectangle object corresponding to shifting a given Rectangle in the specified direction by the specified amount **/
Rectangle RectangleShift(Rectangle R, FlipDirection Dir, int32_t Distance) {
    
    
    if (Dir == UP) {
        R.swY = R.swY + Distance;
    }
    if (Dir == DOWN) {
        R.swY = R.swY - Distance;
    }
    if (Dir == LEFT) {
        R.swX = R.swX - Distance;
    }
    if (Dir == RIGHT) {
        R.swX = R.swX + Distance;
    }
    
    return R;
    
    
}


/** Creates and returns a Rectangle object corresponding to flipping a given Rectangle across an edge in the specified direction*/
Rectangle RectangleFlip(Rectangle R, FlipDirection Dir) {
    
    
    if (Dir == UP) {
        R.swY = R.swY + R.Height;
    }
    
    if (Dir == DOWN) {
        R.swY = R.swY - R.Height;
    }
    
    if (Dir == LEFT) {
        R.swX = R.swX - R.Width;
    }
    
    if (Dir == RIGHT) {
        R.swX = R.swX + R.Width;
    }
    
    return R;
}


/** Creates and returns a Rectangle object correspoinding to rotating a given Rectangle 90 degrees in the specified direction around the specified point. */
Rectangle RectangleRotate(Rectangle R, Pivot Center, RotDirection RotDir) {
    
    
    if (RotDir == CLOCKWISE) {
        if (Center == SW) {
            R.swY = R.swY - R.Width;
            uint32_t height = R.Height;
            R.Height = R.Width;
            R.Width = height;
        }
        if (Center == SE) {
            R.swX = R.swX + R.Width;
            uint32_t height = R.Height;
            R.Height = R.Width;
            R.Width = height;
        }
        if (Center == NE) {
            R.swX = R.swX + R.Width - R.Height;
            R.swY = R.swY + R.Height;
            uint32_t height = R.Height;
            R.Height = R.Width;
            R.Width = height;
            
        }
        if (Center == NW) {
            R.swX = R.swX - R.Height;
            R.swY = R.swY + R.Height - R.Width;
            
            uint32_t height = R.Height;
            R.Height = R.Width;
            R.Width = height;
        }
    }
    
    if (RotDir == COUNTERCLOCKWISE) {
        if (Center == SW) {
            R.swX = R.swX - R.Height;
            uint32_t height = R.Height;
            R.Height = R.Width;
            R.Width = height;
        }
        if (Center == SE) {
            R.swY = R.swY - R.Width;
            R.swX = R.swX + R.Width - R.Height;
            uint32_t height = R.Height;
            R.Height = R.Width;
            R.Width = height;
        }
        if (Center == NE) {
            R.swY = R.swY + R.Height - R.Width;
            R.swX = R.swX + R.Width;
            uint32_t height = R.Height;
            R.Height = R.Width;
            R.Width = height;
        }
        if (Center == NW) {
            R.swY = R.swY + R.Height;
            uint32_t height = R.Height;
            R.Height = R.Width;
            R.Width = height;
        }
    }
    
    return R;
    
}







