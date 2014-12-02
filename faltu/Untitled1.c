#include <stdio.h>

int m(int a[][4])
{
    a[0][0] = 100;
    a[2][0] = 100;
}
int main(){
    int a[4][4];
    int i;
    for (i = 0; i < 4; i++) {
        a[i][i] = 1;
    }
    for (i = 0; i < 4; i++) {
        printf("%d ", a[i][i]);
    }
    printf("\n");
    m(a);

    for (i = 0; i < 4; i++) {
        printf("%d ", a[i][i]);
    }
    printf("\n");
    return 0;
}
