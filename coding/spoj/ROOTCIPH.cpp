#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    long long int t, a, b, c;
    scanf("%lld", &t);
    while(t--) {
        scanf("%lld%lld%lld", &a, &b, &c);
        a = a * a;
        b = -2 * b;
        printf("%lld\n", a+b);
    }
    return 0;
}
