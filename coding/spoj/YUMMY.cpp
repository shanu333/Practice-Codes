#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int a[] = {	1, 1, 1, 4, 6, 19, 43, 120, 307, 866, 2336, 6588, 18373, 52119, 147700, 422016};

    long long int t, i = 1;
    int n;
    scanf("%lld", &t);
    while(t--) {
        scanf("%d", &n);
        printf("Case #%lld: %d\n", i++, a[n-1]);
    }
    return 0;
}
