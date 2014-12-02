#include <iostream>
#include <cstdio>
#include <map>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
    map<char, int> m, m1, m2;
    map<char, int>::iterator it;
    char a[1001];
    char b[1001];
    while (scanf("%s%s", a,b) != EOF) {
        for (int i =0; i < strlen(a); i++) {
            m[a[i]]++;
        }
        for (int i = 0; i < strlen(b); i++) {
            if (m[b[i]] >= 1) {
                m2[b[i]]++;
                //m[b[i]]++;
            }
        }
        int flag = 0;
        for (it = m.begin(); it != m.end();  it++) {

               // cout << m2[it->first] << endl;
                //cout << it -> second << endl;
                //cout << min(m2[it -> first],it -> second) << endl;
                for (int i = 0; i < min(m2[it -> first],it -> second); i++) {
                    printf("%c", it ->first);
                }

        }
        printf("\n");
        m.clear();
        m2.clear();

    }
    return 0;
}
