#include <iostream>
#include <cstdio>
#include <vector>
#include <climits>

using namespace std;

int f(vector<vector<int> > v, int m, int n);
void print(vector<vector<int> > path, int i, int j);

int main()
{
    int m,n;
    cin >> m >> n;

    vector<vector<int> > v;
    v.resize(m);

    for (int i = 0; i < m; i++) {
        v[i].resize(n);
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }

    cout << f(v, m, n);

    return 0;
}

int f(vector<vector<int> > v, int m, int n)
{
    vector<vector<int> > dp, path;
    dp.resize(m);
    path.resize(m);
    for (int i = 0; i < m; i++) {
        dp[i].resize(n);
        path[i].resize(n);
    }
    dp[0][0] = v[0][0]; // i.e base case

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (i-1 >= 0 && j-1 >= 0) {
                dp[i][j] = INT_MAX;
                if (dp[i][j] > dp[i-1][j-1]+ v[i][j]) {
                    dp[i][j] = dp[i-1][j-1]+ v[i][j]; // diagonal movement
                    path[i][j] = 0;
                }
                if (dp[i][j] > dp[i-1][j] + v[i][j]) {
                    dp[i][j] = dp[i-1][j] + v[i][j]; // move left
                    path[i][j] = 1;
                }
                if (dp[i][j] > dp[i][j-1] + v[i][j]) {
                    dp[i][j] = dp[i][j-1] + v[i][j];// move down
                    path[i][j]  = -1;
                }
            } else if (i - 1 >= 0 && j - 1 < 0) {
                dp[i][j] =  dp[i-1][j] + v[i][j];// only left movement
                path[i][j] = 1;
            } else  if (j-1 >= 0 && i-1 < 0){
                dp[i][j] =  dp[i][j-1] + v[i][j]; // only down movement
                path[i][j] = -1;
            }
        }
    }

    print(path, m-1, n-1);

    return dp[m-1][n-1];
}

void print(vector<vector<int> > path, int i, int j)
{
    if (i < 0 || j < 0) {
        return;
    } else {
        if (path[i][j] == 0){
            // diagonal case
            print(path, i-1, j-1);
            cout << " - > (" << i << " , " << j << ")   ";
        } else if (path[i][j] == 1) {
            // move right
            print(path, i-1, j);
            cout << " - > (" << i << " , " << j << ")   ";
        } else {
            //move down
            print(path, i, j-1);
            cout << " - > (" << i << " , " << j << ")   ";
        }
    }
}
