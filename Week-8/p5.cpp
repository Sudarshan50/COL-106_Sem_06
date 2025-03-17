#include<bits/stdc++.h> 
using namespace std;


signed main()
{
    int n;cin>>n;
    vector<int> a(n);
    for(auto &it:a)
    {
        cin>>it;
    }
    int ans = 0;
    map<int,map<int,int>> mp;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            int diff = a[i]-a[j];
            mp[i][diff] = mp[j][diff]+1;
            ans = max(ans,mp[i][diff]);
        }
    }
    cout<<ans+1<<endl;

}