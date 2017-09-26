#include <bits/stdc++.h>
using namespace std;

int main()
{
   int n,p;
   cin>>n>>p;
   string s;
   cin>>s;
    
   if(p>n/2) p=n-p+1;  
    
   int res=0;
    
   int l=1;int r=n%2==0?n/2:n/2+1;
   
   while(l<p && s[l-1]==s[n-1-(l-1)]) l++;
   while(r>p && s[r-1]==s[n-1-(r-1)]) r--;
   
   res+=min(p-l,r-p)+r-l;  //pointer movement
   
   for(int i=l;i<=r;i++)   //character conversion
   {
       int diff=abs(s[i-1]-s[n-1-(i-1)]);
       res+=min(diff,26-diff);
   }    
   
   cout<<res<<endl; 
}
