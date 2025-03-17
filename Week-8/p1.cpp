#include<bits/stdc++.h>
using namespace std;


signed main()
{
    int n;cin>>n;
    int sum;cin>>sum;
    vector<int> a(n);
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    map<int,int> mp;
    for(auto &it:a)
    {
        mp[it]++;
    }
    for(auto it:a)
    {
        int curr = sum-it;
        if(mp[curr])
        {
            cnt++;
            mp[it]--;
            mp[curr]--;
        }
    }
    cout<<cnt<<endl;

}