#include <iostream>
#include <string>
#include <cstdio>
#include <sstream>
using namespace std;
#define FOR(n) for (int i = 0; i < n; i++)

struct sell
{
    int buy;
    int sell;
};
void sawap(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}

int  main()
{
    int n=7;
    //cin >> n;
    int a[7] = {100, 180, 260, 310, 40, 535, 695};
    int i=0;
    sell stocks[n];
    int count = 0;
    //FOR(n) cin >> a[i];
    int maxima = 0, minima= 0;
    while (i < n) {
        while (i < n && a[i] <= a[i-1]) {
            i++;
        }
        stocks[count].buy = i-1;
        while (i < n && a[i] >= a[i-1]) {
            i++;
        }
        stocks[count++].sell = i-1;
    }
    if (count == 0)
        printf("There is no day when buying the stock will make profit\n");
    else
    {
       for (int i = 0; i < count; i++)
          printf("Buy on day: %d\t Sell on day: %d\n", stocks[i].buy, stocks[i].sell);
    }



    return 0;
}
