#include <iostream>

using namespace std;

int main()
{

//    Maximum sum such that no two elements are adjacent

    int a[] =  {5,  5, 10, 40, 50, 35};
    int n = 6;

    int incl = a[0];
    int excl = 0;
    for (int i = 1; i < n; i++) {
        int incl_new = excl;
        incl_new += a[i]; // includeing this opne

        excl = max(excl, incl);
        incl = incl_new;
        cout << incl << " " << excl << endl;
    }
    cout << max(incl, excl);

    return 0;
}
