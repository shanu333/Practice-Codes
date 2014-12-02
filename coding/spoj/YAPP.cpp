#include <iostream>
#include <cstdio>
#include <cmath>
#include <climits>
#include <vector>
using namespace std;

#define mod 1000000007

long long int f(long long int x)
{

    if (x <= 1) {
        return pow(2, x);
    } else {
        long long int z = f(x/2);
        z = (z * z) % mod;
        if (x % 2 != 0) {
            z = (z * 2) % mod;
        }
        return z;
    }
}

int main()
{
    int t;
    long long int n;
    scanf("%lld", &t);
    while (t--) {
        scanf("%lld", &n);
        n--;
        printf("%lld\n", f(n));
    }
    return 0;

}
