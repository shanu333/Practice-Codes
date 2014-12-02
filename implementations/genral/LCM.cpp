#include <iostream>
#include <cstdio>

using namespace std;

long long gcd(long long a, long long b)
{
    if (b == 0) {
        return a;
    } else {
        return gcd(b, a%b);
    }
}

long long LCM(long long a, long long b)
{
    return (a * b)/(gcd(a, b));
}

int main()
{
    long long int a, b;

    cin >> a >> b;

    if (b > a) {
        a = a + b;
        b = a - b;
        a = a - b;
    }
    cout << LCM(a, b) << endl;
    return 0;
}
