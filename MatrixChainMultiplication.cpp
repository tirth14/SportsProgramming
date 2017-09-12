#include <bits/stdc++.h>
using namespace std;

int main() 
{
  int t;
  cin>>t;
  while(t--)
  {
      int n;
      cin>>n;
      n=n-1;
      vector<int> D(n+1);
      for(int i=0;i<n+1;i++)
      {
          cin>>D[i];
      }
      
      vector<vector<int>> dp(n+1,vector<int>(n+1,INT_MAX));
      
      for(int i=1;i<=n;i++) dp[i][i]=0;
      
      for(int l=2;l<=n;l++)
      {
          for(int i=1;i<=n-l+1;i++)
          {
              int j=i+l-1;
              for(int k=i;k<j;k++)
              {
                  dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j]+D[i-1]*D[k]*D[j]);
              }
          }
      }
      
      cout<<dp[1][n]<<endl;
  }
}
