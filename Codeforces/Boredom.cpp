#include <bits/stdc++.h>
using namespace std;

bool myComp(const pair<int,int> &p1, const pair<int,int> &p2)
{
    return p1.first<p2.first;
}

long long MaxPoints(vector<pair<int,int> > A,int n)
{
    vector<long long> dp(n+1);
    dp[0]=0;
    dp[1]=(long long) A[0].first*A[0].second;  //typecast is must
 
    for(int i=2;i<=n;i++)
    {
        dp[i]=max(dp[i-1],dp[i-2]+(long long)A[i-1].first*A[i-1].second);
    }
    
    return dp[n];
}

int main()
{
   int n;
   cin>>n;
   vector<int> A(n);
   
   for(int i=0;i<n;i++) cin>>A[i];
    //for(int i=0;i<n;i++){A[i]=n;}
   
    map<int,int> m;
   for(int i=0;i<n;i++)
   {
       if(m.find(A[i])==m.end()) m[A[i]]=1;
       else { m[A[i]]++;}
   }
   vector<pair<int,int> > B;
   for(map<int,int>::iterator i=m.begin();i!=m.end();i++)
   {
       B.push_back(make_pair(i->first,i->second));
   }
    
   sort(B.begin(),B.end(),myComp); 
    
   n=B.size();
   
   long long res=0,partial_res;
   int s=0,l=1;
   while(s<n)
   {
       while(s<n-1 && B[s].first+1==B[s+1].first) {s++;l++;}
       vector<pair<int,int> > V(B.begin()+s-(l-1),B.begin()+s+1);
       partial_res=MaxPoints(V,l);
       res+=partial_res;
       l=1;s++;
   }
    
   cout<<res<<endl; 
}


