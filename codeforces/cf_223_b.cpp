#include <iostream>
#include <cstdio>
#include <map>
using namespace std;
int a[100005];
int b[100005];
int main()
{
    int t, n;
    map<int, int> m;
    map<int, int>::iterator it;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        m[t]++;
    }
    int cnt = 0;
    int p = 0, q = 0;
    for (it = m.begin(); it != m.end(); it++) {
        if (it -> second >= 2) {
            a[p] = it -> first;
            b[q] = it -> first;
            p++;
            q++;
        } else {
            a[p] = it -> first;
            p++;
        }
    }
    if (a[p-1] == a[q-1]) {
        p--;
    }
    cout << p + q << endl;
    for (int i = 0; i < p; i++) {
        cout << a[i] << " ";
    }

    for (int i = q - 1; i >= 0; i--) {
        cout << b[i] << " ";
    }
    cout << endl;
    return 0;
}
