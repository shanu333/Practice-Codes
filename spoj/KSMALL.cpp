#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;

#define ll long long
ll a, b, mod, k;

unsigned array[5000000];
void randomize(unsigned a,unsigned b,unsigned mod)
{
	for( int i=0 ; i<5000000 ; i++ )
	{
		a = 31014 * (a & 65535) + (a >> 16);
		b = 17508 * (b & 65535) + (b >> 16);
		array[i] = ((a << 16) + b) % mod;
	}
}



int main()
{
    ios_base::sync_with_stdio(false);
    cin >> a >> b >> mod >> k;
    randomize(a, b, mod);
    priority_queue<unsigned> pq;
    for (int i = 0; i < 5000000; i++) {
        if(pq.size() >= k) {
            unsigned u = pq.top();
            if (u > array[i]) {
                pq.pop();
                pq.push(array[i]);
            }
        } else {
            pq.push(array[i]);
        }
    }
    cout << pq.top() << endl;

    return 0;
}
