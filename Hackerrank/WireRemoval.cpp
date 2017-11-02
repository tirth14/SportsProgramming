#include <bits/stdc++.h>
using namespace std;

int DFS(int u,vector<vector<int> > &adj,vector<bool> &v, int dist , vector<int> &wd, vector<int> &wn)
{
    v[u]=true;
    int nodes=1;
    wd[u]=dist;
    for(int i=0;i<adj[u].size();i++)
    {
        if(!v[adj[u][i]])
        {
            nodes+=DFS(adj[u][i], adj , v, dist+1, wd, wn);
        }
    }
    
    return wn[u]=nodes;
}

int main() 
{
    int n;
    cin>>n;
    vector<vector<int> > adj(n+1);
    
    for(int i=0;i<n-1;i++)
    {
        int s,d;
        cin>>s>>d;
        adj[s].push_back(d);
        adj[d].push_back(s);
    }
    
    vector<bool> v(n+1,false);
    vector<int> wd(n+1);
    vector<int> wn(n+1);
    
    int x=DFS(1,adj, v,0,wd,wn);
    
    double wdsum=0;
    for(int i=2;i<=n;i++)
    {
        wdsum+=(double)wd[i];
    }
    
    double favout=0;
    for(int i=2;i<=n;i++)
    {
        favout+=(double)((double)wd[i]*(n-wn[i]));
    }
    
    double res=favout/wdsum;
    
    //2->2.0000000000
    cout<<setprecision(10)<<res<<endl;
}
