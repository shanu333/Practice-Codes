#include <iostream>
#include <cstdio>

using namespace std;

unsigned  long long n, m, l, e1, e2;
unsigned long long  a[600][600];
int b[2500001], c[2500001];
int flag1, flag2;
unsigned long long haha(unsigned long long aa, unsigned long long bb)
{
    if (aa > bb) {
        return aa;
    }
    return bb;
}
int main()
{
    flag1 = 0;
    flag2 = 0;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    cin >> l;
    for (int i = 0; i < l; i++) {
        cin >> b[i] >> c[i];
    }
    e1 = 0;
    e2 = 0;
    for (int i = 0; i < l; i++) {
        if (b[i] > n || c[i] > m) {
            e1 = -1;
            flag1 = 1;
            break;
        } else {
            e1 += a[b[i] - 1][c[i] - 1];
        }
    }

    for (int i = 0; i < l; i++) {
        if (c[i] > n || b[i] > m) {
            e2 = -1;
            flag2 = 1;
            break;
        } else {
            e2 += a[c[i] - 1][b[i] - 1];
        }
    }
    if (flag1 == 0 && flag2 == 0) {
        cout <<  haha(e1, e2) << endl;;
    } else if (flag1 != 0 && flag2 == 0) {
        cout << e2 << endl;
    } else if (flag1 == 0 && flag2 != 0) {
        cout << e1 << endl;
    } else {
        cout << "-1\n";
    }



    return 0;
}
