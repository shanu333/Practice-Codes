#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;


long long a[100005];
int main()
{
    long long int t, n;
    scanf("%lld", &t);
    while (t--) {
        scanf("%lld", &n);
        for( int i = 0; i < n; i++) {
            scanf("%lld", &a[i]);
        }
        //sort(a, a + n);
        long long ans = n * n;
        ans = ans - (n *( n + 1))/2;
        cout << ans << endl;
    }

    return 0;
}
