#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<ll>
#define vvi vector<vector<ll>>

void problem3()
{
    ll n, m;
    cin >> n >> m;
    vvi adj(n);
    vector<int> inDegree(n, 0);

    for (ll i = 0; i < m; i++)
    {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        inDegree[v]++;
    }

    queue<ll> q;
    for (ll i = 0; i < n; i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }

    ll visitedCount = 0;
    while (!q.empty())
    {
        ll node = q.front();
        q.pop();
        visitedCount++;

        for (auto &neigh : adj[node])
        {
            inDegree[neigh]--;
            if (inDegree[neigh] == 0)
            {
                q.push(neigh);
            }
        }
    }

    cout << (visitedCount == n ? "NO CYCLE" : "CYCLE") << endl;
}

signed main()
{
    problem3();
}