#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <climits>
#include <set>
using namespace std;
map<int , vector<int> > vv;
vector<int> v;
set<pair<int, int> > vp;
set<pair<int, int> >::iterator it;
int n, k, a, ans;

int mini(int a, int b)
{
    if (a < b) return a;
    return b;
}
int maxi(int a, int b)
{
    if (a > b) return a;
    return b;
}

int poss(pair<int, int> p)
{
    //cout << p.first << " " << p.second << endl;
    if (p.first == p.second) return -9999;
    int poss1 = maxi(p.first , p.second);
    int poss2 = maxi(n - p.first - 1, n - p.second -1 );
    int poss3 = maxi(n - p.first - 1, p.second);
    int poss4 = maxi(n - p.second - 1, p.first);
   // cout << poss1 << poss2 << poss3 << poss4 << endl;
    //cout << "return " <<  mini(mini(poss1, poss2), mini(poss3, poss4)) << endl;;
    return mini(mini(poss1, poss2), mini(poss3, poss4));
}

int main()
{
    cin >> n >> k;
    //vv.resize(1000001);
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a;
        v[i] = a;
        vv[a].push_back(i);
    }

    for (int i = 0; i < (int)v.size(); i++) {
        int d = k - v[i];
        if (d == v[i])continue;//distinct types
        if (d > 0 && vv[d].size() > 0) {
            for (int j = 0; j < vv[d].size(); j++) {
                vp.insert(pair<int, int> (i, vv[d][j]));
            }
            break;
        }
    }
    for (int i = (int)v.size() - 1; i >= 0;  i--) {
        int d = k - v[i];
        if (d == v[i])continue;//distinct types
        if (d > 0 && vv[d].size() > 0) {
            for (int j = 0; j < vv[d].size(); j++) {
                vp.insert(pair<int, int> (i, vv[d][j]));
            }
            break;
        }
    }

    if (vp.size() == 0) {
        cout << "-1\n";
        return 0;
    }
    ans = poss(*vp.begin());
    for (it = vp.begin(); it != vp.end(); it++) {
        int ans2 = poss(*it);
        if (ans > ans2) {
          //  cout << " i = " << vp[i].first <<  " j = " << vp[i].second << endl;
            ans = ans2;
        }
    }
    if (ans < 0) {
        cout << "-11\n";
        return 0;
    }
    cout << ans + 1 << endl;
    return 0;
}
