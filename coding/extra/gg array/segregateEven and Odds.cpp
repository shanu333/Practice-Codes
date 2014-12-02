#include <iostream>

using namespace std;

int main()
{
    int a[] = {12, 34, 45, 9, 8, 90, 3};
    int n = 7;
    int l = 0, r = n - 1;
    while (l < r) {
        // find first odd
        while (1) {
            if (l == n) {
                break;
            }
            if (a[l]&1)
                break;
            else
                l++;
        }
        while (1) {
            if (r == -1) {
                break;
            }
            if (!(a[r]&1))
                break;
            else
                r--;
        }
        if (r != -1 && l != n) {
          //  cout << "AS " << a[l] << " " << a[r] << endl;;
            int kk = a[r];
            a[r] = a[l];
            a[l] = kk;
            l++;
            r--;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }


    return 0;
}
