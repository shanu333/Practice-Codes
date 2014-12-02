#include <iostream>
#include <cstring>

using namespace std;
// a -> b, using c

char a[1000];
int size;
void func(int n, char a[1000])
{
    if (n == size) {
        return;
    } else{
        cout << a << endl;
        func(n + 1, a);
        a[n] = '1';
        cout << a << endl;
        func(n + 1, a);
        a[n] = '0';
    }
}

int main()
{
    int n;
    cout << "enter number of bits << endl;
    cin >> n;
    size = n;
    memset(a, '0', n);
    func(0, a);

    return 0;
}
