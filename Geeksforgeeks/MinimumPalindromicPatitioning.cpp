#include <bits/stdc++.h>
using namespace std;

int MinCuts(string s)
{
    int n=s.length();
    
    vector<vector<bool> > p(n,vector<bool>(n));
    
    for(int i=0;i<n;i++) p[i][i]=true;
    for(int i=0;i<n-1;i++) p[i][i+1]=s[i]==s[i+1];
    
    for(int l=3;l<=n;l++)
    {
        for(int i=0;i<=n-l;i++)
        {
            int j=i+l-1;
            
            if(s[i]==s[j] && p[i+1][j-1]) 
                p[i][j]=true;
            else
                p[i][j]=false;
        }
    }
    
    //dp[i] : minimum cuts required for partitioning s[0...i]
    vector<int> dp(n,INT_MAX);
    dp[0]=0;
    for(int i=1;i<n;i++)
    {
        if(p[0][i]) {dp[i]=0;continue;}
        
        for(int j=0;j<i;j++)
        {
            if(p[j+1][i] && 1+dp[j]<dp[i])
                dp[i]=1+dp[j];
        }
    }
    
    return dp[n-1];
}

int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        int res=MinCuts(s);
        
        cout<<res<<endl;
    }
}
