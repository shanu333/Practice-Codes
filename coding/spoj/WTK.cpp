#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cstdio>

using namespace std;
int r = 0;
int josephus(int n, int k)
{
   // r++;
  if (n == 1)
    return 1;
  else
    /* The position returned by josephus(n - 1, k) is adjusted because the
       recursive call josephus(n - 1, k) considers the original position
       k%n + 1 as position 1 */

    return (josephus(n - 1, k+1) + k) % n + 1;
}

int main()
{
	int n, t, d;
	scanf("%d", &t);
	while(t--) {
        scanf("%d", &n);
        printf("%d\n",josephus(n,0));

	}
    return 0;
}

