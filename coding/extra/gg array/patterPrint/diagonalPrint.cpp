#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;
#define FOR(a, n) for (int i = a; i < n; i++)

#define ROW 5
#define COL 4
int min(int a, int b)
{ return (a < b)? a: b; }

// A utility function to find min of three integers
int min(int a, int b, int c)
{ return min(min(a, b), c);}

// A utility function to find max of two integers
int max(int a, int b)
{ return (a > b)? a: b; }
void diagonalOrder(int matrix[][COL])
{
    // There will be ROW+COL-1 lines in the output
    for (int line=1; line<=(ROW + COL -1); line++)
    {
        /* Get column index of the first element in this line of output.
           The index is 0 for first ROW lines and line - ROW for remaining
           lines  */
        int start_col =  max(0, line-ROW);

        /* Get count of elements in this line. The count of elements is
           equal to minimum of line number, COL-start_col and ROW */
         int count = min(line, (COL-start_col), ROW);

        /* Print elements of this line */
        for (int j=0; j<count; j++)
            printf("%5d ", matrix[min(ROW, line)-j-1][start_col+j]);

        /* Ptint elements of next diagonal on next line */
        printf("\n");
    }
}
int  main()
{
   int M[ROW][COL] = {{1, 2, 3, 4},
                       {5, 6, 7, 8},
                       {9, 10, 11, 12},
                       {13, 14, 15, 16},
                       {17, 18, 19, 20},
                      };



    return 0;
}
