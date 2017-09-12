#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,W;
        cin>>n>>W;
        vector<int> val(n),wt(n);
        for(int i=0;i<n;i++)
        {
            cin>>val[i];
        }
        for(int i=0;i<n;i++)
        {
            cin>>wt[i];
        }
        
        vector<int> dp(W+1,0);
        dp[0]=0;
        
        for(int i=1;i<=W;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i>=wt[j])
                {
                    dp[i]=max(dp[i],val[j]+dp[i-wt[j]]);
                }
            }
        }
        
        cout<<dp[W]<<endl;
    }
}
