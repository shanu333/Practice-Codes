#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <iostream>
int main()
{
    int k,t;
    long  long  int  l, index;
    double sum;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%lld", &l);
        if (l <= 3)
            printf("1\n");
        else {
                  sum = 0;   /* log(1) + ... + log(N-1) + log(N) */
            for (index = 1; index <= l; index++) {
                sum = sum + log10((double) index);
            }
            /* CEILING[(log(1) + ... + log(N-1) + log(N))] */
            k = sum;
            printf("%d\n", k+1);
        }

    }



    return 0;
}
