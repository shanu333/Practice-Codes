    #include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int n;
int q;
int x1, x2, y1, y2;
int a[500][500];

int x[500][500][10];
int y[500][500][10];

void print(int t)
{
    if (t == 1) {
            for (int i = 0; i < n ; i++) {
                for (int j = 0; j <= n; j++) {
                    for (int k = 0; k < 11; k++) {
                        cout << " " << x[i][j][k] << " ";
                    }
                    cout << endl;
                }
                cout << endl;
            }
            cout << endl;
            cout <<"As\n";
    } else {

            for (int i = 0; i <= n; i++) {
                for (int j = 0; j < n; j++) {
                    for (int k = 0; k < 11; k++) {
                        cout << " " << y[i][j][k] << " ";
                    }
                    cout << endl;
                }
                cout << endl;
            }
            cout << endl;

    }
}

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }

    }


    for (int i = 0; i < n ; i++) {
        for (int k = 0; k < 11; k++) {
            x[i][0][k] = 0;
        }
        for (int j = 1; j <= n; j++) {
            for (int k = 0; k < 11; k++) {
                x[i][j][k] = x[i][j-1][k];
            }
            x[i][j][a[i][j-1]]++;
           // cout <<"as " <<  x[i][j][a[i][j-1]] << endl;
        }
    }

//    for (int i = 0; i < n; i++) {
//        for (int k = 0; k < 11; k++){
//            y[0][i][k] = 0;
//        }
//        for (int j = 1; j <= n; j++) {
//            for (int k = 0; k < 11; k++) {
//                y[j][i][k] = y[j-1][i][k];
//            }
//            y[j][i][a[j-1][i]]++;
//            cout << "df " << y[j][i][a[j-1][i]] << endl;
//        }
//    }

    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);

        bool cnt[11];
        memset(cnt, 0, sizeof(cnt));
        if ()
        for (int j = x1 - 1; j < x2; j++) {
            for (int k = 0; k < 11; k++) {
                if (x[x2-1][y2][k] - x[j][y1 - 1][k]) {
                    cnt[k] = 1;
                }
            }
        }
        int h = 0;
        for (int k = 0; k < 11; k++) {
            if (cnt[k] == 1) {
                h++;
            }
        }
        printf("%d\n", h);

    }





    return 0;
}
