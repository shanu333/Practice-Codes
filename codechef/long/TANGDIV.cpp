#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

#define pi pair<int, int>

pi a[1000];
pi b[1000];

void print(pi a[], int f)
{
    cout << endl;
    for (int i = 0; i < f; i++) {
        cout << a[i].first << " " << a[i].second << endl;
    }
    cout << endl;
}

int main()
{
    int t;
    long long n;
    int p, k;
    cin >> t;
    pi l;
    while (t--) {
        cin >> n >> k >> p;
        int f = 0, f1 = 0;
        for (int i = 0; i < k; i++) {
                cin >> a[i].first >> a[i].second;
                if (a[i].first > a[i].second) {
                    f++;
                    l = a[i];
                }
                if (a[i].first == 1) {
                    f1++;
                }
        }

        for (int i = 0; i < p; i++) {
                cin >> b[i].first >> b[i].second;
        }
        if (f >= 2 || (f == 1 && f1 > 0)) {
            cout << "No\n";
            continue;
        } else {
            if (f == 1) {
                for (int i = 0; i < k; i++) {
                    if (a[i].first >= l.first) {
                        a[i].first = a[i].first - l.first + 1;
                    } else {
                        a[i].first = a[i].first + (n - l.first) + 1;
                    }
                    if (a[i].second >= l.first) {
                        a[i].second = a[i].second - l.first + 1;
                    } else {
                        a[i].second = a[i].second + (n - l.first) + 1;
                    }
                }

                for (int i = 0; i < p; i++) {
                    if (b[i].first >= l.first) {
                        b[i].first = b[i].first - l.first + 1;
                    } else {
                        b[i].first = b[i].first + (n - l.first) + 1;
                    }
                    if (b[i].second >= l.first) {
                        b[i].second = b[i].second - l.first + 1;
                    } else {
                        b[i].second = b[i].second + (n - l.first) + 1;
                    }
                }
               // cout << "t";

            }
            sort(a, a + k);
            sort(b, b + p);
            print(a, k);
            print(b, p);
            f = 0;
            // code here
            for (int i = 0, j = 0; i < k; i++) {
                // either full andar
                if (a[i].first >= b[j].first && a[i].second <= b[j].second) {
                    continue;
                } else if (a[i].first > b[j].first && a[i].second > b[j].second) {
                    // or full bahar
                    j++;i--;
                } else {
                    f = 1;
                    break;
                }
            }
            if (f == 1) {
                cout << "No\n";
            } else {
                cout << "Yes\n";
            }

        }


    }

    return 0;
}
