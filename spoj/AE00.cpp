#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
		long long int n;
		long long int cnt = 0;
		scanf("%lld", &n);
		for (int i = 1 ; i <= n; i++) {
			for (int j = i; j <= n; j++) {
				if (i * j <= n) {
					cnt++;
				} else {
					break;
				}
			}
		}
		printf("%lld\n", cnt);
    return 0;
}
