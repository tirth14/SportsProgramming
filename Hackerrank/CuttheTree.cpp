#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int data[1000000];
long long sum=0;

long long dfs(vector<vector<int> > &a, vector<bool> &v,int u,long long &res)
{
    v[u]=true;
    long long subtreesum=0;
    for(int i=0;i<a[u].size();i++)
    {
        if(!v[a[u][i]])
        {
            long long subsum=dfs(a,v,a[u][i],res);
            subtreesum+=subsum;
            res=min(res,abs(sum-2*subsum));
        }
    }
    return subtreesum+data[u];
}

int main() 
{
   int V;
    cin>>V;
    vector<vector<int> > a(V+1);
    
    for(int i=1;i<=V;i++) { cin>>data[i]; sum+=data[i]; }
    for(int i=0;i<V-1;i++)
    {
        int s,d;
        cin>>s>>d;
        a[s].push_back(d);
        a[d].push_back(s);
    }
    
    vector<bool> v(V+1);
    
    long long res=1000000000;
    long long sdata=dfs(a,v,1,res);
    
    cout<<res<<endl;
}
