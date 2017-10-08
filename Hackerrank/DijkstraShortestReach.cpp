#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int minDist(vector<int> &dist,vector<bool> &v)
{
    int min_idx=-1;int min_d=INT_MAX;
    int size=dist.size();
    for(int i=1;i<=size-1;i++)
    {
        if(!v[i] && dist[i]!=INT_MAX && min_d>dist[i])
        {
            min_d=dist[i]; min_idx=i;
        }
    }
    return min_idx;
}

int main(){
    int t;
    cin >> t;
    while(t--)
    {
    int V,E;
    cin>>V>>E;
    vector<vector<int> > g(V+1,vector<int>(V+1,INT_MAX));
        for(int i=0;i<E;i++)
        {
            int s,d,w;
            cin>>s>>d>>w;
            g[s][d]=min(w,g[s][d]);
            g[d][s]=min(w,g[d][s]);
        }
        int source;
        cin>>source;
        
        vector<int> dist(V+1,INT_MAX);
        vector<bool> v(1+V,false);
        dist[source]=0;
        
        int mvd=minDist(dist,v);  //mvd : minimum distance vertex
        
        while(mvd!=-1)
        {
            v[mvd]=true;
            for(int i=1;i<=V;i++)
            {
                if(!v[i] && g[mvd][i]!=INT_MAX && dist[mvd]+g[mvd][i]<dist[i])
                {
                    dist[i]=dist[mvd]+g[mvd][i];
                }
            }
            mvd=minDist(dist,v);
        }
        
        for(int i=1;i<=V;i++)
        { 
                if(dist[i]==INT_MAX) 
                    dist[i]=-1; 
                cout<<dist[i]<<" ";
        }
        cout<<endl;
    }
    
}
