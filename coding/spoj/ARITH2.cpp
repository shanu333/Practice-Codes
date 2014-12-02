#include <iostream>
#include <cstdio>
using namespace std;


int main()
{
    int t,i;
    string s,s1;
    long long int ans, num;
    scanf("%d", &t);
    getchar();
    while(t--) {
        ans = 0;
        num = 0;
        getline(cin, s, '\n');
        s1 = "";
        for (i = 0; i < s.size(); i++) {
            if(s[i]!= '+' && s[i] != '-' && s[i] != '*' && s[i] != '/' && s[i] != ' ') {
                s1 = s1 + s[i];
                num = num*10 + (s[i] - 48);
            } else if (s[i] != ' ') {
                cout << "ans = " << ans << " number = " << num << endl;
                s1 = "";
                if (s[i] == '+')
                    ans += num;
                else if (s[i] == '-')
                    ans = ans - num;
                else if (s[i] == '*')
                    ans = ans * num;
                else
                    ans = ans  / num;
                num = 0;
            }

        }
        if (s[i] == '+')
            ans += num;
        else if (s[i] == '-')
            ans = ans - num;
        else if (s[i] == '*')
            ans = ans * num;
        else
            ans = ans  / num;

        printf("%lld\n", ans);
    }
    return 0;
}
