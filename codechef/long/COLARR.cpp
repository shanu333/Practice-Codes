#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;
int b[1005][1005];
int c[1005][1005];
int main()
{
    int a[1005];
    int d[1005];
    int n, t, m ,k ;

    ios_base::sync_with_stdio(false);
    cin >> t;
    while (t--) {
        cin >> n >> m >> k;

        for (int i = 0; i < n; i++){
            cin >> a[i];
            a[i]--;
            d[i] = 0;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> b[i][j];
            }
        }

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += b[i][a[i]];
            for (int j = 0; j < m; j++) {
                cin >> c[i][j];
                if (b[i][j] - c[i][j] > 0){
                    d[i] = max(d[i], b[i][j] - c[i][j]);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (b[i][a[i]] > d[i]) {
                d[i] = 0;
            } else {
                d[i] = d[i] - b[i][a[i]];
            }
        }
        sort(d, d + n);
        if (k > n) k = n;
        for (int i = n - 1; i >= (n - k); i--) {
            if (d[i] > 0) {
                ans += d[i];
            }
        }
        cout << ans << endl;

    }

    return 0;
}
