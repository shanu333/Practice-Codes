#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    int n;
    cin >> n;
    v.resize(n);
    int odd = 0 ;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        odd = odd ^ v[i];
    }
    cout << odd << endl;


    return 0;
}
