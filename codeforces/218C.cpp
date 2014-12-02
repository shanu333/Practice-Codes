#include <iostream>
#include <vector>
#include <map>
using namespace std;

int n, g;
vector<int> repr;
vector<pair<int, int> > poss, vv;
map<int, int> num_elem;

void init(int f) {
    n = f;
    repr.resize(n);
    for (int i = 0; i < n; i++) {
        repr[i] = i;
        num_elem[i] = 1;
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
    //cout << "for a : " << a  << " "<< repr_a << " \t for b : " << b << " " << repr_b << endl;
    if (repr_a != repr_b) {
        int p = num_elem[repr_a];
        num_elem[repr_a] += num_elem[repr_b];
        num_elem[repr_b] += p;
    } else {
        poss.push_back(pair<int, int> (a, b));
    }
    if (repr_a < repr_b) {
        repr[repr_b] = repr_a;
    } else {
        repr[repr_a] = repr_b;
    }
}

int main()
{
    cin >> n;
    init(n);
    vector<pair<int, int> > vp;
    vp.resize(n);
    for(int i = 0; i < n; i++) {
        cin >> vp[i].first >> vp[i].second;
    }
    for (int i = 0; i < vp.size(); i++) {
        for (int j = i + 1; j < vp.size(); j++) {
            if (vp[i].first == vp[j].first || vp[j].second == vp[i].second) {
                Union(i, j);
            }
        }
    }
    map<int ,int> m;
    for (int i = 0; i < n; i++)m[findRepr(i)]++;
    cout << m.size()  - 1 << endl;
    return 0;
}
