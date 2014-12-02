#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;
/**
      { 0, if p = 0                                       }
C[P]= {                                                   }
      { min {1 + C[p − d[i]}, if p > 0} AND (i:d[i] <= p) }
**/

int f(vector<int> v, int value);

int main()
{

    int n;
    cout << "enter value of diff coins\n";
   // cin >> n;
    n = 3;
    vector<int> v;
    v.resize(n);

    for (int i = 0; i < n; i++) {
        //cin >> v[i];
    }
    v[0] = 1;
    v[1] = 3;
    v[2] = 5;

    int value;
    cout << "enter value for the minimum number of coins:\n";
    cin >> value;

    cout << f(v,value) << endl;
    return 0;
}

int f(vector<int> v, int value)
{
    // return minimum number of coins
    int min_for[value+1];
    int kaun_sa[value+1];
    for (int i = 1; i <= value; i++) {
        min_for[i] = 99999;
    }
    min_for[0] = 0;
    kaun_sa[0] = 0 ;
    for (int i = 0; i < v.size(); i++) {
            for (int j = 0; j <= value - v[i]; j++) {
                int l = min_for[j+v[i]];
                min_for[j + v[i]] = min(min_for[j+v[i]], min_for[j] + 1);
                if (l != min_for[j+v[i]])  {
                    kaun_sa[j+v[i]] = v[i];
                }
              //  cout << "min for  " << j + v[i] << "   " << min_for[j + v[i]];
            }

    }
    int val = value, s = value;
    while (s > 0) {
        cout << kaun_sa[val] << " ";
        s = s - kaun_sa[val];
        val  = val - kaun_sa[val];
    }
    cout << endl;
    return min_for[value];
}
