#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    int n;
    cin >> t;
    vector<pair<int, int> > v, v1;
    while(t--) {
        v.clear();
        cin >> n;
        v.resize(n);

        for (int i = 0; i < n; i++) {
            cin >> v[i].second >> v[i].first;
        }
        v1 = v;
        sort(v.begin(), v.end());
        pair<int, int> p = v[v.size() -1];
        int flag = 0;
        for (int i = 0; i < v.size() -1; i++) {
            if (v[i].first >= p.second) {
                flag = 1;
                break;
            }
        }
        if (flag == 1) {
            printf("-1");
        } else {
            int i = 0;
            for (i = 0; i < v.size(); i++) {
                if (v1[i] == p) {
                    break;
                }
            }
            printf("%d\n", i + 1);
        }
    }

    return 0;
}
