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
    stack<int> st1;
    queue<int> q2;
    vector<int> ans(n,-1);
    for(int i=0;i<n;i++)
    {
        int curr = a[i];
        while(!q2.empty() && a[q2.front()]<a[i])
        {
            ans[q2.front()]=curr;
            q2.pop();
        }
        if(!st1.empty() && curr > a[st1.top()])
        {
            while(!st1.empty() && a[st1.top()]<curr)
            {
                q2.push(st1.top());
                st1.pop();
            }
        }
        st1.push(i);
    }    
    for(auto it:ans)
    {
        cout<<it<<" ";
    }   
    cout<<endl;


}