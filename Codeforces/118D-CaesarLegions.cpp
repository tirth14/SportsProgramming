#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define p 100000000
#define ll long long

int main() 
{
   int n1,n2,k1,k2;
   cin>>n1>>n2>>k1>>k2;
    
    //Idea: 
    //dp1->last is horseman, dp2->last is footman
    //append k=(1 to min(k1,i)) horseman after dp2[i-k][j] to make dp[i][j](after summing all for k)  
    
   vector<vector<int> > dp1(n1+1,vector<int> (n2+1)), dp2(n1+1,vector<int> (n2+1)); 
    
    dp1[0][0]=1;
    dp2[0][0]=1;
    
   for(int i=0;i<=n1;i++)
   {
       for(int j=0;j<=n2;j++)
       {
           for(int k=1;k<=min(k1,i);k++)
           { dp1[i][j]+=dp2[i-k][j]; dp1[i][j]%=p;}
               
           for(int k=1;k<=min(k2,j);k++)
           { dp2[i][j]+=dp1[i][j-k]; dp2[i][j]%=p;}
       }
   }
    
    cout<<(dp1[n1][n2]+dp2[n1][n2])%p<<endl;
   
}
