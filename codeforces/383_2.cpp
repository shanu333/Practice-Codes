#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
long long abss(long long a)
{
    if (a < 0) return -a;
    return a;
}
long long  GCF(long long  a, long long  b)
{
    if (b == 0) {
        return a;
    } else {
        return GCF(b, a%b);
    }
}
long long HCF(long long a, long long b)
{
    if (a == 0 || b == 0) {
        return 0;
    }
    if (a < b) {
        return GCF(b, a);
    }
    return GCF(a, b);
}
vector<long long int> v, v2;

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
    long long diff = v[1] - v[0];
    for (long long i = 0; i < v.size() - 1; i++) {
        long long d = v[i + 1] - v[i];
        diff = HCF(diff, d);
    }
    if (diff == 0) {
        int flag = 1, gg = v[1] - v[0];
        for (int i = 0; i < v.size() - 1; i++) {
            if (v[i + 1] - v[i] != gg) {
               // break;
                flag = 0;
                break;
            }
        }
        if (flag == 1) {
            cout << 1 << endl << v[0] << endl;
            return 0;
        }
        cout << 0 << endl;
        return 0;
    }
    //cout << "dif == " << diff << endl;
    for (long long i = 0; i < v.size() - 1; i++) {
        if (v[i + 1] - v[i] == diff) {
            continue;
        } else {
            long long t = (v[i+1] - v[i]) / diff;
            long long aa = v[i] + diff;
            for (long long j = 1; j < t; j++) {
                v2.push_back(aa);
                aa += diff;
            }
        }
    }
    if (v2.size() == 0) {
        if (v.size() == 2 && ((v[0] + v[1])%2 == 0)) {
            cout << 3 << endl;
            cout << v[0] - diff <<  " " << (v[0] + v[1])/2 << " " <<  v[v.size() - 1] + diff << endl;
            //printf("%lld %lld %lld\n", );
            return 0;
        }
        cout << 2 << endl;
        cout << v[0] - diff << " " <<  v[v.size() - 1] + diff << endl;;
        return 0;
    }
    cout << v2.size() << endl;
    for (long long i = 0; i < v2.size(); i++) {
        cout << v2[i] << " ";
    }
    cout << endl;

    return 0;
}
