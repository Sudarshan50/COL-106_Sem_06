#include <bits/stdc++.h>
using namespace std;

int mergSort(vector<int> &a, int l, int r)
{
    if (l >= r)
        return 0;
    int mid = (l + r) / 2;
    int inv = mergSort(a, l, mid) + mergSort(a, mid + 1, r);
    vector<int> temp(r - l + 1);
    int i = l, j = mid + 1, k = 0;
    while (i <= mid && j <= r)
    {
        if (a[i] <= a[j])
        {
            temp[k++] = a[i++];
        }
        else
        {
            inv += (mid - i + 1);
            temp[k++] = a[j++];
        }
    }
    while (i <= mid)
        temp[k++] = a[i++];
    while (j <= r)
        temp[k++] = a[j++];
    for (int i = l; i <= r; i++)
        a[i] = temp[i - l];
    return inv;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &it : a)
        cin >> it;
    cout << mergSort(a, 0, n - 1)<<endl;
}

signed main()
{
    solve();
}