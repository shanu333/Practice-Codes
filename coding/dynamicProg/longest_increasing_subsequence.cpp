#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

vector<int>  input();

int main()
{
    vector<int> v;
    v = input();
    int n = v.size();

    vector<int> L;
    L.resize(n);
    L[0] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (v[j] < v[i]) {
                L[i] = max(1 + L[j], L[i]);
            }
        }
    }

    //cout << "subsequence = " << L[n-1] << endl; WRONG because it's possible
    // not to include the last element for the lingest subsequence so, we need to find the max
    int maxi = L[0];
    for (int i = 1; i < n; i++) {
        if (maxi < L[i])
            maxi = L[i];
    }

    cout << "subsequence of length =  " << maxi << endl;

    return 0;
}

vector<int>  input()
{
    int n;
    vector<int> v;
    cout << "enter size\n";
    cin >> n;
    cout << "enter values of 1d array\n";
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    return v;
}
