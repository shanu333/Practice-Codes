#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define mod 1000000007

vector<vector<long long > > v(5001);
long long  a[100001];

int main()
{
    long long  n, k;
    scanf("%lld%lld", &n, &k);
   // v.resize(n);
    v[0].resize(k);
    for (long long  i = 0; i < k; i++) {
        v[0][i] = -1;
    }
    scanf("%lld", &a[0]);
    v[0][a[0]-1] = 0;
    for (long long  i = 1; i < n; i++) {
        scanf("%lld", &a[i]);
        v[i].resize(k);
        v[i] = v[i-1];
        v[i][a[i] - 1] = i;
    }
//    for (long long  i = 0; i < n; i++) {
//        for (long long  j = 0; j < k; j++) {
//            cout << v[i][j] << " ";
//        }
//        cout << endl;
//    }
//    cout << endl;

    long long fear = 1;
    for (long long  i = 1; i < n; i++) {
        long long  local_fear = 1;
        for (long long  j = a[i]; j < k; j++) {
            if (v[i-1][j] >= 0) {
                local_fear = i - v[i-1][j] + 1;
               // cout << "local = " << i << " " << local_fear << endl;
                fear = (fear * local_fear)%mod;
            }
        }

    }
    cout << fear << endl;

    return 0;
}
