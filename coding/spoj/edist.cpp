#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int dp[2001][2001];

int main()
{
    string s1, s2;
    int t;
    scanf("%d", &t);
    while (t--) {
        cin >> s1 >> s2;
        for (int i = 0; i < s1.size(); i++) {
            dp[i][0] = i;
        }
        for (int i = 0; i < s2.size(); i++) {
            dp[0][i] = i;
        }
        for (int i = 1; i <= s1.size(); i++) {
            for (int j = 1; j <= s2.size(); j++) {
                int val = 1; // i.e for replacement
                if (s1[i-1] == s2[j-1])
                    val = 0; // same character inserted
                int temp = min(dp[i-1][j] + 1, dp[i][j-1] + 1);
                int temp2 = dp[i-1][j-1] + val;
                dp[i][j] = min(temp, temp2);
            }
        }
        printf("%d\n", dp[s1.size()][s2.size()]);

    }
    return 0;
}
