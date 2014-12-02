#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
#include <cmath>
using namespace std;
int hcf(int a, int b)
{
    int m ,i,n;
    if(a > b){
        m = b;
        n = a;
    } else {
        n = b;
        m = a;
    }
    int qu = n;
    int remainder;
    while(1){
        qu = n / m;
        remainder = n%m;
        if(!remainder){
            break;
        }
        n = m;
        m = remainder;

    }
    return m;
}
int main()
{
    long long int t,a,b,c;
    int i;
    scanf("%lld", &t);
    while(t--)  {
        scanf("%lld%lld", &a, &b);

        b = hcf(a,b);
        c = 0;
        for (i = 1; i*i < b; i++) {
            if (b%i == 0) {
                c = c + 2;
            }
        }
        if (i*i == b)
            c++;
        printf("%lld\n",c);
    }
    return 0;
}

