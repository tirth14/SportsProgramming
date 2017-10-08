#include <bits/stdc++.h>
using namespace std;

int DFS(int u,vector<bool> &visited,vector<vector<int> > &adjlist)
{
    visited[u]=true;
    int count=1;
    for(int v=0;v<adjlist[u].size();v++)
    {
        if(!visited[adjlist[u][v]])
            count+=DFS(adjlist[u][v],visited,adjlist);
    }
    return count;
}

int main() {
    int q;
    cin >> q;
    for(int i = 0; i < q; i++)
    {
        int n;
        int m;
        long clib;
        long croad;
        cin >> n >> m >> clib >> croad;
        vector<vector<int> > adjlist(n+1);
        for(int i = 0; i< m; i++)
        {   
            int src,dest;
            cin >> src >> dest;
            adjlist[src].push_back(dest);
            adjlist[dest].push_back(src);
        }
        
        vector<bool> visited(n+1,false);
        
        long long res=0;
        if(clib<=croad) res=n*clib;
        else
        {
            for(int i=1;i<=n;i++)
            {
                if(!visited[i]){ res+=(long long)(((long long)DFS(i,visited,adjlist)-1)*(long long)croad)+(long long)clib; }
            }
        }
        
        cout<<res<<endl;
    }
    return 0;
}
