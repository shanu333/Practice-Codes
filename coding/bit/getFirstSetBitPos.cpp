#include <iostream>
#include <cmath>
using namespace std;

typedef unsigned long long ull;

unsigned int getFirstSetBitPos(int n)
{
   return log2(n&-n)+1;
}

int main()
{
    cout << getFirstSetBitPos(0) << endl;
    return 0;
}
