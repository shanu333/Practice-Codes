#include <iostream>
#include <cstdio>

using namespace std;

struct Tree
{
        long long  sum;
};


Tree T[3000005], result;
long long v[1000005];

void create(int node, int i, int j)
{
    if (j == i) {
        T[node].sum = v[i];
    } else {
        int mid = (i + j)/2;
        create(2 * node + 1, i, mid);
        create(2 * node + 2, mid + 1, j);
        T[node].sum = T[2 * node + 1].sum + T[2 * node + 2].sum;
    }
}

long long  sum(int node, int bound_start, int bound_end, int search_start, int search_end)
{
    /** if the seached segment is part of bounded segment **/
    if (search_start <= bound_start && search_end >= bound_end) {
        return T[node].sum;
    } /** outside the range **/
    else if (search_start > bound_end || search_end < bound_start) {
        return 0;
    } else {
        int mid = (bound_end + bound_start)/2;
        return (sum(2 * node + 1, bound_start, mid, search_start, search_end) + sum(2 * node + 2, mid + 1, bound_end, search_start, search_end));
    }
}

void update (int node, int bound_start, int bound_end, int diff_btw_val, int index)
{
    if (index >= bound_start && index <= bound_end) {
        T[node].sum += diff_btw_val;
        if (bound_end != bound_start) {
            int mid = (bound_end + bound_start )/2;
            update(2 * node + 1, bound_start, mid, diff_btw_val, index);
            update( 2 * node + 2, mid + 1, bound_end, diff_btw_val, index);
        }
    }

}



int main()
{
    int n, k, s, e;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }
    create(0, 0, n - 1);
    //scanf("%d", &k);
    for (int i = 0; i < 3 * n; i++) {
        cout << " " << T[i].sum << " ";
    }
    cout << endl;
    cout << sum (0, 0, n - 1, 0, n - 2);
    update(0, 0, n- 1, 2, 1);
    for (int i = 0; i < 3 * n; i++) {
        cout << " " << T[i].sum << " ";
    }
    return 0;
}
