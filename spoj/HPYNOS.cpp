#include <iostream>
#include <cstdio>
#include <sstream>
#include <map>
using namespace std;
#define ll long long
string up(string s)
{
    ll a = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        a += ((s[i] - '0')*(s[i] - '0'));
    }
    stringstream ss;
    ss << a;
    string str = ss.str();
    return str;
}
int main()
{
    string  s;
    cin >> s;
    int flag = 0;
    long long  cnt = 0;
    map<string ,int > m;

    while (1) {
        cnt++;
        if (s.size() == 1) {
            if (s[0] == '1') {
                flag = 1;
                break;
            } else {
               // break;
            }
        }
        if (m.count(s)) {
            break;
        }
        m[s] = 1;
        s = up(s);
    }
    if (flag == 0) {
        cout << "-1\n";
    } else {
        cout << cnt  - 1 << endl;
    }


    return 0;
}

