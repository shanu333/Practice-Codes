#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int a[500][500];
int f[500][500][10];
int q;
int res[10];
bool chck()
{
    for (int i = 0; i < 10; i++) {
        if (!f[i]) {
            return false;
        }
    }
    return true;
}

int main()
{
    int n,  x1, x2, y1, y2;
    scanf("%d", &n);
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < 10; j++) {
            f[0][i][j] = 0;
            f[i][0][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            scanf("%d", &a[i][j]);
            for (int k = 0; k < 10; k++) {
                f[i][j][k] = f[i][j-1][k];
            }
            f[i][j][a[i][j] - 1]++;
        }
    }

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            cout << " i = " << i << " j = " << j << endl;
            for (int k = 0; k < 10; k++) {
                cout  << f[i][j][k] << " ";
            }
            cout << "\n";
        }
        cout << "\n\n";
    }

    scanf("%d", &q);
    for (int l = 0; l < q; l++) {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

        memset(res, 0, sizeof(res));
        for (int i = y1; i <= y2; i++) {
            //cout << "\t i = " << i << endl;
            for (int j = 0; j < 10; j++) {
              //  cout << j << " " << f[x2][i][j]  << " , "  <<  f[x1][i][j] << endl;
                res[j] += (f[x2][i][j] - f[x1-1][i][j]);
            }
            //cout << endl;
        }
        int cnt = 0;
        cout << endl;
        for (int i = 0; i < 10; i++) {
            cout << res[i] << " ";
            if (res[i] > 0) {
                cnt++;
            }
        }
        printf("%d\n", cnt);
    }

    return 0;
}
