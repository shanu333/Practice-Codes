#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int n, m;
vector<int> repr;
set<int> s;
int main()
{
    cin >> n >> m;
    repr.resize(n);
    for (int i = 0; i < n; i++) {
        s.insert(i);
        repr[i] = -1;
    }
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--;b--;c--;
        set<int>::iterator it = s.lower_bound(a);
        vector<int> toerase;
        while(it != s.end()) {
            int curr = *it;
            if (curr > b) break;
            if (curr != c) {
                repr[curr] = c;
                toerase.push_back(curr);
            }
            it++;
        }
        for (int i = 0; i < toerase.size(); i++) s.erase(toerase[i]);
    }
    for (int i = 0; i < n; i++) {
        if (repr[i] < 0) repr[i] = -1;
        cout << repr[i] + 1 << " ";
    }
    cout << endl;

    return 0;
}
