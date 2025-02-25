#include<bits/stdc++.h>
using namespace std;



signed main()
{
    int n,k;cin>>n>>k;
    vector<int> a(n);
    priority_queue<int, vector<int>, greater<int> >pq;
    int ans = 0;
    for(auto &it:a)
    {
        cin>>it;
        pq.push(it);
    }
    while(!pq.empty())
    {
        if(pq.top()>=k)
        {
            cout<<ans<<endl;
            return 0;
        }
        int top1 = pq.top();
        pq.pop();
        int top2 = pq.top();
        pq.pop();

        int op = (top1+2*top2);
        pq.push(op);
        ans++;
    }
    cout<<-1<<endl; 
}