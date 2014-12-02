    #include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
int n;
int q;
int x1, x2, y1, y2;
int a[500][500];

int X[500][500][10];


int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 10; k++) {
                if (a[i][j] == k) {
                    X[i + 1][j + 1] = X[i][j+1] + X[i+1][j] - X[i][j] + 1;
                } else {
                    X[i + 1][j + 1] = X[i][j+1] + X[i+1][j] - X[i][j] + 1;
                }
            }
        }
    }




    return 0;
}
