#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int main()
{
    string s;

    getline(cin, s, '\n');
    while (s != "*") {
        char p = s[0];
        bool f  = 0;
        for (int i = 1; i < s.size(); i++) {
            if (s[i-1] == ' '){
                if(!(s[i] == p || (s[i] == (p - 32)) || (s[i] == (p+32)))) {
                    f = 1;
                }
            }
        }
        if (f == 0) {
            printf("Y\n");
        } else {
            printf("N\n");
        }
        getline(cin, s, '\n');
    }

    return 0;
}

