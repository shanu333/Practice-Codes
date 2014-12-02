#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int a[1000333];
long long x;
int i, j, n, m, l, r, y, failed, succes;

int main()
{
	cin >> n >> x;
	for (i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + n + 1);
	failed = n;
	for (i = 1; i <= n; i++)
		if ((a[i] + 1) / 2 <= x)
		{
			x -= (a[i] + 1) / 2; // itne task aur kar sakte hain ..
			a[i] -= (a[i] + 1) / 2;// itna ho chuka hai
			failed--;// yeh fail nahi hua
		}
	for (i = 1; i <= n; i++)
		if (a[i] <= x)
		{
			x -= a[i];
			succes++;
		}
	printf("%d %d\n", failed, succes);
}
