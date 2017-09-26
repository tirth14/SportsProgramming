#include <bits/stdc++.h>
using namespace std;

int main()
{
   string s;
   cin>>s;
   int n=s.length();
    
   string pre="",res="";
   
   for(int i=0;i<n;i++)      //remove more than 2 occurenences
   {
       pre+=s[i];
       if(i<n-1 && pre[pre.length()-1]==s[i+1]) 
       { 
           pre+=s[i+1]; i++;
           while(i<n-1 && s[i]==s[i+1]) i++;
       }
   }
   n=pre.length();
   int x=0,i=0;
   while(i<n)              //remove consecutive pairs                   
   { 
       if(i<n-1 && pre[i]!=pre[i+1] || i==n-1) {res+=pre[i];i++;}
       else
       {
           while(i<n-1 && pre[i]==pre[i+1])
           {
               if(x==0) {res+=pre[i];res+=pre[i+1];}
               else{res+=pre[i];}
               i=i+2; x=1-x; 
           }
           x=0;
       } 
   }
    
    cout<<res<<endl;
}
