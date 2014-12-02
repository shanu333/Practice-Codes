#include <iostream>
#include <cstdio>
#include <sstream>
using namespace std;

int main()
{
    stringstream ss;
    //float g;
    string g;
    cin >> g;
    ss << g;
    float f;
    ss >> f;
    cout << f << endl;

    return 0;
}
