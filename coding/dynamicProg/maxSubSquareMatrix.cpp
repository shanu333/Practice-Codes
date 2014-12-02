#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int a[100][100], dp[100][100];
    int r, c;
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> a[i][j];
            dp[i][j] = 0;
        }
    }
    for (int i = 0; i < r; i++) {
        dp[i][0] = a[i][0];
    }

    for (int i = 0; i < c; i++) {
        dp[0][i] = a[0][i];
    }
    int maxx = 0;
    for (int i = 1; i < r; i++) {
        for (int j = 1; j < c; j++) {
            if (a[i][j] == 1) {
                cout << i << " " << j << endl;
                dp[i][j] = min(dp[i-1][j-1], min(dp[i][j-1], dp[i-1][j])) + 1;
                maxx = max(maxx, dp[i][j]);
            } else dp[i][j] = 0;
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << maxx << endl;

    return 0;
}
