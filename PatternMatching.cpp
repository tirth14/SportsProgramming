bool PatternMatching(string A,string P)
{
   int m=A.length();
   int n=P.length();
   vector<vector<bool>> dp(m+1,vector<bool>(n+1,false));
   
   dp[0][0]=true;
   for(int i=1;i<=m;i++) dp[i][0]=false;
   for(int j=1;j<=n;j++) dp[0][j]=P[j-1]=='*'&&dp[0][j-1]; //if only *'s in pattern
   
   for(int i=1;i<=m;i++)
   {
       for(int j=1;j<=n;j++)
       {
           if(P[j-1]=='?' || (P[j-1]==A[i-1]) )
           { 
              dp[i][j]=dp[i-1][j-1];
           }
          else if(P[j-1]=='*')
          {
              dp[i][j]=dp[i-1][j]||dp[i][j-1]; //Case1:'*' engulfs/matches ith character Case2:skip '*'
          }
          else
          {
              dp[i][j]=false;   
          }
       }
   }
   
   return dp[m][n];
}
