#include<bits/stdc++.h>
using namespace std;    

signed main()
{
    int t;cin>>t;
    while(t--)
    {
    string sh;cin>>sh;
    map<char,int> mp; 
    int ans = 0;
    int cnt = 0;
    for(auto it:sh)
    {
        if(mp[it] > 0)
        {
            mp.clear();
            ans = max(ans,cnt);
            cnt = 0;
        }
        cnt++;
        mp[it]++;
    }
    ans = max(ans,cnt);
    cout<<ans<<endl;
}
}