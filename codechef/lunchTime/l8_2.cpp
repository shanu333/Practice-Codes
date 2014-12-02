#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;
#define ll long long
map<char, vector<int> > m;

int main()
{

    string s;
    cin >> s;

    int c = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        m[s[i]].push_back(i+1);
    }
    int i, j, k , l;
    l = (int)m['F'].size() - 1;
    k = (int)m['E'].size() - 1;
    j = (int)m['H'].size() - 1;
    for (i = (int)m['C'].size() - 1; i >= 0; i --) {
        for (; ; j --) {
            if (m['C'][i] < m['H'][j]) break;
        }
        for (; ; k--) {
            if (m['H'][j] < m['E'][k]) break;
        }
        for (; ; l --) {
            if (m['E'][k] < m['F'][l]) break;
        }
        cout << i << " " << j << " " << k << " " << l << endl;
        if (l <= -1 || k <= -1 || j <= -1) continue;
        c++;
        j--;k--;l--;
    }
    cout << c << endl;
}
