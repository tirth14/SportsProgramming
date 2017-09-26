#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define p 1000000007

long long Ways(int n,int k)
{
    vector<long long> dp(n+1,0);
    
    dp[0]=1;
    
    for(int i=1;i<=n;i++)
    {   
        for(int j=1;j<=k;j++)
        {
            if(i>=j)
                dp[i]=(dp[i]+dp[i-j])%p;
        }
    }
    
    return dp[n];
}

int main() 
{
    int n,k,d;
    cin>>n>>k>>d;
    
    long long res=Ways(n,k)-Ways(n,d-1);
    
    if(res<0) res+=p;
    
    cout<<res<<endl;
}
