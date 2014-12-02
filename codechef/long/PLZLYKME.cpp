#include <iostream>
#include <cstdio>

using namespace std;

double po(double a, int c)
{
    if (c == 0) {
        return 1;
    } else if (c == 1) {
        return a;
    } else {
        double d = po(a, c / 2);
        d = d * d;
        if (c%2) {
            d = d * a;
        }
        return d;
    }
}

int main()
{
    int t;
    double l, d, s, c, k;
    cin >> t;
    while (t--) {
        cin >> l >> d >> s >> c;
        k = po(1 + c, d - 1);
        k = k * s;
        if (k >= l) {
            printf("ALIVE AND KICKING\n");
        } else {
            printf("DEAD AND ROTTING\n");
        }
    }

    return 0;
}
