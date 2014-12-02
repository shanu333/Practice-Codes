#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
using namespace std;

vector<vector<int> > v;
vector<bool> visited;
int n;
struct node
{
    int i;
    int l;
};
int main()
{
    int a, b, t;
    cin >> n;
    v.resize(n);
    visited.resize(n);
    for (int i = 0; i < n; i++) {
        v[i].resize(n);
        visited[i] = false;
        for (int j = 0; j < n; j++) {
            cin >> a;
            v[i][j] = a;
        }
    }

    int s;
    cout << "enter the strtting node" << endl;
    cin >> s;
    stack<int> q;
    q.push(s);

    while(!q.empty())
    {
        int p = q.top();
        q.pop();
        if (visited[p] == true) {
            continue;
        }
        cout << p << endl;
        visited[p] = true;
        for (int i = 0; i < n; i++) {
            if(visited[i] == false && v[p][i] != 0) {
                q.push(i);
            }
        }
    }
    return 0;
}
