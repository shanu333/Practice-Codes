#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int main()
{
    int n, m ,k;
    int is_core_locked[101];
    int is_mem_locked[101];
    int store[101][101];
    cin >> n >> m >> k;
    for (int i = 0; i < 101; i++) {
        is_core_locked[i] = is_mem_locked[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> store[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        map<int, vector<int> > mp;
        for (int j = 0; j < n; j++) {
            if (store[j][i] != 0 && is_core_locked[j] == 0) {
                // actual work
                mp[store[j][i]].push_back(j);
            }
        }
        for (int j = 0; j <= k; j++) {
            if (mp[j].size() > 1) {
                for (int k = 0; k < mp[j].size(); k++) {
                    int l = mp[j][k]; // l gives me core number
                    if (is_core_locked[l] != 0) {
                        continue;
                    } else {
                        is_core_locked[l] = i+1; // lock the process
                    }
                }
                is_mem_locked[j] = 1;
            } else if (mp[j].size() == 1) {
                int l = mp[j][0]; // l gives me core number
                // if it is already locked
                if (is_core_locked[l] != 0) {
                    continue;
                } else {
                    if (is_mem_locked[j] == 1) {
                        is_core_locked[l] = i+1; // lock the process
                    }
                }
            }
        }
        mp.clear();
    }
    for (int i = 0; i < n; i++) {
        cout << is_core_locked[i] << endl;
    }


    return 0;
}
