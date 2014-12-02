#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

map<int, int> um;

int a[1000001];
int n;
int m;
int k;

void delete_frm()
{
    for (int i = 0; i < m; i++) {
        if (um.size() >= (a[i] - i - 1)) {
            break;
        } else {
            map<int, int> :: iterator it = um.begin() + (a[i] - i - 1);
            um.erase(it);
        }
    }
}

int main()
{

    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &k);
        if (k == -1) {
            delete_frm(k);
        } else {
            um.insert(pair<int, int> (i, k));
        }
    }
    for (auto& elem:um) {
        cout << elem.second << " ";
    }
    cout << endl;

    return 0;
}
