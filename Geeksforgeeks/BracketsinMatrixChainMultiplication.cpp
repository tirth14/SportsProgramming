#include <bits/stdc++.h>
using namespace std;

void PrintParanthesis(char &m, vector<vector<int> > break_p, int i,int j)
{
    if(i==j)
    {
        cout<<m;
        m++;
        return;
    }
    
    cout<<"(";
    PrintParanthesis(m,break_p,i,break_p[i][j]);
    PrintParanthesis(m,break_p,break_p[i][j]+1,j);
    cout<<")";
}

int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        n=n-1;
        vector<int> A(n+1);
        for(int i=0;i<=n;i++)
            cin>>A[i];
        
        string res="";
        
        vector<vector<int> > dp(n+1,vector<int>(n+1,INT_MAX));
        
        //stores breakpoint of i to j i.e optimal k here.
        vector<vector<int> > break_p(n+1,vector<int>(n+1,INT_MAX));
        
        for(int i=1;i<=n;i++) dp[i][i]=0;
        
        for(int l=2;l<=n;l++)
        {
            for(int i=1;i<=n-l+1;i++)
            {
                int j=i+l-1;
                for(int k=i;k<j;k++)
                {
                    int cost=dp[i][k]+dp[k+1][j]+A[i-1]*A[k]*A[j];
                    if(cost<dp[i][j])
                    {
                        dp[i][j]=cost;
                        break_p[i][j]=k;
                    }
                }
            }
        }
        
        char m='A';
        PrintParanthesis(m,break_p,1,n);
        cout<<endl;
    } 
}
