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
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        Union(a - 1, b - 1);
    }
    for (int i = 1; i < n; i++) {
        if (findRepr(0) != findRepr(i)){
            vv.push_back(pair<int, int> (0, i));
            Union(0, i);
        }
    }
    cout << vv.size() << endl;
    for (int i = 0; i < (int) vv.size(); i++) {
        cout << poss[i].first + 1 << " " << poss[i].second + 1 << " " << vv[i].first + 1 << " " << vv[i].second + 1 << endl;
    }
    return 0;
}
