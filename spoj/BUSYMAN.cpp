#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;
int t, n, k;
int tot;
struct node
{
    int start;
    int end;

};
vector<node> v;


bool srt(node a, node b)
{
    if (a.end < b.end) {
        return true;
    }
    return false;
}

int main()
{
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        tot = 0;
        for (int i = 0; i < n; i++) {
            node a;
            scanf("%d%d", &a.start, &a.end);
            v.push_back(a);
        }

        sort(v.begin(), v.end(), srt);

        if (n == 0) {
            printf("0\n");
        } else {
            node prev = v[0];
            tot++;
            //cout << "size = " << v.size() << endl;
            for (int i = 1; i < v.size(); i++) {
                if (prev.end <= v[i].start) {
                    tot++;
                    prev = v[i];
                }
            }
            printf("%d\n", tot);
        }
        v.clear();
    }

    return 0;
}
