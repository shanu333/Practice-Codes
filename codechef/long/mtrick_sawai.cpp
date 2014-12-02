#include <iostream>
#include <cstdio>

using namespace std;

typedef unsigned long long int ll;
ll l[1009];

int main()
{
    int t, n, m = 10;
    ll mm, k, a, b, c, p, q, flag, add, factor, mul, temp, temp1, total, total1, tt, counter;
    char s;

    scanf("%d", &t);
    while(t--) {
        flag = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%llu", &l[i]);
        }
        scanf("%llu%llu%llu", &a, &b, &c);
        getchar();

        for (int i = 0; i < n; i++) {
            l[i] %= c;
        }
        a %= c;
        b %= c;
        p = 0;
        q = n-1;
        add = 0;
        mul = 1;
        for (int i = 0; i < n; i++) {
            scanf("%c", &s);
            if (s == 'A') {
                add = (add+a)%c;

            } else if (s == 'M') {
                counter = 0;
                k = b;
                total = 0, total1 = 0;
                while(k) {
                    tt = k % 10;
                    temp = (mul*tt) % c;
                    temp1 = (add*tt) % c;

                    for (int p = 0; p < counter; p++) {
                        temp = (temp*10) % c;
                        temp1 = (temp1*10) % c;
                    }

                    total = (total + temp) % c;
                    total1 = (total1 + temp1) % c;

                    k = k / 10;
                    counter++;
                }
                mul = total;
                add = total1;
            } else if (s == 'R') {
                if (flag == 0) {
                    flag = 1;
                } else {
                    flag = 0;
                }
            }
            if (flag == 0) {
                factor = l[p];
                p++;
            } else {
                factor = l[q];
                q--;
            }

            counter = 0;
            k = mul;
            total = 0;
            while(k) {
                tt = k % 10;
                temp = (factor*tt) % c;
                for (int p = 0; p < counter; p++) {
                    temp = (temp*10) % c;
                }
                total = (total + temp) % c;
                k = k / 10;
                counter++;
            }

            factor = total;
            factor = (factor + add) % c;

            if (i == n-1) {
                printf("%llu\n", factor);
            } else {
                printf("%llu ", factor);
            }
        }
    }

    return 0;
}
