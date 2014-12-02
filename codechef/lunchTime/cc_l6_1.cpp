#include <iostream>
#include <cstdio>
#include <string>
#include <map>
using namespace std;

int main()
{

    int t, n;
    map<int, pair<string, int> > m;
    map<int, pair<string, int> >::iterator it;;
    pair<string, int> p;
    scanf("%d", &t);
    char a[1000];
    string s;
    int g;
    while (t--)

    {
        scanf("%d", &n);

        for (int i = 0; i < n; i++) {
            cin >> s >> g;
            p.first = s;
            p.second = m[g].second + 1;
            m[g] = p;

        }
        g = 0;
        s = "Nobody wins.";
        for (it = m.begin(); it != m.end(); it ++) {
            if ((it -> second).second == 1) {
                s = (it -> second).first;
                break;
            }
            //cout << it -> first << " " << (it -> second).first << " " << (it -> second).second << endl;
        }
        cout << s << endl;
        m.clear();
    }

    return 0;
}
