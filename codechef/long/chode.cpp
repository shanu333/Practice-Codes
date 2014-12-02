#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <cctype>

using namespace std;
vector<pair<char, int> > v;
int pos[26];
bool f(pair<char, int> p1, pair<char, int> p2)
{
    if (p1.second > p2.second) {
        return false;
    } else if (p1.second == p2.second && p1.first > p2.first) {
        return false;
    } else {
        return true;
    }
}
string s1, s2, s;
int  main()
{
    int t;
    scanf("%d", &t);
    getchar();
    while (t--) {


        getline(cin, s1, '\n');
        getline(cin, s2, '\n');
        //cout << s1 << " "<< s2 << endl;
        s = s2;
        v.resize(26);
        for (int i = 0; i < 26; i++) {
            v[i].first = (char) (i + 'a');
            v[i].second = 0;
            pos[i] = 0;
        }

        for (int i = 0; i < s.size(); i++) {
            s[i] = (char)tolower(s[i]);
            if (s[i] >= 'a' && s[i] <= 'z')
            v[s[i] - 'a'].second ++;
        }

        sort(v.begin(), v.end(), f);

        for (int i = 0; i < 26; i++) {
            //cout << v[i].first << " " << v[i].second << endl;
            pos[v[i].first - 'a'] = i;
            //cout << pos[i] << endl;
        }
        for (int i = 0; i < s2.size(); i++) {
            if (s2[i] >= 'a' && s2[i] <= 'z') {
                printf("%c", s1[pos[s[i] - 'a']]);
            } else if (s2[i] >= 'A' && s2[i] <= 'Z'){
                printf("%c", s1[pos[s[i] - 'a']] - ('a' - 'A'));
            } else {
                printf("%c",s2[i]);
            }
        }
        printf("\n");
//        for (int i = 0; i < 26; i++) {
//            cout<< pos[i] << " ";
//        }
        v.clear();
    }
    return 0;
}
