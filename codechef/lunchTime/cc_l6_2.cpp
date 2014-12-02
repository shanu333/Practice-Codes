#include <iostream>
#include <cstdio>
#include <string>
#include <map>
using namespace std;

char a[100003];
int store[100003][10];
string s;
int n;
int aa[10];
#define mod 1000000007
long long fact (int t)
{
    if (t == 0 || t == 1) {
        return 1;
    } else {
        return (fact(t-1) * t) % mod;
    }
}
void func(int k, int l, int r)
{
    // check for more than one odd
    int flag = 0, indx;
    for (int i = 0; i < 10; i++) {
        if (aa[i] % 2) {
            flag++;
            indx = i;
            if (flag == 2){
                cout << 0 << endl;
                return;
            }
        }
    }
    if (flag == 1) {
        aa[indx] = 0;
    }

    long long f_k = fact((k)/2);

    long long d = 1;
    for (int i = 0; i < 10; i++) {
        d = (d * fact(aa[i]/2)) % mod;
    }
    //cout << "yes" << endl;
    cout << f_k/d<< endl;
}
void init()
{

    for (int j = 0; j < 10; j++) {
           store[0][j]= 0;
    }

    for (int i = 0; i < s.size(); i++) {
        for (int j = 0; j < 10; j++) {
            store[i][j] = store[i-1][j];
        }
        store[i][s[i] - 'a'] = store[i-1][s[i] - 'a'] + 1;
        for (int j = 0; j < 10; j++) {
          //  cout << store[i][j] << " ";
        }
       // cout << endl;

    }
}

int main()
{
    int m;
    scanf("%d%d", &n, &m);
    scanf("%s", a);
    s = a;
   // cout << s << endl;
    init();
    int t, l, r;
    for (int i = 0; i < m; i++) {
        scanf("%d%d%d", &t, &l, &r);
        l--;
        r--;
        if(t == 1) {
            //cout << l << " " << r << endl;
            for (int j = l; j < r/2 + 1; j++) {
                char c = s[j];
                s[j] = s[r - j];
                s[r - j] = c;
            }
            //cout << s << endl;
            init();
        } else  {

            for (int j = 0; j < 10; j++) {
                if (l - 1 < 0) {
                    aa[j] = store[r][j];
                } else {
                    aa[j] = store[r][j] - store[l-1][j];
                }
               // cout << aa[j] << endl;
            }
            int k = r - l + 1;
            func(k, l , r);
        }
    }

    return 0;
}
