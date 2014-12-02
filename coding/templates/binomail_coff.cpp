#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

void pre(int MAX);
double ncr[10000][10000];

double get_ncr (int n, int r)
{
	if (r > n)
		return 0.0;
	else
		return ncr[n][r];
}

int main()
{
    int t,n,m,s,k,q;
    double p;
    scanf("%d", &t);
    pre(1000);
    while (t--) {
        scanf("%d%d%d%d", &s, &n, &m, &k);

        if (s == n) {
            printf("1.000000\n");
        } else if (n <= k) {
            printf("0.000000\n");
        } else {

            q = get_ncr (s-1, n - 1);
            p = 0.0;
            for (int i = k; i <= min(m-1, n-1);  i++) {
                p = p + get_ncr (m-1, i) * get_ncr (s-m, n-1-i);
            }
            p = p/q;
            printf("%0.8lf\n",p);
        }

    }

    return 0;
}

void pre(int MAX)
{

    ncr[0][0] = 1.0;
	for (int n = 1; n <= MAX; n++)
	{
		ncr[n][0] = 1.0;
		for (int r = 1; r < n; r++)
			ncr[n][r] = ncr[n-1][r-1] + ncr[n-1][r];
		ncr[n][n] = 1.0;
	}

}
