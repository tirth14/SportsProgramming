#include <bits/stdc++.h>
using namespace std;

struct subset
{
  int parent;
  int rank;
};

int Find(int i,vector<subset> &par)
{
    if(par[i].parent!=i)
        return par[i].parent=Find(par[i].parent,par);
    return i;
}

void Union(int x,int y,vector<subset> &par)
{
    int xroot=Find(x,par);
    int yroot=Find(y,par);
    if(par[xroot].rank<par[yroot].rank) par[xroot].parent=yroot;
    else if(par[yroot].rank<par[xroot].rank) par[yroot].parent=xroot;
    else
    {
        par[xroot].parent=yroot; par[yroot].rank++;
    }
}

struct edge
{
    int src;
    int dest;
    int w;
};

struct myComp
{
    bool operator()(const edge &e1,const edge &e2)
    {
        if(e1.w>e2.w) return true;
   else if(e2.w<e1.w) return false;
        return e1.src+e1.dest>e1.src+e1.dest;
    }
};

int main() 
{
    int V,E;
    cin>>V>>E;
    vector<edge> A(E); 

    for(int i=0;i<E;i++) cin>>A[i].src>>A[i].dest>>A[i].w;
    
    vector<subset> par(V+1);
    for(int i=1;i<=V;i++) {par[i].parent=i;par[i].rank=0;}
    
    //custom declaration of priority queue 
    priority_queue<edge,vector<edge>,myComp> pq;
    
    for(int i=0;i<E;i++) pq.push(A[i]);
    
    int count=0;int res=0;
    while(count!=V-1)
    {
        edge e=pq.top();
        pq.pop();
        int x=Find(e.src,par);
        int y=Find(e.dest,par);
        if(x!=y)
        {
            res+=e.w; 
            count++; 
            Union(x,y,par);
        }
    }
    
    cout<<res<<endl;
}
