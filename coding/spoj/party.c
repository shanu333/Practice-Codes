#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;


// functions declaration
void print(vector<pair<int, int> > vv);
void print(vector<bool> v);
bool f(pair<int, int> p1, pair<int, int> p2);
int max_profit(vector<pair<int, int> > v, int max_wt);

int main()
{
	// intialise
	int n;
    vector<pair<int, int> > v;
    int max_wt;
	//printf("enter number of items\n");
	scanf("%d", &n);
	v.resize(n);
//	printf("enter max wt\n");
	//printf("enter weight, profit of each item");
	for (int i = 0; i < n; i++) {
		scanf("%d%d", &v[i].first, &v[i].second);

	}
	//sort(v.begin(), v.end(), f);
	//print(v);

    cout << max_profit(v, max_wt) << endl;;

	return 0;
}

int max_profit(vector<pair<int, int> > v, int max_wt)
{
    int n = v.size();
    int dp[n+1][max_wt+1];

    for (int i = 0; i < max_wt+1; i++) {
        dp[0][i] = 0; // when no item is included in the knapsack
    }

    for (int i = 0; i < n+1; i++) {
        dp[i][0] = 0; // when wt of kanpsack is zero
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= max_wt; j++) {
            dp[i][j] = dp[i-1][j]; // ith item not included
            if (j - v[i-1].first >= 0 && dp[i][j] < dp[i-1][j - v[i-1].first] + v[i-1].second) {
                dp[i][j] = dp[i-1][j - v[i-1].first] + v[i-1].second; // including the ith item
            }
        }
    }

    return dp[n][max_wt];

}



bool f(pair<int, int> p1, pair<int, int> p2)
{
	if (p1.second / p1.first > p2.second / p2.first)
		return true;
	return false;
}

void print(vector<pair<int, int> > vv)
{
	for (int i = 0; i < vv.size(); i++) {
		cout << vv[i].first << " " << vv[i].second << endl;
	}
	cout << endl;
}
void print(vector<bool> p)
{
	for (int i = 0; i < p.size(); i++) {
		if (p[i] == true)
			cout << i<< " ";
	}
	cout << endl;
}
