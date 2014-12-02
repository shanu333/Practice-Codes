#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

/**
    C(n, k) = C(n-1, k-1) + C(n-1, k)
    C(n, 0) = C(n, n) = 1
    C(n, k) = C(n-1, k-1) + C(n-1, k)
has a nice intuitive interpretation.

To pick k elements from n elements [C(n, k)],
 you consider one element and either include it in the k
  chosen elements, or you don't. If you do, you have to now
   choose k-1 elements from the remaining n-1 elements[C(n-1, k-1)]
   ; if you don't you need to choose k elements from the
    remaining n-1 elements [C(n-1, k)].
QED
**/

long long int C(int n, int k);
int main()
{
    int n, k;
    cin >>n >> k;
    if (k > n - k)
        k = n - k;
    cout << C(n,k) << endl;
    return 0;
}

long long int C(int n, int k)
{
    vector<vector<long long int> > dp;
    dp.resize(n+1);
    for (int i = 0; i <= n; i++) {
        dp[i].resize(k+1);
    }
    for (int i = 0; i <= n; i++) {
        for(int j = 0; j <= min(i, k); j++) { // min because c(n,k) = c(n, n - k);
            if (j == 0 || j == i) {
                dp[i][j] = 1; // base cases i.e c(n,n) = 1 || c(0, 0) = 1
            } else {
                dp[i][j] = dp[i-1][j-1] + dp[i-1][j];
            }
        }
    }
    for (int i = 0; i <= n; i++) {
        for(int j = 0; j <= min(i, k); j++) { // min because c(n,k) = c(n, n - k);
            //cout <<  dp[i][j] << " "; // base cases i.e c(n,n) = 1 || c(0, 0) = 1
        }
       // cout << endl;
    }
    return dp[n][k];

}
