#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
#define pi pair<int, int>
#define fi first
#define se second

bool f(pi p1, pi p2)
{
    if (p1.se < p2.se) {
        return false;
    } else if (p1.se == p2.se) {
        if (p1.fi < p2.fi) {
            return true;
        }
        return false;
    }
    return true;
}
int main()
{
    pi a[1001];
    pair < pi , int> ans;
    pi t[1001];
    int n, k;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i].fi >> a[i].se;
    }

    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> t[i].fi;
        t[i].se = i + 1;
    }

    sort(a, a + n, f);
    sort(t, t + k);
    for (int i = k; i >= 0; i--) {

    }



    return 0;
}
