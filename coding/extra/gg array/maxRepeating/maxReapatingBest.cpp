#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>
using namespace std;
#define FOR(n) for (int i = 0; i < n; i++)


void sawap(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}

int  main()
{
    int a[] = {2, 3, 3, 5, 3, 4, 1, 7};
    int n = sizeof(a)/sizeof(int);
    int k = 8;
    FOR(n) {
        a[a[i]%k] += k;
    }
    int max = 0,res=0;
    FOR(n) {
        if (max < a[i]) {
            max = a[i];
            res=i;
        }
    }
    cout << res << endl;;



    return 0;
}
