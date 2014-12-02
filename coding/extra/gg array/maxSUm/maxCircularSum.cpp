#include <iostream>
#include <cstdio>

using namespace std;

int kadane (int a[], int n)
{
    int max_so_far = 0, max_ending_here = 0;
    int i;
    for(i = 0; i < n; i++)
    {
        max_ending_here = max_ending_here + a[i];
        if(max_ending_here < 0)
            max_ending_here = 0;
        if(max_so_far < max_ending_here)
            max_so_far = max_ending_here;
    }
    return max_so_far;
}
int maxCircularSum (int a[], int n)
{
    int maxKadane = kadane(a, n), maxWrap=0;
    for (int i = 0;  i < n; i++) {
        maxWrap += a[i];
        a[i] *= -1;
    }
    cout << kadane(a, n);
    maxWrap += kadane(a, n);
    cout << "maxWrap = " << maxWrap << " maxkadane = " << maxKadane << endl;
    return (maxWrap > maxKadane) ? maxWrap : maxKadane;
}
int main()
{
    int a[] =  {10 , -12, 11};
    int n = sizeof(a)/sizeof(a[0]);
    printf("Maximum circular sum is %d\n", maxCircularSum(a, n));
    return 0;

}
