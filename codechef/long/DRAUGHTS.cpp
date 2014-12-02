#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#define pb push_back

using namespace std;
vector<vector<int> > vv;
vector<int> wind;
int  visited[100000];
int visited2[100000];
int n, m;
struct node
{
    int indx;
    int level;
};

void dfs(int a, int ctr)
{
    visited[a] = ctr;
    for (int i = 0; i < vv[a].size(); i++) {
        if (visited[vv[a][i]] == 0) {
            dfs(vv[a][i], ctr);
        }
    }
}

int main()
{
    cin >> n >> m;

    vv.resize(n+1);
    wind.resize(n+1);
    visited[0] = visited2[0] = false;
    for(int i = 1; i <= n; i++) {
        cin >> wind[i];
        visited[i] = false;
        visited2[i] = false;
    }

    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        vv[a].pb(b);
        vv[b].pb(a);
    }
    int inc = 0;
    for (int i = 0; i <= n; i++) {
        if (!visited[i]) {
            dfs(i, inc++);
        }
    }

    long long  ctr = 0;
    for (int i = 0; i <= n; i++) {
        if (visited[i] != 0 && wind[i] == 1){
            ctr++;
        }
    }
    ctr = (ctr * (ctr - 1))/2;
    cout << ctr << " ";
    ctr = 0;
    for (int i = 0; i <= n; i++) {

    }

    cout << ctr << endl;
    return 0;
}
