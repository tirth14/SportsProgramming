#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <vector> 
#include <list>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <functional>
#include <numeric>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <fstream>
#include <ctime>
#include <cassert>

using namespace std;
 
struct node
{
  int val;
  int rank;
};

//Find using path compression and Union by rank

int Find(int i,vector<node> &par)
{
    if(par[i].val!=i)
        par[i].val=Find(par[i].val,par);
    return par[i].val;
}

void Union(int x,int y,vector<node> &par)
{
    int xp=Find(x,par);
    int yp=Find(y,par);
    
      if(par[xp].rank<par[yp].rank) par[xp].val=yp;
 else if(par[yp].rank<par[xp].rank) par[yp].val=xp;
    else{ par[xp].val=yp; par[yp].rank++; }
}

int main()
{ 
    int N, I;
    cin >> N >> I;
  
    vector<node> par(N);
    for(int i=0;i<N;i++) { par[i].val=i; par[i].rank=0; }
    
    for (int i = 0; i < I; ++i)
    {
        int a, b;
        cin >> a >> b;    
        int x=Find(a,par);
        int y=Find(b,par);
        if(x!=y) 
            Union(x,y,par);
    }
    
    for(int i=0;i<N;i++) {int p=Find(i,par);}
    
    long long sqr_sum=0; 
    vector<long long> A(N,0);
    for(int i=0;i<N;i++) { A[par[i].val]++; }
    for(int i=0;i<N;i++) { sqr_sum+=A[i]*A[i]; }
    
    long long result = ((long long)((long long)N*(long long)N)-sqr_sum)/2;
   
   //for(int  i=0;i<N;i++) cout<<par[i].val<<" "; 
    
    cout << result << endl;
}
