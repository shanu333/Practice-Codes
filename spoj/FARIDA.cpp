#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

long long maxm(long long a, long long b)
{
    if (a > b) {
        return a;
    }
    return b;
}
vector<long long > a;
int   main()
{
		long long  t;
		cin >> t;
		long long  cntr = 0;
		while (t != 0) {
			cntr++;
			long long  n;
			cin >> n;
			if (n == 0) {
				cout << "Case " <<  cntr <<  ": " <<  "0" << endl;
				t--;
				continue;
			}
			//long long  a[n];
			a.clear();
            a.resize(n);
			for (int i = 0 ; i < n; i++) {
				cin >> a[i];
			}

			long long  including = a[0], excluding = 0;
			for (long long  i = 1; i < n; i++) {
				/* excluding this elemnt i.e choosing max from the previous one */
				long long  exclude_new = (including > excluding)? including : excluding;

				/*including this .. so we can not take the previosu one */
				including = excluding + a[i];
				/* update the exluding */
				excluding = exclude_new;
			}
			cout << "Case " <<  cntr <<  ": " << maxm(including, excluding) << endl;;
			t--;
		}
		return 0;
}
