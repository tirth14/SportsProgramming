#include <bits/stdc++.h>
#define p 1000000007
using namespace std;

int main()
{
  int v,e;
  cin>>v>>e;
  
  vector<vector<int> > g(v+1,vector<int>(v+1,0));  //matrix
  vector<vector<int> > adj(v+1); // adjlist
    
    for(int i=0;i<e;i++)
    {
        int s,d;
        cin>>s>>d;
        g[s][d]=1;
        adj[s].push_back(d);
    }
    
    long long res=0;
    
  for(int a=1;a<=v;a++)
  {
      for(int c=1;c<=v;c++)
      {
          if(a!=c)
          {
              long long r=0;
              for(int i=0;i<adj[a].size();i++)
              {
                int b=adj[a][i];
                if(b!=c && b!=a && g[a][b] && g[b][c]) r++;  
              }
              res+=r*(r-1)/2;
              res%=p;
          }
      }
  }
    
    cout<<res<<endl;
}
