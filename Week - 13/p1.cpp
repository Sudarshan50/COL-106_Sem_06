#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n); 
    for (auto &it : a) cin >> it;
    sort(a.begin(), a.end());
    for (int i = 0; i < n - 1; i += 2)
    {
        swap(a[i], a[i + 1]);
    }

    for (auto it : a) cout << it << " ";
}

signed main()
{
    solve();
}