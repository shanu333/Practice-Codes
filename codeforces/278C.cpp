#include <iostream>
#include <vector>
#include <map>
using namespace std;

int n, m;
vector<int> repr;
vector<vector<int> > vv;
void init(int f) {
    n = f;
    repr.resize(n);
    for (int i = 0; i < n; i++) {
        repr[i] = i;
    }
}
int findRepr(int x) {
    if (x != repr[x]) {
        return findRepr(repr[x]);
    }
    return x;
}
void Union(int a, int b)
{
    int repr_a = findRepr(a);
    int repr_b = findRepr(b);
    if (repr_a < repr_b) {
        repr[repr_b] = repr_a;
    } else {
        repr[repr_a] = repr_b;
    }
}

int main()
{
    cin >> n >> m;
    init(n);
    vv.resize(m);
     int cnt =0 ;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        for (int j = 0; j < a; j++) {
            int b;
            cin >> b;
            cnt = 1;
            vv[b-1].push_back(i);
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < (int)vv[i].size(); j++) {
            for (int k = j + 1; k < (int)vv[i].size(); k++) {
                Union(vv[i][j], vv[i][k]);
            }
        }
    }

    map<int, int> m;
    for (int i = 0; i < n; i++) {
        m[findRepr(i)]++;
       // cnt = 1;
    }
    if (cnt == 1) {
        if (m.size() <= 1) cout << 0 << endl;
        else cout << m.size() - 1 << endl;
    } else {
        cout << m.size() << endl;
    }

    return 0;
}
