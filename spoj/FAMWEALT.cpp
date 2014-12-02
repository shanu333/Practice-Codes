#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int t;
    int x, y, w;
    int a[20];
    int d, z;
    scanf ("%d", &t);
    char prev = 'F';
    double mul, div, total_w;
    while (t--) {
        scanf("%d%d%d", &x, &y, &w);
        d = 0;

        z = x;
        while (z) {
            a[d++] = z % 2;
            z /= 2;
        }
        mul = 1;
        if (x == 1){
            mul = 1;
            goto l;
        }
        prev = 'F';
        for (int i = d - 2; i >= 0; i--) {
            if (prev == 'F') {
                if (a[i] == 0) {
                    mul = mul * 2;
                    prev = 'M';
                } else {
                    mul = mul * 4;
                    prev = 'F';
                }
            } else {
                if (a[i] == 0) {
                    mul  = mul * 2;
                    prev = 'M';
                } else {
                    mul = mul * 2;
                    prev = 'F';
                }
            }
        }
        l :
       // cout << mul << endl;
        total_w = mul * w;
        div = 1;
        d = 0;
        z = y;
        while (z) {
            a[d++] = z % 2;
            z /= 2;
        }
        if (y == 1) {
            div = 1;
            goto k;
        }
        prev = 'F';
        for (int i = d - 2; i >= 0; i--) {
            if (prev == 'F') {
                if (a[i] == 0) {
                    div = div * 2;
                    prev = 'M';
                } else {
                    div = div * 4;
                    prev = 'F';
                }
            } else {
                if (a[i] == 0) {
                    div  = div * 2;
                    prev = 'M';
                } else {
                    div = div * 2;
                    prev = 'F';
                }
            }
        }
        k :
        double ans = total_w / div;
        printf("%.6lf\n", ans);


    }

    return 0;
}
