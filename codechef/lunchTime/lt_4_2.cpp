#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int t, n;
    long long a[20000];
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        long long minl = -999999;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                for (int k = j+1; k < n; k++) {

                    if (minl < ((a[i] ^ a[j])^ a[k])) {
                        minl = ((a[i] ^ a[j])^ a[k]);
                    }
                }
            }
        }
        cout << minl << endl;
    }

    return 0;
}
