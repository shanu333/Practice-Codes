#include <iostream>
#include <vector>
#include <map>
using namespace std;

class disjointSet
{
public :
    int n;
    vector<int> repr;
    map<int, int> num_elem;
    disjointSet(int f) {
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
        }
        if (repr_a < repr_b) {
            repr[repr_b] = repr_a;
        } else {
            repr[repr_a] = repr_b;
        }
    }
    int count_distinct() {
        map<int, int> m;
        for (int i = 0; i < n; i++) {
            m[findRepr(i)]++;
        }
        return m.size();
    }
    void clear() {
        for (int i = 0; i < n; i++) {
            repr[i] = i;
            num_elem[i] = 1;
        }
    }

};

int main()
{
    ios_base::sync_with_stdio(false);
    map<string, int> m;
    int t, n;
    string s, aa;
    cin >> t;
    disjointSet ds(100000);
    while (t--) {
        ds.clear();
        cin >> n;
        int ctr = 0;
        for (int i = 0; i < n; i++) {
            cin >> s >> aa;
            if (!m.count(s)) {
                m[s] = ctr++;
            }
            if (!m.count(aa)) {
                m[aa] = ctr++;
            }
            ds.Union(m[s], m[aa]);
            cout << ds.num_elem[ds.findRepr(m[s])] << endl;
        }
        m.clear();
    }

    return 0;
}
