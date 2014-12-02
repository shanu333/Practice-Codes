
#include <iostream>
#include <cstdio>

using namespace std;

char s[10];
int convert(string s)
{
    int g = 0;
    for (int i = 0; i < s.size(); i++) {
        g = g * 10 + (s[i] - '0');
    }
    return g;
}
int main()
{
    int cntr, b1, b2, b3;
    cntr = b1 = b2 = b3 = 0;
    int strike = 0;
    int out = 0;
    int kaun_out = -1;
    while (1) {
        if (cntr == 6) {
            printf("%d\n%d\n%d\n", b1, b2, b3);
            break;
        }
        scanf("%s", s);
       // cout << s << endl;
        if (s[0] != 'W' && s[0] != 'N') {
            cntr++;
        }
        if (s[0] == 'O') {
            //cout << "asd";
            out++;
            kaun_out = strike;
           // cout << "out = " << kaun_out << endl;
            if (out == 2) {
                cntr = 6;
                continue;
            } else {
                strike = 2;
            }
        }
        if (s[0] != 'W' && s[0] != 'N') {
            if (out < 2 && s[0] != 'O') {
                int run = convert(s);
                if (strike == 0) {
                    b1 += run;
                } else if (strike == 1) {
                    b2 += run;
                } else if (strike == 2) {
                    b3 += run;
                }
                if (run & 1) {
                    if (out == 0) {
                        //cout << "strike changed";
                        if (strike == 0) {
                            strike = 1;
                        } else {
                            strike = 0;
                        }
                    } else if (out == 1) {
                        if (kaun_out == 0) {
                            if (strike == 1) {
                                strike = 2;
                            } else {
                                strike = 1;
                            }
                        } else if (kaun_out == 1) {
                            if (strike == 0) {
                                strike = 2;
                            } else {
                                strike = 0;
                            }
                        }
                    }
                }
            }
        }


    }

    return 0;
}
