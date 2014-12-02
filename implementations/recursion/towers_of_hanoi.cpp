#include <iostream>
#include <cstdio>

using namespace std;
// a -> b, using c

void towers(int n, char a, char b, char c)
{
    if (n == 1) {
        cout << "move 1 from " << a << " to " << b << endl;
        return;
    } else {
        cout << "Move " << n -1 << "disks from " << a << " to " << c << " using auxillary " << b << endl;
        towers(n - 1, a, c, b);
        cout << "Move disk" << n << " from " << a << " to " << b << endl;;
        cout << "Move " << n -1 << "disks from " << c << " to " << b << " using auxillary " << a << endl;
        towers(n - 1, c, b, a);
    }
}

int main()
{
    int n;
    cout << "enter number of disks" << endl;
    cin >> n;

    towers(n, 'A', 'B', 'C');

    return 0;
}
