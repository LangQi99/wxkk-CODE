#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct UnionFind
{
    int parent[6];

    UnionFind()
    {
        for (int i = 0; i < 6; i++)
            parent[i] = i;
    }

    int find_set(int x)
    {
        return parent[x] == x ? x : parent[x] = find_set(parent[x]);
    }

    void union_set(int x, int y)
    {
        int fx = find_set(x);
        int fy = find_set(y);
        if (fx != fy)
        {
            parent[fx] = fy;
        }
    }
};

void solve()
{
    string S, T;
    cin >> S >> T;
    int n = S.size();
    int m = T.size();
    vector<int> s_int(n);
    vector<int> t_int(m);
    for (int i = 0; i < n; i++)
        s_int[i] = S[i] - 'a';
    for (int i = 0; i < m; i++)
        t_int[i] = T[i] - 'a';
    int total_windows = n - m + 1;
    vector<int> result;
    result.reserve(total_windows);

    for (int i = 0; i <= n - m; i++)
    {
        UnionFind uf;
        for (int j = 0; j < m; j++)
        {
            int a = s_int[i + j];
            int b = t_int[j];
            uf.union_set(a, b);
        }
        int unique_chars = 0;
        bool present[6] = {false};
        for (int j = 0; j < m; j++)
        {
            present[s_int[i + j]] = true;
            present[t_int[j]] = true;
        }
        for (int j = 0; j < 6; j++)
            if (present[j])
                unique_chars++;
        unordered_set<int> classes;
        for (int j = 0; j < 6; j++)
            if (present[j])
            {
                classes.insert(uf.find_set(j));
            }
        int num_classes = classes.size();
        int ops = unique_chars - num_classes;
        result.push_back(ops);
    }
    for (auto x : result)
    {
        cout << x << " ";
    }
}
int main()
{
    solve();
    return 0;
}
