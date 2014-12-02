#include <iostream>
#include <cstdio>
#include <map>
#include <vector>

using namespace std;

int main()
{
    map<int, int> m, m1;
    map<int, int> :: iterator it;
    int t, n,k, max;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        for (int i =0 ; i < n; i++) {
            scanf("%d", &k);
            m[k]++;
        }
        for (it = m.begin(); it != m.end(); it++) {
            if (it -> second % it -> first == 0) {
                m1[it -> first] = it -> second;
            }
        }
        k = 0, max = 0;
        if (m1.size() == 0)
            printf("-1\n");
        else {
            for (it = m1.begin(); it != m1.end(); it++) {
                if (max < it -> second) {
                    max = it -> second;
                    k = it -> first;
                }
            }
            printf("%d\n", k);
        }
        m1.clear();
        m.clear();
    }
    return 0;
}
