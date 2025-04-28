#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &it : a)
        cin >> it;

    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        v.push_back({a[i], i});
    }

    sort(v.begin(), v.end());

    vector<bool> visited(n, false);
    int swaps = 0;

    for (int i = 0; i < n; i++)
    {
        if (visited[i] || v[i].second == i)
        {
            continue;
        }

        int cycle_size = 0;
        int j = i;

        while (!visited[j])
        {
            visited[j] = true;
            j = v[j].second;
            cycle_size++;
        }

        if (cycle_size > 1)
        {
            swaps += (cycle_size - 1);
        }
    }

    cout << swaps << endl;
}

signed main()
{
    solve();
}