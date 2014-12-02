#include <iostream>
#include <map>
#include <cstdio>
using namespace std;

int main()
{
    long long int t, x, y, a ,b;
    map<pair<long long int, long long int>, int>   m;

    scanf("%lld", &t);
    for (int i = 0; i < t; i++) {
      scanf("%lld%lld", &x, &y);
      pair<long long int, long long int> p;
      for(int i1 = 0; i1 < y; i1++) {
        scanf("%lld%lld", &p.first, &p.second);
        //cout << i1 << endl;
        m[p]++;
      }
     //cout << "re";
      if(m.size() == y) {
        cout << "Scenario #" << i + 1 << ": possible\n";
      } else {
        cout << "Scenario #" << i + 1 << ": impossible\n";
      }
      m.clear();
    }

    return 0;
}

