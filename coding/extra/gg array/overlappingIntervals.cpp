#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;
#define FOR(a, n) for (int i = a; i < n; i++)
struct interval
{
    int a;
    int b;
};

bool operator<(interval a, interval b)
{
    if (a.a < b.a) {
        return true;
    } else {
        if (a.a == b.a && a.b < b.b) {
            return true;
        } else {
            return false;
        }
    }
}

void sawap(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}

int  main()
{
    int n;
    cin >> n;
    interval in[n], mg[n];
    int count = 0;
    FOR(0,n) cin >> in[i].a >> in[i].b;
    sort(in, in + n);
    FOR(0,n) cout << in[i].a << " " << in[i].b << endl;
    mg[0].a = in[0].a;
    mg[0].b = in[0].b;
    FOR(1, n) {
        if (mg[count].b >= in[i].a) {
            mg[count].b = max(mg[count].b, in[i].b);
        } else  {
            count++;
            mg[count].a = in[i].a;
            mg[count].b = in[i].b;
        }
    }
    FOR(0, count+1) {
        cout << mg[i].a << " " << mg[i].b << endl;
    }


    return 0;
}
