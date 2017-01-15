#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>

#define MAX_N 1000001
#define MAX_TREE (MAX_N << 2)

using namespace std;

int n;
int array[MAX_N];
int ST[MAX_TREE];

//Slozenost: init_tree O(N), update O(log N), query O(log N)
void init_tree_util(int idx, int left, int right);
int query_util(int idx, int left, int right, int ql, int qr);
void update_util(int idx, int left, int right, int x, int val);

void init()
{
    init_tree_util(1, 1, n);
}

int query(int ql, int qr)
{
    return query_util(1, 1, n, ql, qr);
}

void update(int x, int value)
{
    array[x] = value;
    update_util(1, 1, n, x, value);
}





int main()
{
    n = 6;
    array[1] = 4;
    array[2] = 2;
    array[3] = 5;
    array[4] = 1;
    array[5] = 6;
    array[6] = 3;

    init();

    //for(int i = 1; i <= n; i ++)
        //cout << ST[i] << " " << ST[i * 2] << " " << ST[i * 2 + 1] << endl;
    cout << query(1, 3) << endl;
    update(3, 10);
    cout << query(1, 3) << endl;
    return 0;
}

void init_tree_util(int idx, int left, int right)
{
    if(left == right)
        ST[idx] = array[left];
    else
    {
        int mid = (left + right) / 2;
        init_tree_util(idx * 2, left, mid);
        init_tree_util(idx * 2 + 1, mid + 1, right);
        ST[idx] = ST[idx * 2] + ST[idx * 2 + 1];
    }
}

int query_util(int idx, int left, int right, int ql, int qr)
{
    if (ql <= left && right <= qr)
        return ST[idx];
    if (right < ql || left > qr)
        return 0;
    int mid = (left + right) / 2;
    return query_util(2 * idx, left, mid, ql, qr) + query_util(2 * idx, mid + 1, right, ql, qr);
}

void update_util(int idx, int left, int right, int x, int value)
{
    if(left == right)
        ST[left] = value;
    else
    {
        int mid = (left + right) / 2;
        if(x < mid)
            update_util(idx * 2, left, mid, x, value);
        else update_util(idx * 2 + 1, mid + 1, right, x, value);

        ST[idx] = ST[idx * 2] + ST[idx * 2 + 1];
    }
}
