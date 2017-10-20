#include <bits/stdc++.h>
using namespace std;

//cities are indexed from 0 to n-1.
//start from 0 and again come back to 0.

int TSP(int n, vector<vector<int> > cost)
{
    if(n==1) return 0;
 
    //dp[i][mask] : path starting from 0 and ending at i.
 
    vector<vector<int> > dp(n,vector<int>((1<<n),INT_MAX));
    
    dp[0][1]=0;
    
    //mask+=2, since every subset must contain 1
    
    for(int mask=3;mask<(1<<n);mask+=2)
    {
        for(int i=0;i<n;i++)
        {
            bool is_subset_size2=true;
            
            //checking if (mask-1) is power of 2.
            
            if((mask-1)&(mask-2))
                is_subset_size2=false;
                
            if(mask&(1<<i))
            {   
                if(is_subset_size2)
                    {
                        dp[i][mask]=cost[0][i];
                        continue;
                    }
                    
                for(int j=0;j<n;j++)
                {
                    if(mask&(1<<j) && j!=i && j!=0)
                    {
                       dp[i][mask]=min(dp[i][mask],dp[j][mask^(1<<i)]+cost[j][i]);  //mask^(1<<i) : unsetting ith bit 
                    }
                }
            }
        }
    }
    
    int res=INT_MAX;
    
    for(int i=1;i<n;i++)
    {
        res=min(res, dp[i][(1<<n)-1] + cost[i][0]);
    }
    
    return res;

}

int main() 
{
    int t;
    cin>>t;
    
    while(t--)
    {
    int n;
    cin>>n;
    
    vector<vector<int> > cost(n,vector<int>(n));
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cin>>cost[i][j];
    }
    
    cout<<TSP(n,cost)<<endl;
    
    }
}
