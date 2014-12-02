#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int t;
string s;
char a[5001];
bool pal[5001][5001];


int main()
{

    scanf("%d", &t);
    while (t--) {

        int n,l , r;

        scanf("%d\n", &n);
        getline(cin, s);
        memset(pal, false, sizeof(pal));

        for (int i = 0; i < n; i++) {
            l = r = i;
            while (l >=0 && r < n && (s[l] == s[r]))  {
                pal[l][r] = true;
                l--;
                r++;
            }

            l = i - 1;
            r = i;
            while (l >=0 && r < n && (s[l] == s[r]))  {
                pal[l][r] = true;
                l--;
                r++;
            }
        }
        int ans[5001];
        ans[0] = 1;
        for (int i = 1; i < n; i++) {
            ans[i] = 99999;
            if (pal[0][i]) ans[i] = 1;
            for (int j = i; j > 0; j--) {
                if (pal[j][i]) {
                    ans[i] = min(ans[i], ans[j-1] + 1);
                }
            }
        }
        cout << ans[n-1] << endl;
    }

    return 0;
}
