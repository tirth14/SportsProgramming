#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define p 1000000007

//parallel updation of dp

int main() 
{
    
    int n,k;
    cin>>n>>k;
    
    vector<vector<long long> > dp(n+1,vector<long long>(k+1));
    
    //dp[i][l] : sequence of length 'l' ending with i 
    
    for(int i=1;i<=n;i++) dp[i][1]=1;
    
    for(int l=2;l<=k;l++)
    {
       for(int i=1;i<=n;i++)
       {
           for(int x=i;x<=n;x=x+i)
           {
               dp[x][l]+=dp[i][l-1];  // i is divisor of x
               dp[x][l]%=p;
           }
       } 
    }
    
    long long res=0;
    for(int i=1;i<=n;i++) {res+=dp[i][k]; res%=p;}
    cout<<res<<endl;
    
}
