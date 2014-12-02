#include <iostream>
#include <cstdio>
#include <vector>

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
    cin >> n;

    vector<int> v;
    v.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

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
    int kaun_sa_coin[value+1];
    min_for[0] = 0;
    for (int i = 1; i <= value; i++) {
        int mini = 999999,index;
        for (int j = 0; j < v.size(); j++) {
            if (v[j] <= i) { // i.e atleast one coin can be used for that payment
                if (1+min_for[i - v[j]] < mini) {
                    mini = 1+min_for[i - v[j]];
                    index = j;
                }
            }
        }
        min_for[i] = mini;
        kaun_sa_coin[i] = index;
    }


    return min_for[value];
}
