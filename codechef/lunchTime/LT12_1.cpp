#include <iostream>
#include <cstdio>
#include <vector>

#define N 100000

using namespace std;

long long modd(long long j)
{
    if (j < 0) return -j;
    return j;
}

int  main()
{


    long long a[N];
    long long t;
    long long k;
    long long n;
    long long ans;
    long long cnt;
    cin >> t;
    while (t--) {
        cnt = 0;

        cin >> n >> k;
        for (long long i = 0; i < n; i++) {
            cin >> a[i];
        }
        ans = modd(a[0] + a[1] - k);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int l = modd(a[i] + a[j] - k);

                if (l < ans) {
                    ans = l;
                    cnt = 1;
                } else if (l == ans) {
                    cnt++;
                }
            }
        }
        cout << ans << " " << cnt << endl;

    }
}
