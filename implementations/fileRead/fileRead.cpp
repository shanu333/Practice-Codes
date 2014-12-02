#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ifstream in("abalone.data.txt");
    ofstream out("abalone_mod");
    string s;
    char c = 0;
    int cntt = 0;
    int cnt = 0;
    while (in.good()) {
        if (!in.good()) {
            break;
        }
        in >> s;
        if (s[0] == 'M') s[0] = '0';
        else if (s[0] == 'F') s[0] = '1';
        else if (s[0] == 'I')s[0]=  '2';
        else {cout <<"error"; cntt++;};
        cout << s << endl;
        out << s << "\n";
        cnt++;
    }
    cout << cntt << endl;
    cout << cnt << endl;
   // cout << s << endl;
    in.close();
   // out.close();

    return 0;
}
