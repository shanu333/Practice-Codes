#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    int n;
    cin >> n;
    n = ceil(log2 (n));
    cout << n << endl;
    cout << pow(2, n) << endl;

    return 0;
}
