#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <climits>
using namespace std;
#define FOR(a, n) for (int i = a; i < n; i++)

void swap (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a[] = {1, 20, 4, 5};

    int n = sizeof(a)/sizeof(int);

    for (int i =  n - 1; i > 0; i--) {
        int j = rand()%(i+1);
        swap(a[j], a[i]);
    }
    FOR(0, n)cout << a[i] << " ";
    cout << endl;

    return 0;
}
