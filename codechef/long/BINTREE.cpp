#include <iostream>
using namespace std;
int main()
{
    //freopen("sample.txt", "w", stdout);
    int n , i , j;
    cin >> n;
    while (n--) {
        cin >> i >> j;
        int c = 0;
        while (i != j) {
            if (i > j) {
                i/= 2;
            } else {
                j/= 2;
            }
            c++;
        }
        cout << c << endl;
    }

    return 0;
}
