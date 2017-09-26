#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() 
{
   int n;
   cin>>n;
   vector<vector<int> > A(n,vector<int> (n));
   vector<long long> d(2*n-1,0),ad(2*n-1,0);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&A[i][j]);    //Do not use cin>> while taking large no. of inputs because 
            d[i+j]+=A[i][j];         //it slows down the program and may lead to TLE.
            ad[i-j+n-1]+=A[i][j];    //Use scanf/printf which is much faster than cin>>. 
        }
    }   
    
        //Cases :i+j even or odd
      
        vector<pair<int,int> > v(2);
        vector<long long> p(2,0);    
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                long long cost=d[i+j]+ad[i-j+n-1]-A[i][j];
                int k=(i+j)&1;
                if(cost>=p[k]){p[k]=cost;v[k].first=i+1;v[k].second=j+1;}
            }
        }
        cout<<(p[0]+p[1])<<endl;
        cout<<v[0].first<<" "<<v[0].second<<" "<<v[1].first<<" "<<v[1].second<<endl;
    
}
