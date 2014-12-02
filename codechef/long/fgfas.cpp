#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
long long t, n, k;
long long tot;
struct node
{
    long long start;
    long long end;
    long long type;
};
vector<node> v;
bool f(node a, node b)
{
    if(a.type < b.type) {
        return true;
    }
    return false;
}

bool srt(node a, node b)
{
    if (a.end < b.end) {
        return true;
    } else if (a.end == b.end) {
        if (a.start < b.start) {
            return true;
        }
    }
    return false;
}

int main()
{
    cin >> t;
    while (t--) {
        cin >> n >> k;
        tot = 0;
        for (int i = 0; i < n; i++) {
            node a;
            cin >> a.start >> a.end >> a.type;
            v.push_back(a);
        }
        sort(v.begin(), v.end(), f);
        sort(v.begin(), v.end(), srt);
        for (int i = 0; i < n; i++) {
            cout << v[i].start << " " << v[i].end << " " << v[i].type << endl;
        }

        if (n == 0) {
            cout << "0\n";
        } else {
            node prev = v[0];
            tot++;
            //cout << "size = " << v.size() << endl;
            for (int i = 1; i < v.size(); i++) {
                if (prev.type == v[i].type) {
                  //  cout << "asD";
                  //  if(prev.end != v[i].end) {
                        // just check for the starting time
                        if (prev.end <= v[i].start) {
                            tot++;
                            prev = v[i];
                        }
                 //   }
                } else {
                 //   cout << "yaer";
                    prev = v[i];
                    tot++;
                }
            }
            cout << tot << endl;
        }
         v.clear();
    }

    return 0;
}
