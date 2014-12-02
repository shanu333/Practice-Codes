#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct Tree
{
        long long  sum;
};


Tree T[3000005], result;
long long v[1000005];

void create(int node, int i, int j)
{
    if (j == i) {
        T[node].sum = v[i];
    } else {
        create(2 * node + 1, i , (i + j)/2);
        create(2 * node + 2, (i + j)/2 + 1, j);
        T[node].sum = T[2*node + 1].sum + T[2*node + 2].sum;
    }
}
/** i , j -> query nodes
    s, e  -> actual index of movements
**/
long long int   sum(int node, int s, int e, int i, int j)
{
    if (i <= s && j >= e) {
        return T[node].sum;
    } else if (e < i || s > j) {
        return 0;
    } else {
        return (sum(2 * node + 1, s, (s + e)/2, i, j) + sum(2 *node + 2, (s + e) / 2, e, i, j));
    }
}

int main()
{
    int n, k, s, e;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    create(0, 0, n - 1);
    scanf("%d", &k);
    for(int i = 0; i < 3 * n; i++ ) {
        cout <<
    }
//    for (int i = 0; i < k; i++) {
//        scanf("%d", &s, &e);
//        printf("%lld\n", sum(0, 0, n - 1, s , e));
//    }

    return 0;
}
