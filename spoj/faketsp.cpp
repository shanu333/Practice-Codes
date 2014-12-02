#include <iostream>
#include <cstdio>
#include <sstream>
#include <cmath>
using namespace std;
string s, s1, s2;
stringstream ss;
double a, b, c, d;
double dis(double a, double b, double c, double d)
{
    double ds = (c - a)*(c - a) + (d - b) * (d - b);
    return sqrt(ds);

}
double conver(string s)
{
    double dd = 0;
    stringstream ss;
    ss << s;
    ss >> dd;
    return dd;
//    for (int i = 0; i < s.size(); i++) {
//        if (s[i] == '.') {
//            flag = 1;
//            continue;
//        }
//        dd = dd * 10 + (s[i] - '0');
//    }
}
int main()
{
//    string sd;
//    cin >> sd;
//    cout << conver(sd);
//    return 0;
    long long k = 0;
    double di = 0;
    while (1) {
        getline (cin, s, '\n');
        if (s == "") {
            break;
        }
        s1 = "";
        s2 = "";
        int i = 0;
        int  flag = 0;
        for(i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                flag = 1;
            } else if (s[i] == ',') {
                flag = 2;
            } else if (s[i] == ')'){
                flag = 0;
            }

            if (flag == 1 && ((s[i] >= '0' && s[i] <= '9') || s[i] == '.' || s[i] == '-' || s[i] == '+')){
                s1 += s[i];
            }
            if (flag == 2 && ((s[i] >= '0' && s[i] <= '9') || s[i] == '.' || s[i] == '-' || s[i] == '+')) {
                s2 += s[i];
            }
        }
        if (k == 0) {
            a = conver(s1);
            b = conver(s2);
            k++;
        } else {
            c = conver(s1);
            d = conver(s2);
            di += dis(c, d, a, b);
            printf("The salesman has traveled a total of %lf kilometers.\n", di);
            a = c;
            b = d;

        }
    }



    return 0;
}
