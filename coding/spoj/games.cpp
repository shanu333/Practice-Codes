#include <iostream>
#include <cstdio>
#include <cmath>
#include <sstream>
using namespace std;
int no_of_digits_after_decimal(double d)
{
    int x = 0;
    stringstream so;
    string s1, s2;
    so << d;
    s1 = so.str();
    s2 = s1.substr(s1.find(".")+1);
    return s2.length();
}
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
    int t;
    double d;
    int n,x;
    stringstream so;
    string s1, s2;

    string s;
    scanf("%d", &t);

    while (t--) {
        cin >>s;
        s1 = s;
        if (s1.find(".") != -1) {
            s2 = s1.substr(s1.find(".")+1);
        }

        if (s2.size() != 0) {
            so << s2;
            so >> n;
            x = 1;
            for (int i = 0; i < s2.size(); i++) {
                x = x * 10;
            }
            printf("%d\n",x/hcf(x,n));
        } else  {
            printf("1\n");
        }
        so.clear();
       // s2.clear();
    }
    return 0;
}
