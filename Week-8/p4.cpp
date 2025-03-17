#include<bits/stdc++.h> 
using namespace std;


signed main()
{
    string a;cin>>a;
    int n = a.size();
    map<char,int> mp;
    int ans = 0;
    for(int lft = 0,rgt = 0;rgt<n;rgt++)
    {
        mp[a[rgt]]++;
        while(mp[a[rgt]] > 1)
        {
            mp[a[lft]]--;
            lft++;
        }
        ans = max(ans,rgt-lft+1);
    }
    cout<<ans<<endl;

}