#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main()
{
    int t,n,k;
    string s, s1;
    vector<int> v,v1;
    scanf("%d", &n);

    while(n!=0) {
        v.resize(n);
        v1.resize(n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &k);
            v1[k-1] = i+1;
            v[i]  = k;

        }
        if (v == v1)
            printf("ambiguous\n");
        else
            printf("not ambiguous\n");
        v.clear();
        v1.clear();
        scanf("%d", &n);

    }
    return 0;
}
