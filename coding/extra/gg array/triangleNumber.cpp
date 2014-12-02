#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <climits>
#include <string>
#include <numeric>

using namespace std;
#define FOR(a, n) for (int i = a; i < n; i++)
bool f(int i,int j) { return (i<j); }
void swap (int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a[] = {1, 20, 4, 5};
    int count=0;
    int n = sizeof(a)/sizeof(int);
    sort(a, a+n,f);

    for (int i = 0; i < n -2; i++) {
        int k = i + 2;
        for (int j = i+1; j < n; j++) {
            while (k < n && a[i] + a[j] > a[k])
               ++k;
            count += k - j - 1;
        }
    }
    cout << count << endl;
    return 0;
}

