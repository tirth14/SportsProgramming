#include <bits/stdc++.h>
using namespace std;

bool myComp(const pair<int,int> &p1,const pair<int,int> &p2)
{
    if(p1.first<p2.first)
        return true;
    else if(p1.first>p2.first)
        return false;
    
    return p1.second<p2.second;
}

int main()
{
   int n;
   cin>>n;
   vector<pair<int,int> > A(n);
    
   for(int i=0;i<n;i++)
   {
       cin>>A[i].first>>A[i].second;
   }

   sort(A.begin(),A.end(),myComp);
    
   int res=0;
    
   for(int i=0;i<n;i++)
   { 
     if(A[i].second>=res) 
         res=A[i].second;
     else { res=A[i].first; }
   }
   cout<<res<<endl;   
}


