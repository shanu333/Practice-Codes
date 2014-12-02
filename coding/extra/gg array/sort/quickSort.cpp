#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;
#define FOR(a, n) for (int i = a; i < n; i++)

void swap ( int* a, int* b )
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int a[], int size, int l, int h)
{
    int x = a[h];
    int i = (l - 1);

    for (int j = l; j <= h- 1; j++)
    {
        if (a[j] <= x)
        {
            i++;
            swap (&a[i], &a[j]);
        }
    }
    swap (&a[i + 1], &a[h]);
    return (i + 1);
}

void quickSort(int a[], int size, int l, int h)
{
    if (l < h) {
        int p = partition(a, size, l, h);
        quickSort(a, size, l, p - 1);
        quickSort(a, size, p + 1, h);
    }

}

int main()
{
    int n = 10,a[n];
    FOR(0, n) a[i] = rand()%10;
    quickSort(a, n, 0, n-1);
    FOR(0, n) cout << a[i] << " ";

    return 0;
}
