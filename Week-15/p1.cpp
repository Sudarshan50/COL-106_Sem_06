#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<ll>
#define vvi vector<vector<ll>>

void solve()
{
    ll n,m;
    cin >> n >> m;
    vvi adj(m, vi(2));
    vector<bool> visited(n, false);
    for (ll i = 0; i < m; i++)
    {
        cin >> adj[i][0] >> adj[i][1];
    }
    bool ans = false;
    vector<int> color(n, -1);
    function<bool(int, int)> dfs = [&](int node, int col) {
        color[node] = col;
        for (ll i = 0; i < m; i++) {
            if (adj[i][0] == node || adj[i][1] == node) {
                ll neighbor = (adj[i][0] == node) ? adj[i][1] : adj[i][0];
                if (color[neighbor] == -1) {
                    if (!dfs(neighbor, 1 - col))
                        return false;
                } else if (color[neighbor] == col) {
                    return false;
                }
            }
        }
        return true;
    };

    for (ll i = 0; i < n; i++) {
        if (color[i] == -1) {
            if (!dfs(i, 0)) {
                ans = false;
                break;
            }
        }
    }
    ans = true;
    cout << (ans ? "YES" : "NO") << endl;
};

signed main()
{
    solve();
}