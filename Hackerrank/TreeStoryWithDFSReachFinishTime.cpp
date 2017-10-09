#include <bits/stdc++.h>

using namespace std;

void DFS(vector<vector<int> > &adjlist, vector<int> &par,vector<int> &reach,vector<int> &finish,int &time, int u, int parent)
{
    time++; //increment time step
    reach[u]=time;
    par[u]=parent;
    for(int i=0;i<adjlist[u].size();i++)
    {
        if(adjlist[u][i]!=parent)
            DFS(adjlist,par,reach,finish,time,adjlist[u][i],u);
    }
    finish[u]=time;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
      int V; cin>>V;
      vector<vector<int> > adjlist(V+1);
        for(int i=0;i<V-1;i++)
        {
            int s,d;
            cin>>s>>d;
            adjlist[s].push_back(d); adjlist[d].push_back(s);
        }
        int g,k;
        cin>>g>>k;
        
        vector<int> par(V+1),reach(V+1),finish(V+1);
        int time=0;
        int root=1; // tree with root node 1
        DFS(adjlist,par,reach,finish,time,root,-1);      // assigns parent to evry node
        
        vector<int> csum(V+2,0);
        for(int i=0;i<g;i++)
        {
            //once again delta pulse train concept (very powerful), draw a tree to understand
            int u,v; cin>>u>>v;
            if(par[v]==u)
            {
                csum[reach[root]]++;
                csum[finish[root]+1]--;
                
                csum[reach[v]]--;
                csum[finish[v]+1]++;
            }
            else
            {
                csum[reach[u]]++;
                csum[finish[u]+1]--;
            }
        }
        
        //summing over pulse train
        int fav_outcome=0;
        for(int i=1;i<=V;i++)
        {
            csum[i]+=csum[i-1];
            if(csum[i]>=k) fav_outcome++;
        }
        
        int p=fav_outcome; int q=V;
        
        // reduced fraction
        if(p==0) {p=0;q=1;}
        else
        {
            for(int i=p;i>=2;i--) if(p%i==0 && q%i==0) {p=p/i;q=q/i;}
        }
       cout<<p<<"/"<<q<<endl;
        
       //for(int i=1;i<=V;i++) cout<<csum[i]<<" ";cout<<endl;
       }
}
