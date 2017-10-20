#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m>>n;
        
        string s1,s2;
        cin>>s1>>s2;
        
        vector<vector<int> > dp(m+1,vector<int> (n+1));
        
        int res=0;
        
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0 || j==0)
                    dp[i][j]=0;
                else if(s1[i-1]==s2[j-1])
                    dp[i][j]=dp[i-1][j-1]+1;
                else
                    dp[i][j]=0;
                res=max(res,dp[i][j]);
            }
        }
        
        cout<<res<<endl;
    }
}
