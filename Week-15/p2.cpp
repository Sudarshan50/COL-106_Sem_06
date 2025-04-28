#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<ll>
#define vvi vector<vector<ll>>


void problem2()
{
    int n; cin >> n;
    vvi adj = {{0, 1}, {0, 2}, {0, 3}, {1, 4}};
    if (adj.size() != n - 1) {
        cout << "NO" << endl;
        return;
    }
    vector<bool> vis(n, false);
    vi col(n, -1);
    function<bool(int, int)> dfs = [&](int u, int c) {
        col[u] = c;
        for (ll i = 0; i < adj.size(); i++) {
            if (adj[i][0] == u || adj[i][1] == u) {
                ll v = (adj[i][0] == u) ? adj[i][1] : adj[i][0];
                if (col[v] == -1) {
                    if (!dfs(v, 1 - c))
                        return false;
                } else if (col[v] == c) {
                    return false;
                }
            }
        }
        return true;
    };
    for (ll i = 0; i < n; i++) {
        if (col[i] == -1) {
            if (!dfs(i, 0)) {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
}


signed main()
{
    problem2();
}