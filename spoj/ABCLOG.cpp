#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
     long long int t, n, z, ans, two;
    vector<int> v;
    int d;

    while (1) {
        cin >> n;
        if (n == -1) {
            break;
        }
        z = n;
        if ((n == 1)) {
            cout << n << endl;
            continue;
        }
        d = 0;
        while (z) {
            v.push_back(z % 2);
            z /= 2;
        }
        ans = 0;
        two = 1;
        for (int i = v.size() - 1; i >= 0; i--) {
            ans = ans + v[i] * two;
            two *= 2;
        }
        cout << ans << endl;
        v.clear();

    }


    return 0;
}

