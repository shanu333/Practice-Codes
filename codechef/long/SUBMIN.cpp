#include <iostream>
#include <cstdio>
#include <set>
#include <vector>

using namespace std;
int a[1000];
vector<int> pos;
set<pair<int, int> > s;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int q, k;
    cin >> q;
    while (q--) {
        cin >> k;
        pos.clear();
        for (int i = 0; i < n; i++) {
            if (a[i] == k) {
                pos.push_back(i);
            }
        }
        s.clear();
        for (int i = 0; i < pos.size(); i++) {
            int p = pos[i];
            int prev = p;
            int fin = p;
            //cout << i << endl;
            while (prev >= 0 && a[prev] >= k) prev--;
            while (fin < n && a[fin] >= k){
               //     cout << "a[fin] = " << a[fin] << endl;
                    fin++;
            }
            //cout << "fin - " << fin << endl;
            for (int i = prev + 1; i <= p; i++) {
                for (int j = p; j <= fin -1; j++) {
                //    cout << i << " " << j << endl;
                    s.insert(pair<int, int> (i , j));
                }

            }
        }
        cout << s.size() << endl;;

    }


    return 0;
}
