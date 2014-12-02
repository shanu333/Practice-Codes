#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    long long t;
    long long n;
    long long a;
    long long sum;
    cin >> t;
    for (long long i = 0; i < t; i++) {
        cin >> n;
        sum = 0;
        for (long long i = 0; i < n; i++) {
            cin >> a;
            sum += a;
        }
        if (sum % n != 0) {
            cout << n - 1<< endl;
        } else {
            cout << n << endl;
        }
    }

    return 0;
}
