#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int main()
{
    bool a[20002];
    memset(a, 0, 20002);
    int g = 0;
    int q,p;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d", &p);
        if (a[p-1] == 0 && a[p+1] == 0) {
            g++;
        } else if ((a[p-1] == 1 && a[p+1] == 1))  {
            g--;
        }
        a[p] = 1;
        printf("%d\n", g);
    }
    printf("Justice\n");
    return 0;
}

