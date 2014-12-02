#include <iostream>
#include <cstdio>

using namespace std;
int a[1000000];
int main()
{
    int n, k, l, r, sa, sk;

    scanf("%d%d%d%d%d%d", &n, &k, &l, &r, &sa, &sk);

    int snk = sa - sk;
    for (int i =  0; i < k; i++) {
        a[i] = sk/k;
        //cout << a[i] << endl;
    }
    if (sk % k != 0) {
        sk = sk % k;
      //  cout << sk << endl;
    } else {
        sk = 0;
    }


    for (int i = 0; i < sk; i++) {
        a[i] += 1;
    }
    if (n - k == 0 ) {
        goto l;
    }
    for (int i =  k; i < n; i++) {
        a[i] = snk/(n-k);
    }
    if (snk % (n-k) != 0) {
        snk = snk % (n-k);
    } else {
        snk = 0;
    }

    for (int i = k; i <k +  snk; i++) {
        a[i] += 1;
    }
l:
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}
