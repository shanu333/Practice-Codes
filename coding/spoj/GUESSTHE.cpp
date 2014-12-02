#include <iostream>
#include <cstdio>

using namespace std;
int hcf(int a, int b)
{
    int m ,i,n;
    if(a > b){
        m = b;
        n = a;
    } else {
        n = b;
        m = a;
    }
    int qu = n;
    int remainder;
    while(1){
        qu = n / m;
        remainder = n%m;
        if(!remainder){
            break;
        }
        n = m;
        m = remainder;

    }
    return m;
}
int main()
{
    long long int n,t;
    string s;
    int f;

    cin >> s;
    while (s != "*") {
        n = 1;
        f = 0;
        for (int i = s.size() - 1; i>= 0; i--) {
            if (s[i] == 'Y') {
                t = (i+1)*n;
                t = t / hcf(i+1,n);
                //cout << "t = " << t << endl;
                n =  t;
            }
        }
        for (int i = s.size() - 1; i>= 0; i--) {
            if (s[i] == 'N') {
                if (n % (i+1) == 0) {
                    f = 1;
                    break;
                }
            }
        }
        if (f == 0) {
            printf("%lld\n", n);
        } else {
            printf("-1\n");
        }
        cin >> s;
    }
    return 0;
}
