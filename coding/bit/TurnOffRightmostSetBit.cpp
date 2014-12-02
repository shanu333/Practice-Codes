#include <cstdio>
#include <iostream>
using namespace std;

void bin(unsigned n)
{
    unsigned i;
    for (i = 1 << 31; i > 0; i = i / 2){
        cout << "i = "  << i << endl;
        (n & i)? printf("1"): printf("0");
    }
}

int main(void)
{
    bin(7);
    printf("\n");
    //bin(4);
}
