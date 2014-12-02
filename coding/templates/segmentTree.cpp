#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <cmath>
#include <climits>

using namespace std;

struct Tree
{
        long long  sum;
        long long maxval, lval, rval;

};

Tree T[3000005];
int  v[1000005];

inline int max2(int a, int b) {
	return ((a > b)? a : b);
}

inline int max3(int a, int b, int c) {
	return max2(a, max2(b, c));
}

void create(int node, int i, int j);
void maxquery(Tree &res, int node, int s, int e, int i, int j);

int main()
{
        int n, i, j, m;
	Tree res;
	scanf("%d", &n);
	for(i = 0; i < n; i++){
                scanf("%d", &v[i]);
	}
	create(1, 0, n-1);
	scanf("%d", &m);
	while(m--) {
		scanf("%d%d", &i, &j);
		maxquery(res, 1, 0, n-1, --i, --j);
		printf("%d\n", res.maxval);
	}
	return 0;
}

void create(int node, int i, int j)
{
    if (j == i){
       T[node].maxval = T[node].sum = T[node].rval = T[node].lval = v[i];
    } else {
        create(2*node, i, (i+j)/2);
        create(2*node + 1, (i+j)/2 + 1, j);
        T[node].sum = T[node*2].sum + T[node*2+1].sum;
	T[node].maxval = max3(T[2*node].maxval, T[2*node].rval + T[2*node+1].lval, T[2*node+1].maxval);
	T[node].lval = max2(T[2*node].lval, T[2*node].sum + T[2*node+1].lval);
	T[node].rval = max2(T[2*node].rval + T[2*node+1].sum, T[2*node+1].rval);
    }
}



void maxquery(Tree &res, int node, int s, int e, int i, int j)
{
    //cout << " i = " << i << " j = " << j << endl;
    if (s >= i && e <= j) {
        // the interval is contained in the range
        res = T[node];
        return;
    }
    int mid = (s+e)/2;
    if (j <= mid) {
        maxquery(res, 2*node, s, mid, i, j);
    } else if (i > mid) {
        maxquery(res, 2*node +1, mid+1, e, i, j);
    } else {
        Tree Left, Right;
		maxquery(Left, 2*node, s, mid, i, mid); // half half
		maxquery(Right, 2*node+1, mid+1, e, mid+1, j);
		res.maxval = max3(Left.maxval, Right.maxval, Left.rval + Right.lval);
		res.sum = Left.sum + Right.sum;
		res.lval = max2(Left.lval, Left.sum + Right.lval);
		res.rval = max2(Left.rval + Right.sum, Right.rval);
    }
}


