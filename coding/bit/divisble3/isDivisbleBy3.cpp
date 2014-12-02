#include <iostream>
#include <cmath>
using namespace std;

typedef unsigned long long ull;

bool isDivisbleBy3(ull n)
{
    if (n == 0 || n == 1) {
        return (!n);
    } else {
        if (n < 0) n = -n;
        int even_pos, odd_pos;
        even_pos = odd_pos = 0;
        while (n != 0) {
            if (n & 1) {
                odd_pos++;
            }
            n >>= 1;
            if (n & 1) {
                even_pos++;
            }
            n>>= 1;
        }
        cout << "odd " << odd_pos << " " << even_pos << endl;
        return isDivisbleBy3((abs(odd_pos - even_pos)));
    }

}

int main()
{
    cout << isDivisbleBy3(3) << endl;
    return 0;
}
