#include <iostream>
#include <cstdio>
using namespace std;

int n, t;
unsigned long long v[10000];
char s[10000];

unsigned long long a, b, c, z, add, mul, ans;

unsigned long long MUL(unsigned long long a, unsigned long long b)
{
    unsigned long long int  cnt = 0, tmp, total = 0;
    while(b)
    {
        tmp = b % 10;
        tmp = (a * tmp)%c;
        for (int i = 0; i < cnt; i++) {
            tmp = (tmp * 10)%c;
        }
        total = (total + tmp)%c;
        cnt++;
        b /= 10;
    }
    return total;

}

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%llu", &v[i]);

        }
        scanf("%llu%llu%llu", &a, &b, &c);
        scanf("%s", s);
        a %= c;
        b %= c;
        add = 0;
        mul = 1;

        int flag = 0;
        int p = 0;
        int q = n - 1;
        for (int i = 0; i < n; i++) {
            v[i] %= c;

        }
        for (int i = 0; i < n; i++) {
            if (s[i] == 'R') {
                if (flag == 0) {
                    flag = 1;
                } else {
                    flag = 0;
                }
            } else if (s[i] == 'A') {
                add = (add + a)%c;
            } else if (s[i] == 'M') {
                // multiply in both add variavle and multiply vairable
                /** i.e. multiplication by b in both**/
                add = MUL(add, b);
                mul = MUL(mul, b);
            }
            if (flag == 0) {
                // front move
                ans = MUL(v[p], mul);
                ans = (ans + add) % c;
                p++;
            } else {
                ans = MUL(v[q], mul);
                ans = (ans + add) % c;
                q--;
            }
            printf("%llu ", ans);
        }
        printf("\n");

    }


    return 0;
}
