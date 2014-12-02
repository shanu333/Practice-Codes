#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int max_wt;
vector<pair<int, int> > v;
int total = 0;
int max_profit(vector<pair<int, int> > v, int max_wt);


int main()
{
    int t;
    scanf("%d", &max_wt);
    scanf("%d", &n);
    while(max_wt != 0 && n != 0) {

        v.resize(n);
        for (int i = 0; i < n; i++) {
            scanf("%d%d", &v[i].first, &v[i].second);
        }
        int pft =  max_profit(v, max_wt) ;;
        printf("%d %d\n", total+1, pft);
        total = 0;
        scanf("%d", &max_wt);
        scanf("%d", &n);
    }

	return 0;
}

int max_profit(vector<pair<int, int> > v, int max_wt)
{
    int n = v.size();
    int dp[n+1][max_wt+1];
    vector<vector<int> > s;
    s.resize(n+1);

    for (int i = 0; i < n+1; i++) {
        s[i].resize(max_wt+1);
        dp[i][0] = 0; // when wt of kanpsack is zero
        s[i][0] = 0;
    }

    for (int i = 0; i < max_wt+1; i++) {
        dp[0][i] = 0; // when no item is included in the knapsack
        s[0][i] = 0;
    }



    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= max_wt; j++) {
            dp[i][j] = dp[i-1][j]; // ith item not included
            s[i][j] = 1;
            if (j - v[i-1].first >= 0 && dp[i][j] < dp[i-1][j - v[i-1].first] + v[i-1].second) {
                dp[i][j] = dp[i-1][j - v[i-1].first] + v[i-1].second; // including the ith item
                s[i][j] = 2;
            }
        }
    }
    int w, best;
    for( w = max_wt, best = dp[n][max_wt] ; ; w--){
			if(dp[n][w] < best) {
				break; // when profit start to decrease ....
			}
    }
    total = w;
    return dp[n][max_wt];

}


