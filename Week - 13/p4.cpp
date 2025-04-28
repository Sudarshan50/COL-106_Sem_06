#include<bits/stdc++.h>
using namespace std;


void solve()
{
    int n ;cin>>n;
    vector<int> a(n);
    for(auto &it:a)
    {
        cin>>it;
    }
    if(is_sorted(a.begin(), a.end()))
    {
        for(auto it:a)
        {
            cout<<it<<" ";
        }
        cout<<endl;
        return;
    }
    int zeroPtr = 0;
    for(int i = 0; i < n; i++)
    {
        if(a[i] == 0)
        {
            swap(a[i], a[zeroPtr]);
            zeroPtr++;
        }
    }
    int twoPtr = zeroPtr;
    for(int i = zeroPtr; i < n; i++)
    {
        if(a[i] == 1)
        {
            swap(a[i], a[twoPtr]);
            twoPtr++;
        }
    }
    for(int i = 0; i < n; i++)
    {
        cout<<a[i]<<" ";
    }   
    cout<<endl;
}


signed main()
{
    solve();
}