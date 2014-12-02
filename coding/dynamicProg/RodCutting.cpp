#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<pair<int, int> > v;
	int n, k;

    cout << "enter  number of sizes:\n";
    cin >> n;

    v.resize(n);
    cout << "enter length, price associated to each piece\n:";
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &v[i].first, &v[i].second);
    }


    cout << max_price(v, k);

	return 0;
}

int max_price(vector<pair<int, int> > v, int k)
{
    int n = v.size();
    int dp[n+1][k+1];

    for (int i = 0; i <= n; i++) {
        dp[i][0] = 0; // when length of rod is 0 => prfoit = 0
    }

    for (int j = 0; j <= k; j++) {
        dp[0][i] = 0; // when size of legth zero is there
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            dp[i][j] =
        }
    }
}
