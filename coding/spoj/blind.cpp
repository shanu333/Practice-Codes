#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int main()
{
    string s;
    char p[3];
    int row = 0;
    long long int t,x;
    scanf("%lld", &t);
    while(t--) {
        scanf("%lld", &x);
        if (x == 1) {
            printf("poor conductor\n");
        } else {
            x--;
            int temp = x%5;
            row = x/5 + 1;
            if (temp == 0) {
                row--;
            }
            if (row %2 == 1) {
                if (temp == 1)
                    s = "W L";
                else if (temp == 2)
                    s = "A L";
                else if (temp == 3)
                    s = "A R";
                else if (temp == 4)
                    s = "M R";
                else
                    s = "W R";
            } else {
                if (temp == 1)
                    s = "W R";
                else if (temp == 2)
                    s = "M R";
                else if (temp == 3)
                    s = "A R";
                else if (temp == 4)
                    s = "A L";
                else
                    s = "W L";
            }
            printf("%d ",row);
            char *a=new char[s.size()+1];
            a[s.size()]=0;
            memcpy(a,s.c_str(),s.size());
            printf("%s\n", a);
        }
    }
    return 0;
}

