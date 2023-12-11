#include <bits/stdc++.h>
using namespace std;

class segTree
{
public:
    vector<int> tree;
    segTree()
    {
    }
    segTree(vector<int> arr, int n)
    {
        tree = vector<int>(n * 4 + 100, 0);
        build_tree(1, 1, n, arr);
    }

    void make(vector<int> arr, int n)
    {
        tree = vector<int>(n * 4 + 100, 0);
        build_tree(1, 1, n, arr);
    }

    int operation(int x, int y)
    {
        return x + y;
    }

    int query(int si, int ss, int se, int qa, int qb)
    {
        assert(qa <= qb);

        if (ss > qb || se < qa)
            return 0; //check the base case

        if (ss >= qa && se <= qb)
            return tree[si];

        int mid = (ss + se) / 2;
        int left = query(2 * si, ss, mid, qa, qb);
        int right = query(2 * si + 1, mid + 1, se, qa, qb);

        return operation(left, right);
    }
    void update(int si, int ss, int se, int pos, int val)
    {
        if (ss == se)
        {
            tree[si] = val;
            return;
        }

        int mid = (ss + se) / 2;

        if (pos <= mid)
            update(2 * si, ss, mid, pos, val);
        else
            update(2 * si + 1, mid + 1, se, pos, val);

        tree[si] = operation(tree[2 * si], tree[2 * si + 1]);
    }

    void build_tree(int si, int ss, int se, vector<int> &arr)
    {
        if (ss == se)
        {
            tree[si] = arr[ss];
            return;
        }
        int mid = (ss + se) / 2;
        build_tree(2 * si, ss, mid, arr);
        build_tree(2 * si + 1, mid + 1, se, arr);

        tree[si] = operation(tree[2 * si], tree[2 * si + 1]);
    }
};