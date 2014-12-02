#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
//    int n,c;
//    cin >> n;
//    int a[2][2];
//    for (int i = 3; i < n; i++) {
//        c = 0;
//        for (int j1 = 1; j1 < 2600; j1++) {
//            for (int j2 = 1; j2 < 2600; j2++) {
//                for (int j3 = 1; j3 < 2600; j3++) {
//                    for (int j4 = 1; j4 < 2600; j4++) {
//                        a[0][0] = j1;
//                        a[0][1] = j2;
//                        a[1][0] = j3;
//                        a[1][1] = j4;
//                        if (j1 + j4 == i) {
//                            if (j4 * j1 - j2 * j3 > 0) {
//                                c++;
//                                cout << j1 << " " << j2 << " " << j3 << " " << j4 << endl;
//                            }
//                        } else if (j1 + j4 > i) {
//                            break;
//                        }
//                    }
//                }
//            }
//        }
//        cout <<  c << endl;
//    }

    string s;
    cin >> s;
    int h = 0;
    for (int i= 0; i < s.size(); i++) {
        h += (s[i] - 'a');
    }
    cout << h << endl;
    return 0;
}
