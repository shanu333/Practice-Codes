#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    long long int n, t,c1,c2,k;
    scanf("%lld", &n);
    n++;

    vector<int> v;
    while (1) {
        t = n;
        c1 = 0;
        c2 = 0;
        while(t > 1) {
            k = t % 2;
            v.push_back(k);
            t /= 2;
            if (k == 1)
                c1 ++;
            else
                c2++;
        }
        for (int i = 0; i < v.size(); i++)
            cout << v[i] << " ";
        cout << endl;
        if (abs(c1 - c2) <= 3) {
            for (int i = v.size() -1 ; i >= 0; i--) {
                if (v[i] == 0) {
                    printf("a");
                } else {
                    printf("b");
                }
            }
            printf("\n");
            break;
        } else {
            v.clear();
            n++;
        }
    }
    return 0;
}
