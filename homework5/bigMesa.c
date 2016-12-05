// bigMesa.c
// Seth Balodi
// Homework 5
// Fall 2014


#define MIN_MESA_LENGTH 5

/**
 *  Given an array of nonnegative integers, a mesa is a sequence of 5 or
 *  more identical values.  The length of a mesa is the number of values
 *  in the sequence, and the mass of a mesa is the sum of the values in
 *  the sequence.
 *
 *  bigMesa() determines the mesa of maximum mass in the array that is
 *  passed into it.  bigMesa() reports its results by setting three extern
 *  variables:  mesaStart, mesaEnd and mesaMass.
 *
 * Pre:  A[0:A_Size - 1] are nonnegative integers.
 * Post: mesaStart = index of first element of most massive mesa
 *       mesaEnd   = index of last element of most massive mesa
 *       mesaMass  = sum of elements in most massive mesa
 *       All are set to zero if no mesa is found.
 *
 * Restrictions:
 *    You may not use a second array.
 */
void bigMesa(int A[], int A_Size) {
    
    // Link to the caller-supplied variables to report results:
    extern int mesaMass;
    extern int mesaStart;
    extern int mesaEnd;
    
    // Set default values in case no mesa is found in the array:
    mesaMass  = 0;
    mesaStart = 0;
    mesaEnd  = 0;
    
    int previousMesa;
    int startOfNewMesa;
    
    
    // we need to go through the elements in the array to begin with
    // in order to do this, we have to set the starting value to 0.
    //VALUE represents the current index
    int value = 0;
    // because we have to count the number of times a value is repeated for the mesa, we need a counter
    // variable available
    int counter = 0;
    
    //so while the VALUE (current index) is less than the index of the size of the array - 1
    //the following code will execute
    while (value < A_Size - 1)
    {
        //now, if the value at an index is equal to the value at the next index,
        if (A[value] == A[value + 1])
        {
            //the counter must be increased, because that would mean there are equal values right
            //next to each other.
            counter++;
            
            //now, if the counter finally makes it to greater than or equal to 4, run the following,
            if (counter >= 4)
            {
                //we store the value of the mesa that we currently are at in this variable and it
                //goes out into the extern field. When we finally go through and the if statement
                //breaks, then the start of the new mesa will be new and the counter will be reset
                //so the entire cycle will begin again. It will eventually run back into this point,
                //at which point it will recalculate the current mesa that it is on.
                previousMesa = A[value] * (counter + 1);

                //finally, the last if statement basically asks whether or not the mesaMass that has
                //already been calculated from a previous mesa is less than the current mesa found now
                //if this is the case, then replace the value of mesaMass with the mesa that is bigger
                //and continue the cycle. 
                if (mesaMass < previousMesa)
                {
                    mesaStart = startOfNewMesa + 1;
                    mesaMass = previousMesa;
                    mesaEnd = value + 1;
                    
                }
            }
        }

        else
        {
            //make the start of the new mesa equal the current value that it is on, and the code will
            //run again because of the while statement
            startOfNewMesa = value;
            //the counter has to be reset, however, so it can count the amount of matches again
            counter = 0;
        }
        //no matter what, the value must always increment upwards so that the while condition
        //will eventually terminate
        value++;
    }
}






//    On my honor:
//
// - //
//
//
// - //
//
// - //
//I have not discussed the C language code in my program with anyone other than my instructor or the teaching assistants assigned to this course.
//I have not used C language code obtained from another student, or any other unauthorized source, either modified or unmodified.
//If any C language code or documentation used in my program
//was obtained from an allowed source, such as a text book or course notes, that has been clearly noted with a proper citation in
//the comments of my program.
//
//
//
//    Seth Balodi

    
    
    
        
