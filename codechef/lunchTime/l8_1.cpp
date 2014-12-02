#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;
#define ll long long
ll n, t, k;
ll ans = 0;
ll cst = 0;
ll wt = 0;
vector<pair<ll, ll> > v;
vector<ll> taken;
void print(vector<ll> take)
{
    for (int i = 0 ; i < (int) taken.size(); i++) {
        cout << take[i];
    }
    cout << endl;
}



int main()
{

    cin >> t;
    while (t--) {
        cin >> n;
        cin >> k;
        v.clear();
        v.resize(n);
        taken.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i].first >> v[i].second;
            //taken[i] = 0;
        }
       // maxx(0);
      // cout << (1<<n) << endl;
       for (int i = 0; i <= (1<<n); i++) {
            cst = 0;
            wt = 0;
            for (int j = 0; j < n; j++) {
                // check if nth bit is set
                //cout << (1<<j) << endl;
                if ( (1<<j) & i) {
                    cst += v[j].first;
                    wt += v[j].second;
                }
            }
            if (k >= cst) {
                ans = max(ans, wt);
            }
       }
        cout << ans << endl;
        cst = ans = wt = 0;
    }

}
