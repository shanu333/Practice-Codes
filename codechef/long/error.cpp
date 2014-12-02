#include <iostream>
#include <cstdio>


using namespace std;

int main()
{
    int t;

    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int f = 0;
        f = s.find("101");
        if (f == -1) {
            f = s.find("010");
            if (f == -1) {
                cout << "Bad\n";
            } else {
                cout << "Good\n";
            }
        } else {
            cout << "Good\n";
        }

    }

    return 0;
}
