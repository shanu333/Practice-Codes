#include <iostream>
#include <cstdio>

using namespace std;
int abss(int a)
{
    if (a < 0) return -a;
    return a;
}
int main()
{
    long long int a, b, c, w, x, cnt = 0;;
    cin >> a >> b >> w >> x >> c;
    while (c > a) {
        if(b > x) {
            int incr = b/x;
            if (b % x == 0) {
              incr --;
            }
            b = b%x + x;
            if (c - incr >= a) {
                cnt += incr;
                c -= incr;
            } else {
                cnt += (c - a);
                c = a;
            }
        } else if (b == x) {
          b = b - x;
          c--;
          cnt++;
        } else {
            b = w - (x - b);
            a--;
            c--;
            cnt++;
        }

    }
    cout << cnt << endl;
    return 0;
}
