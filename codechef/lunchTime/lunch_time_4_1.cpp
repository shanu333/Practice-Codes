#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

long long int mini(long long int a, long long int b, long long int c)
{
    return min(a, min(b,c));
}

long long int maxi(long long int a, long long int b, long long int c)
{
    return max(a, max(b,c));
}

int main()
{
        long long int t;
        long long int n, a, b, min_a, max_a;

        scanf("%lld", &t);
        while (t--) {
            scanf("%lld%lld", &n, &a);
            min_a = a;
            max_a = a;
            for (long long int i = 1; i < n; i++) {
                scanf("%lld", &b);
                min_a = min(min_a, mini(min_a + b, min_a - b, min_a * b));
                min_a = min(min_a, mini(max_a + b, max_a - b, max_a * b));

                max_a = max(max_a, maxi(min_a + b, min_a - b, min_a * b));
                max_a = max(max_a, maxi(max_a + b, max_a - b, max_a * b));

            }


            cout << min_a << endl;
        }


    return 0;
}
