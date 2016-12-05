//
//  HW04Q2.c
//  
//
//  Created by Seth Balodi on 10/16/14.
//
//

#include <stdio.h>

#define MAXLENGTH 100


//example input
//9040-12345 83:97:63:88:72:91:79:56
//9040-38532 56:63:71:55:72:81::
//9030-73014 79:93:89:97:85:91:88:95
//9040-00132 :::::::

//example output
//904012345: 78.62 on 8 assignments
//904038532: 66.33 on 6 assignments
//903073014: 89.62 on 8 assignments
//904000132: no score data was read


int main()
{
    char lineArray[MAXLENGTH];                          //make an array of characters to store the file
    int id1, id2, a, b, c, d, e, f, g, h = 0;           //allocate space for three variables
    
    FILE* fp = fopen("ScoreData.txt", "r");             //open the file "ScoreData.txt"
    FILE* ofp = fopen("Results.txt", "w");
    if (fp == NULL)
    {
        fprintf(ofp, "Error opening file ScoreData.txt.\n");
        return 1;
    }
    
    
    while (fgets(lineArray, MAXLENGTH, fp) != NULL)
    {
        
        if (sscanf(lineArray, "%d-%d    %d:%d:%d:%d:%d:%d:%d:%d", &id1, &id2, &a, &b, &c, &d, &e, &f, &g, &h) == 10)
        {
            float average = ((a + b + c + d + e + f + g + h) / 8.0f);
            fprintf(ofp, "%04d%05d:    %.2f on 8 assignments\n", id1, id2, average);
        }
        
        if (sscanf(lineArray, "%d-%d    %d:%d:%d:%d:%d:%d:%d:%d", &id1, &id2, &a, &b, &c, &d, &e, &f, &g, &h) == 9)
        {
            fprintf(ofp, "%04d%05d:    %.2f on 7 assignments\n", id1, id2, ((a + b + c + d + e + f + g) / 7.0f));
        }
        
        if (sscanf(lineArray, "%d-%d    %d:%d:%d:%d:%d:%d:%d:%d", &id1, &id2, &a, &b, &c, &d, &e, &f, &g, &h) == 8)
        {
            fprintf(ofp, "%04d%05d:    %.2f on 6 assignments\n", id1, id2, ((a + b + c + d + e + f) / 6.0f));
        }
        
        if (sscanf(lineArray, "%d-%d    %d:%d:%d:%d:%d:%d:%d:%d", &id1, &id2, &a, &b, &c, &d, &e, &f, &g, &h) == 7)
        {
            fprintf(ofp, "%04d%05d:    %.2f on 5 assignments\n", id1, id2, ((a + b + c + d + e ) / 5.0f));
        }
        
        if (sscanf(lineArray, "%d-%d    %d:%d:%d:%d:%d:%d:%d:%d", &id1, &id2, &a, &b, &c, &d, &e, &f, &g, &h) == 6)
        {
            fprintf(ofp, "%04d%05d:    %.2f on 4 assignments\n", id1, id2, ((a + b + c + d) / 4.0f));
        }
        
        if (sscanf(lineArray, "%d-%d    %d:%d:%d:%d:%d:%d:%d:%d", &id1, &id2, &a, &b, &c, &d, &e, &f, &g, &h) == 15)
        {
            fprintf(ofp, "%04d%05d:    %.2f on 3 assignments\n", id1, id2, ((a + b + c) / 3.0f));
        }
        
        if (sscanf(lineArray, "%d-%d    %d:%d:%d:%d:%d:%d:%d:%d", &id1, &id2, &a, &b, &c, &d, &e, &f, &g, &h) == 4)
        {
            fprintf(ofp, "%04d%05d:    %.2f on 2 assignments\n", id1, id2, ((a + b) / 2.0f));
        }
        
        if (sscanf(lineArray, "%d-%d    %d:%d:%d:%d:%d:%d:%d:%d", &id1, &id2, &a, &b, &c, &d, &e, &f, &g, &h) == 3)
        {
            fprintf(ofp, "%04d%05d:    %.2f on 1 assignments\n", id1, id2, (a/1.0f));
        }
        
        if (sscanf(lineArray, "%d-%d    %d:%d:%d:%d:%d:%d:%d:%d", &id1, &id2, &a, &b, &c, &d, &e, &f, &g, &h) == 2)
        {
            fprintf(ofp, "%04d%05d:    no score data was read\n", id1, id2);
        }
        
    }
    
    if (!feof(fp))
    {
        printf("Failed to read to end of file. \n");
    }
    
    fclose(fp);
    return 0;
    
}





// On my honor:
//
// - I have not discussed the C language code in my program with
// anyone other than my instructor or the teaching assistants
// assigned to this course.
//
// - I have not used C language code obtained from another student,
// or any other unauthorized source, either modified or unmodified.
//
// - If any C language code or documentation used in my program
// was obtained from an allowed source, such as a text book or course
// notes, that has been clearly noted with a proper citation in
// the comments of my program.
//
// Seth Balodi
