#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;
typedef unsigned long long ull;

/*unsigned long long nextPowerOfTwo(unsigned long long int n)
{
    if (n == 0) {
        return 1;
    } else {
        ull p = 1;
        while (n != 0) {
            n >>= 1;
            p <<= 1;
        }
        return p;
    }

}

*/ull nextPowerOfTwo(ull n)
{
    n--;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >> 16;
    n++;
    return n;
}
int main()
{
    unsigned long long  n;
    cin >> n;
    cout << (n & !(n & (n - 1))) << endl;
    cout << "n & (n - 1)   " << (n & (n - 1)) << endl;
    cout << "!(n & (n - 1))" << !(n & (n - 1)) << endl;
    cout << "(n & !(n & (n - 1)))  " << (n & !(n & (n - 1))) << endl;
    cout << nextPowerOfTwo(n) << endl;

    return 0;
}
