#include <iostream>
#include <vector>

using namespace std;

int f(string s1, string s2);
void print(string s1, vector<vector<int> > movement, int i, int j);

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << "length of max common substring: " << f(s2, s1) << endl;
    return 0;
}

void print(string s1, vector<vector<int> > movement, int i, int j)
{
    if (i < 0 || j < 0) {
        return;
    } else {
        if (movement[i][j] == 10) {
            print(s1, movement, i-1, j-1);
            cout << s1[i];
        } else if (movement[i][j] == -1) {
            print(s1, movement, i, j-1);
        } else if (movement[i][j] == 1) {
            print(s1, movement, i-1, j);
        } else  {
            print(s1, movement, i-1, j-1);
        }
    }

}

int f(string s1, string s2)
{
    int dp[s1.size()+1][s2.size()+1];
    vector<vector<int> > movement;
    movement.resize(s1.size()+1);
    for (int i = 0; i <= s1.size(); i++) {
        dp[i][0] = 0;
        movement[i].resize(s2.size());
    }
    for (int i = 0; i <= s2.size(); i++) {
        dp[0][i] = 0;

    }

    for (int i = 1; i <= s1.size(); i++) {
        for (int j = 1; j <= s2.size(); j++) {
            int val = 0;
            dp[i][j] = dp[i-1][j-1] + val;
            movement[i-1][j-1] = 9;
            if (s1[i-1] == s2[j-1]) {
                val = 1;
                dp[i][j] = dp[i-1][j-1] + val; // i.e one more common charater
                movement[i-1][j-1] = 10;
            }

            if (dp[i][j] < dp[i][j-1]) {
                dp[i][j] = dp[i][j-1];
                movement[i-1][j-1] = -1;
            }

            if (dp[i][j] < dp[i - 1][j]) {
                dp[i][j] = dp[i - 1][j];
                movement[i-1][j-1] = 1;
            }
        }

    }

    for (int i = 0; i <= s1.size(); i++) {
        for (int j = 0; j <= s2.size(); j++) {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < movement.size(); i++) {
        for (int j = 0; j < movement[i].size(); j++) {
            cout << movement[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    print(s1, movement,  s1.size() - 1, s2.size() - 1);
    cout << endl;

    return dp[s1.size()][s2.size()];
}
