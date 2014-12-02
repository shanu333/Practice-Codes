#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int n;
int a[100005];

vector<vector<int> > vv;

int main()
{
    scanf("%d", &n);
    vv.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    vector<int> tmp;
    tmp.push_back(a[0]);
    vv[0] = tmp;
    for (int i = 1; i < n; i++) {
        if (a[i] > a[i-1]) {
            tmp.clear();
            tmp = vv[i-1];
            tmp.push_back(a[i]);
            vv[i] = tmp;
        } else {
            int flag = 0;
            for (int j = i -1; j >= 0; j--) {
                if(a[i] > a[j]) {
                    tmp.clear();
                    tmp = vv[j];
                    tmp.push_back(a[i]);
                    vv[i] = tmp;
                    flag = 1;
                }
            }
            if (flag == 0) {
                tmp.clear();
                vv[i].push_back(a[i]);
            }
        }
    }
    cout << vv[n-1].size() << endl;;
    for (int i = 0; i < vv[n-1].size(); i++) {
        cout << vv[n-1][i] << " ";
    }
    cout << endl;


    return 0;
}

