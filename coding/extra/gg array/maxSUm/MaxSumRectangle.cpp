#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;
#define FOR(a, n) for (int i = a; i < n; i++)
#define ROW 4
#define COL 5
int kadane(int* arr, int* start, int* finish, int n)
{
    // initialize sum, maxSum and start
    int sum = 0, maxSum = INT_MIN, i;

    // needed if sum NEVER becomes less than 0
    *start = 0;

    // Standard Kadane's algorithm. See following link
    // http://www.geeksforgeeks.org/largest-sum-contiguous-subarray/
    for (i = 0; i < n; ++i)
    {
        sum += arr[i];
        if (sum < 0)
        {
            sum = 0;
            *start = i+1;
        }
        else if (sum > maxSum)
        {
            maxSum = sum;
            *finish = i;
        }
    }
    return maxSum;
}
void findMaxSum(int M[][COL])
{
    int temp[ROW], maxSum =INT_MIN, left, right, finalTop, finalBottom, finalRight, finalLeft;
    int start, finish,sum;
    for (left = 0; left < COL; left++)
    {
        memset(temp, 0, sizeof(temp));
        for (right = left; right < COL; right++) {
            for (int i = 0; i < ROW; i++) {
                temp[i] += M[i][right];
            }
            sum = kadane(temp, &start, &finish, ROW);
            if (sum > maxSum)
            {
                maxSum = sum;
                finalLeft = left;
                finalRight = right;
                finalTop = start;
                finalBottom = finish;
            }
        }

    }
    printf("(Top, Left) (%d, %d)\n", finalTop, finalLeft);
    printf("(Bottom, Right) (%d, %d)\n", finalBottom, finalRight);
    printf("Max sum is: %d\n", maxSum);
}
int main()
{
    int M[ROW][COL] = {{1, 2, -1, -4, -20},
                       {-8, -3, 4, 2, 1},
                       {3, 8, 10, 1, 3},
                       {-4, -1, 1, 7, -6}
                      };

    findMaxSum(M);

    return 0;
}
