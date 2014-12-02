#include <iostream>
#include <cstdio>
#include <map>
#include <climits>
#include <vector>
using namespace std;

int f(string s)
{
    if (s.size() <=4 )
        return 1;
    else if (s.size() == 5)
        return 2;
    else if (s.size() == 6)
        return 3;
    else if (s.size() == 7)
        return 5;
    return 11;
}
int main()
{
    string s, s1;
    map<string, int> m;
    vector<vector<string> > v;
    map<string, int>::iterator it;
    int n;
    v.resize(n);
    scanf("%d", &n);
    getchar();
    for (int j = 0; j < n; j++) {
        getline(cin, s, '\n');
        s1 = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == ' ') {
                v[j].push_back(s1);
                //cout << s1 << " ";
                m[s1]++;
                s1 = "";
            } else  {
                s1 = s1 + s[i];
            }
        }
        v[j].push_back(s1);
        m[s1]++;

    }
    int k, max = INT_MIN;
    for (int i = 0; i < n; i++) {
        k =0 ;
        for (int j = 0; j < v[i].size(); j++) {
            if (m[v[i][j]] == 1) {
                 //   cout << v[i][j] << endl;
                k = k + f(v[i][j]);
            }
        }
        if (max < k)
            max = k;
    }
    printf("%d\n", max);
    return 0;
}
