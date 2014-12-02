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
    int type;
};
vector<node> v;
bool f(node a, node b)
{
    if(a.type < b.type) {
        return true;
    }
    return false;
}

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
        scanf("%d%d", &n, &k);
        tot = 0;
        for (int i = 0; i < n; i++) {
            node a;
            scanf("%d%d%d", &a.start, &a.end, &a.type);
            v.push_back(a);
        }
        sort(v.begin(), v.end(), f);
        int prev = 0;
        for (int i = 1; i < n ; i++) {
            if (v[i].type != v[i-1].type) {
                sort(v.begin() + prev, v.begin() + i, srt);
                prev = i;
            }
        }
        sort(v.begin() + prev, v.end(), srt);
        //for (int i = 0; i < n; i++) {
//            cout << v[i].start << " " << v[i].end << " " << v[i].type << endl;
//        }

        if (n == 0) {
            printf("0\n");
        } else {
            node prev = v[0];
            tot++;
            //cout << "size = " << v.size() << endl;
            for (int i = 1; i < v.size(); i++) {
                if (prev.type == v[i].type) {
                  //  cout << "asD";

                        // just check for the starting time
                        if (prev.end <= v[i].start) {
                            tot++;
                            prev = v[i];
                        }

                } else {
                 //   cout << "yaer";
                    prev = v[i];
                    tot++;
                }
            }
            printf("%d\n", tot);
        }
        v.clear();
    }

    return 0;
}
