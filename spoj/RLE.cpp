#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    string s, ans;
    while (cin >> s)
    {
        ans = "";
        char c = '.';
        int cnt = 0;
        int flag = 0;
        for (int i = 0; i < s.size(); i++) {
            if (c == s[i]) {
                cnt++;
            } else {
                if (cnt > 3) {
                    cout << cnt << "!" << c;
                } else {
                    if (cnt == 1) {
                        cout << c;
                    } else if (cnt == 2) {
                        cout << c << c;
                    } else if (cnt == 3) {
                        cout << c << c << c;
                    }
                }
                c = s[i];
                cnt = 1;
            }
        }
        if (cnt > 3) {
                cout << cnt << "!" << c;
        } else {
            if (cnt == 1) {
                       cout << c;
            } else if (cnt == 2) {
                cout << c << c;
            } else if (cnt == 3) {
                cout << c << c << c;
            }
        }
        cout << endl;

    }

    return 0;
}
