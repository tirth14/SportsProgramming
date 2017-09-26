#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define p 1000000007

int main() 
{
    int t,k;
    cin>>t>>k;
    
    int n=100000;
    vector<long long> dp(n+1,0),csum(n+1,0);
    dp[0]=1;
    for(int i=1;i<=n;i++)
    {
        if(i<k){dp[i]=dp[i-1];}                // DP relation ,ith char: if R =>all prevoius(i-1) permuatations
        else{dp[i]=(dp[i-1]+dp[i-k])%p;}       //if W=>i-(k-1) to i-1 should be W, so all previous (i-k) permutaions  
    }
    csum[0]=dp[0];    
    for(int i=1;i<=n;i++)
    {
        csum[i]=(csum[i-1]+dp[i])%p;
    }
    int a,b;long long res;
    for(int i=0;i<t;i++)
    {
        cin>>a>>b;
        res=(2*p+csum[b]-csum[a-1])%p;
        cout<<res<<endl;
    }
        
}
