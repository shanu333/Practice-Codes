#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int max_cont_sum(vector<int> v)
{
    int end, far;
    end = 0;
    far = -999999;
    for (int i = 0; i < (int)v.size(); i++) {
        end += v[i];
        far = max(end, far);
        if (end < 0) {
            end = 0;
        }
    }
    return far;
}

int main()
{
    vector<int> v;
    int n;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    cout << max_cont_sum(v) << endl;;
    return 0;
}
