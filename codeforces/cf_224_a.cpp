#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

vector<long long > v, v1, v2;
map<long long, int> m;
map<long long, int>::iterator it;
int  main()
{
    long long n;
    long long d;
    cin >> n;
    v.resize(n);
    for (long long i = 0; i < n; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());
    if (n == 1) {
        cout << -1 << endl;
        return 0;
    }
    for (int i = 0; i < v.size() -1; i++) {
        m[v[i + 1] - v[i]]++;
    }
    if (m.size() > 2) {
        printf("0\n");
    } else {
        //cout << "ye";
        if (m.size() == 2) {

            int diff, cnt = 0;
            for (it = m.begin(); it != m.end(); it++) {
                if (cnt < it -> second){
                    diff = it -> first;
                    cnt = it -> second;
                }
            }
            if (diff == 0) {
                printf("0\n");
                return 0;
            }
            for (int i = 0; i < v.size() - 1; i++) {
                if (v[i+1] - v[i] != diff) {
                    int aa = v[i] + diff;
                    for (int j = 1; j < (v[i+1] - v[i])/diff; j++) {
                        v2.push_back(aa);
                        aa += diff;
                    }
                }
            }
            cout << v2.size() << endl;
            for (int i = 0; i < v2.size(); i++) {
                cout << v2[i] << " ";
            }
            cout << endl;
        } else {

            if (n == 2) {
                if (v[0] == v[1]) {
                    cout << "1\n" << v[0] << endl;
                    return 0;
                }
                if ((v[0] + v[1]) % 2 == 0) {
                    cout << "3" << endl;
                    cout << v[0] - m.begin() -> first << " " << (v[0] + v[1])/2 << " " << v[1] + m.begin() -> first << endl;;
                } else {
                    cout << "2\n";
                    cout << v[0] - m.begin() -> first << " "<< v[1] + m.begin() -> first << endl;
                }
            } else {
                if (v[0] == v[1]) {
                    cout << "1\n";
                    cout << v[0] << endl;;
                } else {
                    cout << "2" << endl;
                    cout << v[0] - m.begin() -> first << " "<< v[n-1] + m.begin() -> first << endl;
                }
            }
        }
    }

    return 0;
}
