#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int key, t;

    scanf("%d", &t);
    while(t--) {
       scanf("%d", &key);
       getchar();
       string s;
       getline(cin, s, '\n');
       //cout << s << endl;
       if (key >= 0 && key <= 25) {
            for (int i = 0; i < s.size(); i++) {
                if (s[i] >= 'a' && s[i] <= 'z') {
                    int n = s[i] - 'a';
                    n = (n + key) % 26;
                    s[i] = (char)('a' + n);

                } else if (s[i] >= 'A' && s[i] <= 'Z') {
                    int n = s[i] - 'A';
                    n = (n + key) % 26;
                    s[i] = (char)('A' + n);

                } else if (s[i] == '.') {
                    s[i] = ' ';

                }
                cout << s[i];
            }
            cout << endl;
       } else {
          for (int i = 0; i < s.size(); i++) {
                if (s[i] >= 'a' && s[i] <= 'z') {
                    int n = s[i] - 'a';
                    n = (n + key) % 26;
                    s[i] = (char)('A' + n);

                } else if (s[i] >= 'A' && s[i] <= 'Z') {
                    int n = s[i] - 'A';
                    n = (n + key) % 26;
                    s[i] = (char)('a' + n);

                } else if (s[i] == '.') {
                    s[i] = ' ';

                }
                cout << s[i];
            }
            cout << endl;
       }
    }

    return 0;
}
