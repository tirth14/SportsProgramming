#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int DFS(int u,vector<bool> &visited,vector<vector<int> > &adjlist,int &res)
{
    visited[u]=true;
    int nodes=0;
    for(int v=0;v<adjlist[u].size();v++)
    {
        if(!visited[adjlist[u][v]])
        {
            int s_nodes=DFS(adjlist[u][v],visited,adjlist,res);
            res+=s_nodes%2==0?1:0;  // if subtree has even numbver of nodes, then detach it.
            nodes+=s_nodes;
        }
    }
    return nodes+1;
}

int main() 
{
    int V,E;
    cin>>V>>E;
    vector<vector<int> > adjlist(V+1);
    for(int i=0;i<E;i++)
    {
        int a,b;
        cin>>a>>b;
        adjlist[a].push_back(b);
        adjlist[b].push_back(a);
    }
    vector<bool> visited(V+1,false);
    
    int res=0;
    int total_nodes=DFS(1,visited,adjlist,res);
    cout<<res<<endl;    
}
